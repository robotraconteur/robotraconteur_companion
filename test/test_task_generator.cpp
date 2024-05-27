#include <RobotRaconteur.h>
#include <RobotRaconteurCompanion/Util/TaskGenerator.h>
#include <RobotRaconteurCompanion/Util/TestFixtures.h>

#include <gtest/gtest.h>

#include "experimental__testing__companion__test_task_generator.h"
#include "experimental__testing__companion__test_task_generator_stubskel.h"

namespace RR = RobotRaconteur;
namespace RRC_Util = RobotRaconteur::Companion::Util;
namespace rr_gentest = experimental::testing::companion::test_task_generator;

class TestTaskGenImpl : public virtual RRC_Util::AsyncTaskGenerator<rr_gentest::TestGenStatus>
{
  public:
    int32_t done_time;
    int32_t fail_time;
    int32_t status_update_time;
    RR_SHARED_PTR<RR::Timer> task_complete_timer;
    RR_SHARED_PTR<RR::Timer> task_failed_timer;
    RR_SHARED_PTR<RR::Timer> status_update_timer;

    TestTaskGenImpl(const RR_SHARED_PTR<RR::RobotRaconteurNode>& node, int32_t done_time, int32_t fail_time,
                    int32_t status_update_time, int32_t next_timeout, int32_t watchdog_timeout)
        : RRC_Util::AsyncTaskGenerator<rr_gentest::TestGenStatus>(node, next_timeout, watchdog_timeout)
    {
        this->done_time = done_time;
        this->fail_time = fail_time;
        this->status_update_time = status_update_time;
    }

    RR_OVIRTUAL void StartTask() RR_OVERRIDE
    {
        RR_SHARED_PTR<RR::RobotRaconteurNode> node = this->node.lock();
        if (!node)
            throw RR::InvalidOperationException("Node has been released");
        RR_SHARED_PTR<TestTaskGenImpl> this_ = RR_DYNAMIC_POINTER_CAST<TestTaskGenImpl>(shared_from_this());
        task_complete_timer = node->CreateTimer(
            boost::posix_time::milliseconds(done_time),
            boost::bind(&TestTaskGenImpl::task_complete_timeout, this_, RR_BOOST_PLACEHOLDERS(_1)), true);
        task_failed_timer = node->CreateTimer(
            boost::posix_time::milliseconds(fail_time),
            boost::bind(&TestTaskGenImpl::task_failed_timeout, this_, RR_BOOST_PLACEHOLDERS(_1)), true);
        status_update_timer = node->CreateTimer(
            boost::posix_time::milliseconds(status_update_time),
            boost::bind(&TestTaskGenImpl::status_update_timeout, this_, RR_BOOST_PLACEHOLDERS(_1)), true);

        task_complete_timer->Start();
        task_failed_timer->Start();
        status_update_timer->Start();
    }

    void task_complete_timeout(const RR::TimerEvent& ev)
    {
        if (ev.stopped)
            return;
        RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status(new rr_gentest::TestGenStatus());
        status->action_status = com::robotraconteur::action::ActionStatusCode::complete;
        status->message = "Task completed";
        status->data = RR::AllocateEmptyRRMap<std::string, RR::RRValue>();
        status->data->insert(std::make_pair("test", RR::ScalarToRRArray<int32_t>(5)));
        SetResult(status);

        task_complete_timer.reset();
        task_failed_timer.reset();
    }

    void task_failed_timeout(const RR::TimerEvent& ev)
    {
        if (ev.stopped)
            return;
        RR_SHARED_PTR<RR::RobotRaconteurException> err = RR_MAKE_SHARED<RR::OperationFailedException>("Task failed");
        SetResultException(err);

        task_complete_timer.reset();
        task_failed_timer.reset();
    }

    void status_update_timeout(const RR::TimerEvent& ev)
    {
        if (ev.stopped)
            return;
        SendUpdate();
    }
};

class SyncTestTaskGenImpl : public RRC_Util::SyncTaskGenerator<rr_gentest::TestGenStatus>
{
  public:
    int32_t done_time;
    int32_t fail_time;
    RR_SHARED_PTR<RR::Timer> task_complete_timer;
    RR_SHARED_PTR<RR::Timer> task_failed_timer;

    SyncTestTaskGenImpl(const RR_SHARED_PTR<RR::RobotRaconteurNode>& node, int32_t done_time, int32_t fail_time,
                        int32_t next_timeout, int32_t watchdog_timeout)
        : RRC_Util::SyncTaskGenerator<rr_gentest::TestGenStatus>(node, next_timeout, watchdog_timeout)
    {
        this->done_time = done_time;
        this->fail_time = fail_time;
    }

    RR_OVIRTUAL RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> RunTask() RR_OVERRIDE
    {
        if (done_time <= fail_time)
        {
            boost::this_thread::sleep(boost::posix_time::milliseconds(done_time));
            RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status(new rr_gentest::TestGenStatus());
            status->message = "Task completed";
            status->data = RR::AllocateEmptyRRMap<std::string, RR::RRValue>();
            status->data->insert(std::make_pair("test", RR::ScalarToRRArray<int32_t>(5)));
            return status;
        }
        else
        {
            boost::this_thread::sleep(boost::posix_time::milliseconds(fail_time));
            throw RR::OperationFailedException("Task failed");
        }
    }
};

class TestGenObjectImpl : public virtual rr_gentest::TestGenObject_default_impl
{
  private:
    RR_SHARED_PTR<RR::RobotRaconteurNode> node;

  public:
    TestGenObjectImpl(const RR_SHARED_PTR<RR::RobotRaconteurNode>& node) { this->node = node; }

    RR_OVIRTUAL RR_SHARED_PTR<RR::Generator<RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus>, void> > test_task_generator(
        int32_t done_time, int32_t fail_time, int32_t status_update_time, int32_t next_timeout,
        int32_t watchdog_timeout) RR_OVERRIDE
    {
        RR_SHARED_PTR<TestTaskGenImpl> gen = RR_MAKE_SHARED<TestTaskGenImpl>(
            node, done_time, fail_time, status_update_time, next_timeout, watchdog_timeout);
        return gen;
    }

    RR_OVIRTUAL RR_SHARED_PTR<RR::Generator<RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus>, void> >
    test_sync_task_generator(int32_t done_time, int32_t fail_time, int32_t next_timeout,
                             int32_t watchdog_timeout) RR_OVERRIDE
    {
        RR_SHARED_PTR<SyncTestTaskGenImpl> gen =
            RR_MAKE_SHARED<SyncTestTaskGenImpl>(node, done_time, fail_time, next_timeout, watchdog_timeout);
        return gen;
    }
};

typedef RR_SHARED_PTR<RR::Generator<RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus>, void> > task_gen_type;

class TaskGenTestFixture
{
  public:
    RRC_Util::IntraTestFixture fixture;
    RR_SHARED_PTR<TestGenObjectImpl> test_gen_obj;
    RR_SHARED_PTR<rr_gentest::TestGenObject> test_gen_obj_client;

    TaskGenTestFixture()
    {
        fixture.RegisterServiceType<com::robotraconteur::action::com__robotraconteur__actionFactory>();
        fixture.RegisterServiceType<rr_gentest::experimental__testing__companion__test_task_generatorFactory>();

        test_gen_obj = RR_MAKE_SHARED<TestGenObjectImpl>(fixture.server_node);

        fixture.RegisterService("test_gen", "experimental.testing.companion.test_task_generator", test_gen_obj);

        test_gen_obj_client = RR::rr_cast<rr_gentest::TestGenObject>(
            fixture.ConnectService("rr+intra:///?nodename=server_node&service=test_gen&servicepath=/test_gen"));
    }

    task_gen_type test_task_generator(int32_t done_time, int32_t fail_time, int32_t status_update_time,
                                      int32_t next_timeout, int32_t watchdog_timeout) const
    {
        return test_gen_obj_client->test_task_generator(done_time, fail_time, status_update_time, next_timeout,
                                                        watchdog_timeout);
    }

    task_gen_type test_sync_task_generator(int32_t done_time, int32_t fail_time, int32_t next_timeout,
                                           int32_t watchdog_timeout) const
    {
        return test_gen_obj_client->test_sync_task_generator(done_time, fail_time, next_timeout, watchdog_timeout);
    }
};

void run_task_gen_test(int32_t done_time, int32_t fail_time, int32_t status_update_time, int32_t next_timeout,
                       int32_t watchdog_timeout, int32_t next_delay)
{
    TaskGenTestFixture fixture;
    task_gen_type gen =
        fixture.test_task_generator(done_time, fail_time, status_update_time, next_timeout, watchdog_timeout);

    RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status;
    bool res = false;
    do
    {

        res = gen->TryNext(status);
        if (res)
        {
            std::cout << "Status: " << status->message << std::endl;
        }
        if (res && next_delay > 0)
        {
            boost::this_thread::sleep(boost::posix_time::milliseconds(next_delay));
        }
    } while (res);
}

void run_task_gen_test_status_update()
{
    TaskGenTestFixture fixture;
    task_gen_type gen = fixture.test_task_generator(200, 2000, 50, 2000, 2100);

    RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status;
    bool res = false;
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    EXPECT_EQ(status->action_status, com::robotraconteur::action::ActionStatusCode::running);
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    EXPECT_EQ(status->action_status, com::robotraconteur::action::ActionStatusCode::complete);
    res = gen->TryNext(status);
    ASSERT_FALSE(res);
}

void run_task_gen_test_status_update2()
{
    TaskGenTestFixture fixture;
    task_gen_type gen = fixture.test_task_generator(200, 2000, 50, 2000, 2100);

    RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status;
    bool res = false;
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    EXPECT_EQ(status->action_status, com::robotraconteur::action::ActionStatusCode::running);
    res = gen->TryNext(status);
    ASSERT_TRUE(res);
    EXPECT_EQ(status->action_status, com::robotraconteur::action::ActionStatusCode::complete);
    res = gen->TryNext(status);
    ASSERT_FALSE(res);
}

void run_sync_task_gen_test(int32_t done_time, int32_t fail_time, int32_t next_timeout, int32_t watchdog_timeout,
                            int32_t next_delay)
{
    TaskGenTestFixture fixture;
    task_gen_type gen = fixture.test_sync_task_generator(done_time, fail_time, next_timeout, watchdog_timeout);

    RR_INTRUSIVE_PTR<rr_gentest::TestGenStatus> status;
    bool res = false;
    do
    {

        res = gen->TryNext(status);
        if (res)
        {
            std::cout << "Status: " << status->message << std::endl;
        }
        if (res && next_delay > 0)
        {
            boost::this_thread::sleep(boost::posix_time::milliseconds(next_delay));
        }
    } while (res);
}

TEST(CompanionUtil, AsyncTaskGenerator)
{
    EXPECT_NO_THROW(run_task_gen_test(100, 1000, 5000, 1000, -1, 0));
    EXPECT_NO_THROW(run_task_gen_test(200, 1000, 5000, 10, -1, 1200));
    EXPECT_NO_THROW(run_task_gen_test(1000, 2000, 5000, 10, -1, 1));
    EXPECT_THROW(run_task_gen_test(1000, 2000, 5000, 10, 150, 200), RR::OperationAbortedException);
    EXPECT_THROW(run_task_gen_test(1000, 300, 5000, 500, 2000, 0), RR::OperationFailedException);
    EXPECT_THROW(run_task_gen_test(1000, 100, 5000, 10, 2000, 200), RR::OperationFailedException);
    EXPECT_NO_THROW(run_task_gen_test(2000, 5000, 5000, 50, 200, 25));
    run_task_gen_test_status_update();
    run_task_gen_test_status_update2();
}

TEST(CompanionUtil, SyncTaskGenerator)
{
    EXPECT_NO_THROW(run_sync_task_gen_test(100, 1000, 1000, -1, 0));
    EXPECT_NO_THROW(run_sync_task_gen_test(200, 1000, 10, -1, 1200));
    EXPECT_NO_THROW(run_sync_task_gen_test(1000, 2000, 10, -1, 1));
    EXPECT_THROW(run_sync_task_gen_test(1000, 2000, 10, 150, 200), RR::OperationAbortedException);
    EXPECT_THROW(run_sync_task_gen_test(1000, 300, 500, 2000, 0), RR::OperationFailedException);
    EXPECT_THROW(run_sync_task_gen_test(1000, 100, 10, 2000, 200), RR::OperationFailedException);
    EXPECT_NO_THROW(run_sync_task_gen_test(2000, 5000, 50, 200, 25));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
