/**
 * @file TaskGenerator.h
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2023 Wason Technology, LLC
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * @par
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <RobotRaconteur/Generator.h>

#include "com__robotraconteur__action.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    /**
     * @brief Base class for asynchronous task generators
     * 
     * Base class for asynchronous task generators. This utility class is used
     * to help implement generators that represent long running operations.
     * 
     * Subclasses should override the following functions:
     * 
     * * StartTask() - Called when the generator is started
     * * FillStatus() - Called to fill the next intermediate status report
     * * CloseRequested() - Called when the generator is closed
     * * AbortRequested() - Called when the generator is aborted
     * 
     * The operation should call SetResult() or SetResultException() when the
     * operation is complete. The generator will then return the result to the
     * caller.
     * 
     * @tparam StatusType The status type for the generator
     */
    template<typename StatusType>
    class AsyncTaskGenerator : public virtual RobotRaconteur::Generator<RR_INTRUSIVE_PTR<StatusType>, void>, public RR_ENABLE_SHARED_FROM_THIS<AsyncTaskGenerator<StatusType>>
    {
    public:
        
        /**
         * @brief Represents an asynchronous task generator.
         *
         * The AsyncTaskGenerator class is used to generate asynchronous tasks in RobotRaconteurCompanion.
         * It takes a RobotRaconteurNode, next_timeout, and watchdog_timeout as parameters.
         * 
         * @param node The RobotRaconteurNode instance.
         * @param next_timeout The timeout to return from the Next() function.
         * @param watchdog_timeout The timeout for the watchdog. -1 to disable.
         */
        AsyncTaskGenerator(RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> node, int32_t next_timeout, int32_t watchdog_timeout)
        {
            this->node = node;
            started = false;
            closed = false;
            aborted = false;
            completed = false;
            task_completed = false;
            if (next_timeout < 0)
            {
                throw RobotRaconteur::InvalidArgumentException("next_timeout must be >= 0");
            }

            if (watchdog_timeout > 0 && watchdog_timeout < next_timeout)
            {
                throw RobotRaconteur::InvalidArgumentException("watchdog_timeout must be >= next_timeout");
            }
            this->next_timeout = next_timeout;
            this->watchdog_timeout = watchdog_timeout;
        }

        RR_OVIRTUAL void AsyncNext(boost::function<void(const RR_INTRUSIVE_PTR<StatusType>&,
                const RobotRaconteur::RobotRaconteurExceptionPtr&)> handler, int32_t timeout = RR_TIMEOUT_INFINITE ) RR_OVERRIDE
        {
            boost::mutex::scoped_lock lock(this_lock);
            if (watchdog_timer)
            {
                try
                {
                    watchdog_timer->Stop();
                }
                catch (std::exception&) {}
                watchdog_timer.reset();
            }
            if (aborted)
            {
                throw RobotRaconteur::OperationAbortedException("Scanning Procedure operation was aborted");
            }
            if ((closed && !started) || completed)
            {
                throw RobotRaconteur::StopIterationException("");
            }

            if (!started)
            {
                StartTask();
                started = true;
                RR_INTRUSIVE_PTR<StatusType> ret(new StatusType());
                ret->action_status = com::robotraconteur::action::ActionStatusCode::running;                
                lock.unlock();
                handler(ret, nullptr);
                return;
            }

            if (next_handler)
            {
                throw RobotRaconteur::InvalidOperationException("Next call already in progress");
            }

            if (task_completed)
            {
                complete_gen(handler);
                return;
            }

            next_handler = handler;

            RR_WEAK_PTR<AsyncTaskGenerator<StatusType> > weak_this = this->shared_from_this();
            next_timer = RobotRaconteur::RobotRaconteurNode::s()->CreateTimer(boost::posix_time::milliseconds(next_timeout), 
                boost::bind(&AsyncTaskGenerator::next_timer_handler, weak_this, RR_BOOST_PLACEHOLDERS(_1)), true);
            next_timer->Start();
            if (watchdog_timeout > 0)
            {
                watchdog_timer = RobotRaconteur::RobotRaconteurNode::s()->CreateTimer(boost::posix_time::milliseconds(watchdog_timeout), 
                    boost::bind(&AsyncTaskGenerator::watchdog_timer_handler, weak_this, RR_BOOST_PLACEHOLDERS(_1)), true);
                watchdog_timer->Start();
            }
        }
                

        RR_OVIRTUAL void AsyncClose(boost::function<void(const RobotRaconteur::RobotRaconteurExceptionPtr& err)> handler,
                        int32_t timeout = RR_TIMEOUT_INFINITE) RR_OVERRIDE
        {
            boost::mutex::scoped_lock lock(this_lock);
            if (closed || aborted)
            {
                lock.unlock();
                handler(nullptr);
                return;
            }
            closed = true;
            if (started)
            {
                CloseRequested();
            }
            lock.unlock();
            handler(nullptr);
        }

        RR_OVIRTUAL void AsyncAbort(boost::function<void(const RobotRaconteur::RobotRaconteurExceptionPtr& err)> handler,
                        int32_t timeout = RR_TIMEOUT_INFINITE) RR_OVERRIDE
        {
            boost::mutex::scoped_lock lock(this_lock);
            if (closed || aborted)
            {
                lock.unlock();
                handler(nullptr);
                return;
            }
            aborted = true;
            if (started)
            {
                AbortRequested();
            }
            lock.unlock();
            handler(nullptr);
        }

        RR_OVIRTUAL RR_INTRUSIVE_PTR<StatusType> Next() RR_OVERRIDE 
        {
            // This is never called
            throw RobotRaconteur::NotImplementedException("Not implemented");
        }
        RR_OVIRTUAL void Close() RR_OVERRIDE
        {
            // This is never called
            throw RobotRaconteur::NotImplementedException("Not implemented");
        }
        RR_OVIRTUAL void Abort() RR_OVERRIDE
        {
            // This is never called
            throw RobotRaconteur::NotImplementedException("Not implemented");
        }
    protected:

        /**
         * @brief Set the result of the generator
         * 
         * This method sets the result of the generator. The generator will return
         * the result to the caller.
         * 
         * @param result The result to return
         */
        virtual void SetResult(RR_INTRUSIVE_PTR<StatusType>& result)
        {
            boost::mutex::scoped_lock lock(this_lock);
            if (task_completed) return;
            this->result = result;
            do_result();            
        }

        /**
         * @brief Set the exception result of the generator
         * 
         * This method sets the exception result of the generator. The generator will return
         * the exception to the caller.
         * 
         * @param exp The exception to return
         */
        virtual void SetResultException(RR_SHARED_PTR<RobotRaconteur::RobotRaconteurException>& exp)
        {
            boost::mutex::scoped_lock lock(this_lock);
            if (task_completed) return;
            this->exception_result = exp;
            do_result();            
        }

        void do_result()
        {
            task_completed = true;
            auto h = next_handler;
            next_handler.clear();
            if (h)
            {
                try
                {
                    next_timer->Stop();
                }
                catch (std::exception&) {}

                complete_gen(h);
                return;
            }
        }

        void complete_gen(boost::function<void(const RR_INTRUSIVE_PTR<StatusType>&,
                const RobotRaconteur::RobotRaconteurExceptionPtr&)> handler)
        {
            completed = true;

            if (exception_result)
            {
                auto exp = exception_result;
                exception_result.reset();
                handler(nullptr, exp);
                return;
            }
            RR_INTRUSIVE_PTR<StatusType> ret = result;
            result.reset();
            handler(ret,nullptr);
        }

        /**
         * @brief Start the task
         * 
         * This method is called when the generator is started. Subclasses should
         * override this method to start the task.
         * 
         */
        virtual void StartTask() = 0;

        
        /**
         * @brief This method is called when a close request is received.
         */
        virtual void CloseRequested() {}

        /**
         * @brief This method is called when an abort request is received.
         */
        virtual void AbortRequested() {}

        /**
         * @brief This method is called to fill the next status report
         * 
         * This method is called to fill the next status report. Subclasses should
         * override this method to fill the next status report.
         * 
         * @param status The status report to fill
         */
        virtual void FillStatus(RR_INTRUSIVE_PTR<StatusType>& status) {}

        static void next_timer_handler(RR_WEAK_PTR<AsyncTaskGenerator> weak_this, const RobotRaconteur::TimerEvent& evt)
        {
            RR_SHARED_PTR<AsyncTaskGenerator> shared_this = weak_this.lock();
            if (!shared_this) return;
            boost::mutex::scoped_lock lock(shared_this->this_lock);
            auto h = shared_this->next_handler;
            shared_this->next_handler.clear();
            if (h)
            {
                RR_INTRUSIVE_PTR<StatusType> ret(new StatusType());
                ret->action_status = com::robotraconteur::action::ActionStatusCode::running;
                shared_this->FillStatus(ret);
                h(ret, nullptr);
                return;
            }
        }

        static void watchdog_timer_handler(RR_WEAK_PTR<AsyncTaskGenerator> weak_this, const RobotRaconteur::TimerEvent& evt)
        {
            RR_SHARED_PTR<AsyncTaskGenerator> shared_this = weak_this.lock();
            if (!shared_this) return;
            if (evt.stopped) return;
            boost::mutex::scoped_lock lock(shared_this->this_lock);
            if (shared_this->task_completed) return;
            shared_this->aborted = true;
            shared_this->AbortRequested();
        }

        RR_WEAK_PTR<RobotRaconteur::RobotRaconteurNode> node;
        RR_SHARED_PTR<RobotRaconteur::Timer> next_timer;
        RR_SHARED_PTR<RobotRaconteur::Timer> watchdog_timer;
        bool started;
        bool closed;
        bool aborted;
        bool completed;
        bool task_completed;
        int32_t next_timeout;
        int32_t watchdog_timeout;
        boost::mutex this_lock;
        boost::function<void(const RR_INTRUSIVE_PTR<StatusType>&,
                const RobotRaconteur::RobotRaconteurExceptionPtr&)> next_handler;
        RR_INTRUSIVE_PTR<StatusType> result;
        RR_SHARED_PTR<RobotRaconteurException> exception_result;

    };

    /**
     * @brief A template class for generating synchronous tasks.
     * 
     * This class is derived from the AsyncTaskGenerator class and provides a framework for generating synchronous tasks.
     * It allows the user to define a RunTask() function that performs the actual task and returns a result of type StatusType.
     * The task is executed in a separate thread and the result is set using the SetResult() function.
     * If an exception occurs during task execution, it is caught and converted to a RobotRaconteurException, which is then set as the result exception.
     * 
     * The user should override the RunTask() function to perform the actual task. The StartTask(),
     * SetResult(), and SetResultException() functions should not be called by the user.
     * 
     * @tparam StatusType The type of the task result.
     */
    template <typename StatusType>
    class SyncTaskGenerator : public AsyncTaskGenerator<StatusType>
    {
        public:
        /**
         * @brief Constructor for SyncTaskGenerator.
         * 
         * @param node The RobotRaconteurNode instance.
         * @param next_timeout The timeout to return from the Next() function.
         * @param watchdog_timeout The timeout for the watchdog. -1 to disable.
         */
        SyncTaskGenerator(RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> node, int32_t next_timeout, int32_t watchdog_timeout) 
            : AsyncTaskGenerator<StatusType>(node, next_timeout, watchdog_timeout)
        {
            
        }

        protected:
        /**
         * @brief Pure virtual function to be implemented by the user.
         * 
         * This function should perform the actual task and return a result of type StatusType.
         * 
         * @return RR_INTRUSIVE_PTR<StatusType> The result of the task.
         */
        virtual RR_INTRUSIVE_PTR<StatusType> RunTask() = 0;

       
        void run_task_thread()
        {
            try
            {
                RR_INTRUSIVE_PTR<StatusType> ret = RunTask();
                this->SetResult(ret);
            }
            catch (std::exception& exp)
            {
                RR_SHARED_PTR<RobotRaconteur::RobotRaconteurException> exp1 = RobotRaconteur::RobotRaconteurExceptionUtil::ExceptionToSharedPtr(exp);
                this->SetResultException(exp1);
            }
        }


        RR_OVIRTUAL void StartTask() RR_OVERRIDE
        {
            RR_SHARED_PTR<SyncTaskGenerator> this_ = RR_DYNAMIC_POINTER_CAST<SyncTaskGenerator>(this->shared_from_this());
            boost::thread(boost::bind(&SyncTaskGenerator::run_task_thread, this_));
        }
    };
}
}
}
