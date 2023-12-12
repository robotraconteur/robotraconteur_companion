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

#include <RobotRaconteurCompanion/StdRobDef/group1/com__robotraconteur__action.h>

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    template<typename StatusType>
    class AsyncTaskGenerator : public virtual RobotRaconteur::Generator<RR_INTRUSIVE_PTR<StatusType>, void>, public RR_ENABLE_SHARED_FROM_THIS<AsyncTaskGenerator<StatusType>>
    {
    public:
        AsyncTaskGenerator(RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> node)
        {
            this->node = node;
            started = false;
            closed = false;
            aborted = false;
            completed = false;
            task_completed = false;
        }

        RR_OVIRTUAL void AsyncNext(boost::function<void(const RR_INTRUSIVE_PTR<StatusType>&,
                const RobotRaconteur::RobotRaconteurExceptionPtr&)> handler, int32_t timeout = RR_TIMEOUT_INFINITE ) RR_OVERRIDE
        {
            boost::mutex::scoped_lock lock(this_lock);
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
            next_timer = RobotRaconteur::RobotRaconteurNode::s()->CreateTimer(boost::posix_time::seconds(5), 
                boost::bind(&AsyncTaskGenerator::next_timer_handler, weak_this, RR_BOOST_PLACEHOLDERS(_1)), true);
            next_timer->Start();
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

        virtual void SetResult(RR_INTRUSIVE_PTR<StatusType>& result)
        {
            boost::mutex::scoped_lock lock(this_lock);
            this->result = result;
            do_result();            
        }

        virtual void SetResultException(RR_SHARED_PTR<RobotRaconteur::RobotRaconteurException>& exp)
        {
            boost::mutex::scoped_lock lock(this_lock);
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

        virtual void StartTask() = 0;

        virtual void CloseRequested() {}

        virtual void AbortRequested() {}

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
                h(ret, nullptr);
                return;
            }
        }

        RR_WEAK_PTR<RobotRaconteur::RobotRaconteurNode> node;
        RR_SHARED_PTR<RobotRaconteur::Timer> next_timer;
        bool started;
        bool closed;
        bool aborted;
        bool completed;
        bool task_completed;
        boost::mutex this_lock;
        boost::function<void(const RR_INTRUSIVE_PTR<StatusType>&,
                const RobotRaconteur::RobotRaconteurExceptionPtr&)> next_handler;
        RR_INTRUSIVE_PTR<StatusType> result;
        RR_SHARED_PTR<RobotRaconteurException> exception_result;

    };
}
}
}
