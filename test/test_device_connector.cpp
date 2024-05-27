
#include <RobotRaconteurCompanion/Util/DeviceConnector.h>
#include <RobotRaconteurCompanion/Util/TestFixtures.h>

#include <RobotRaconteurCompanion/Util/InfoFileLoader.h>
#include <RobotRaconteurCompanion/Util/AttributesUtil.h>

#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/Util/IdentifierUtil.h>

#include <com__robotraconteur__robotics__robot_stubskel.h>

#include <gtest/gtest.h>

namespace RR = RobotRaconteur;
namespace RRC = RobotRaconteur::Companion;
namespace RR_Util = RobotRaconteur::Companion::Util;

using namespace com::robotraconteur::robotics::robot;
using namespace com::robotraconteur::identifier;

class RobotStub : public Robot_default_impl
{
  public:
    RobotInfoPtr robot_info;

    RobotInfoPtr get_robot_info() override { return robot_info; }

    com::robotraconteur::device::DeviceInfoPtr get_device_info() override { return robot_info->device_info; }

    RobotStub(const RobotInfoPtr& robot_info) { this->robot_info = robot_info; }
};

void LoadTags(const RobotInfoPtr& robot_info, const std::string& tags)
{
    std::vector<std::string> tag_str_list;
    boost::split(tag_str_list, tags, boost::is_any_of(","));

    RR::RRListPtr<RR::RRValue> tag_list = RR::AllocateEmptyRRList<RR::RRValue>();
    for (auto& tag_str : tag_str_list)
    {
        tag_list->push_back(RR_Util::StringToIdentifier(tag_str));
    }

    if (!robot_info->device_info->extended)
    {
        robot_info->device_info->extended = RR::AllocateEmptyRRMap<std::string, RR::RRValue>();
    }

    robot_info->device_info->extended->insert(std::make_pair("tags", tag_list));
}

class DevConnectorTestFixture
{
  public:
    RR_Util::IntraTestFixture fixture;
    RR::RobotRaconteurNodePtr client_node;

    void Init()
    {
        RRC::RegisterStdRobDefServiceTypes(fixture.server_node);
        RRC::RegisterStdRobDefServiceTypes(fixture.client_node);

        RobotInfoPtr robot1_info = LoadInfo("robot1");

        RobotInfoPtr robot2_info = LoadInfo("robot2");
        robot2_info->device_info->serial_number = "54738";

        RobotInfoPtr robot3_info = LoadInfo("robot3_another_robot");
        LoadTags(robot3_info,
                 "my_tag1,my_tag2|5a85724f-8533-4a7a-b955-698e1740eff9,a3a7fbc2-52b0-426f-8ea9-4934bd24aa8c");

        RobotInfoPtr robot4_info = LoadInfo("robot3_another_robot");
        LoadTags(robot4_info,
                 "my_tag4,my_tag5|25f9682d-932e-44cd-89a5-13d724c2583a,385e3ec4-5faa-4c2f-b766-7a9295604a4a");

        RegisterRobotStub(robot1_info, "robot1");
        RegisterRobotStub(robot2_info, "robot2");
        RegisterRobotStub(robot3_info, "robot3");
        RegisterRobotStub(robot4_info, "robot4");

        client_node = fixture.client_node;
        client_node->SetLogLevelFromEnvVariable();
    }

    RobotInfoPtr LoadInfo(const std::string& device_ident)
    {
        auto map = YAML::LoadFile("sawyer_robot_default_config.yml");
        auto robot_info = map.as<RobotInfoPtr>();
        robot_info->device_info->device = RR_Util::CreateIdentifierFromName(device_ident);
        return robot_info;
    }

    RR_SHARED_PTR<RobotStub> RegisterRobotStub(RobotInfoPtr robot_info, const std::string& service_name) const
    {
        auto attributes = RR_Util::GetDefaultServiceAttributesFromDeviceInfo(robot_info->device_info);
        auto robot_stub = RR_MAKE_SHARED<RobotStub>(robot_info);
        auto ctx = fixture.RegisterService(service_name, "com.robotraconteur.robotics.robot", robot_stub);
        ctx->SetAttributes(attributes);
        return robot_stub;
    }
};

TEST(DeviceConnector, TestDeviceConnector)
{
    DevConnectorTestFixture test_fixture;
    test_fixture.Init();

    RR_Util::DeviceConnector con(test_fixture.client_node);
    con.Init();

    RR_Util::DeviceConnectorDetails d1("robot1", RR_Util::CreateIdentifierFromName("robot1"),
                                       {"com.robotraconteur.robotics.robot.Robot"});

    con.AddDevice(d1);

    auto dev1 = con.GetDevice("robot1");
    ASSERT_TRUE(dev1);
    RobotPtr c1;
    c1 = dev1->GetDefaultClientWait<Robot>(5000);

    auto inf1 = c1->get_device_info();
    ASSERT_EQ(inf1->device->name, "robot1");

    con.RemoveDevice("robot1");

    boost::this_thread::sleep(boost::posix_time::milliseconds(500));

    ASSERT_THROW(con.GetDevice("robot1"), std::runtime_error);
    ASSERT_THROW(dev1->GetDefaultClientWait<Robot>(100), std::runtime_error);
}

TEST(DeviceConnector, TestDeviceConnector2)
{
    DevConnectorTestFixture test_fixture;
    test_fixture.Init();

    RR_Util::DeviceConnector con(test_fixture.client_node);
    con.Init();

    RR_Util::DeviceConnectorDetails d1("robot1", {"rr+intra:///?nodename=server_node&service=robot1"});

    con.AddDevice(d1);

    auto dev1 = con.GetDevice("robot1");
    ASSERT_TRUE(dev1);
    RobotPtr c1;
    c1 = dev1->GetDefaultClientWait<Robot>(5000);

    auto inf1 = c1->get_device_info();
    ASSERT_EQ(inf1->device->name, "robot1");

    con.RemoveDevice("robot1");

    con.Close();
}

void _assert_connected_device_count(const RR::ServiceSubscriptionPtr& dev, size_t count)
{
    if (count == 0)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));
        auto c = dev->GetConnectedClients();
        ASSERT_EQ(c.size(), 0);
        return;
    }
    auto c1 = dev->GetDefaultClientWait<Robot>(5000);
    for (size_t i = 0; i < 5; i++)
    {
        auto c = dev->GetConnectedClients();
        if (c.size() == count)
        {
            break;
        }
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    }
    auto c = dev->GetConnectedClients();
    ASSERT_EQ(c.size(), count);
}

void _assert_service_name(const RR::RobotRaconteurNodePtr& node, const RR::ServiceSubscriptionPtr& dev,
                          const std::string& service_name)
{
    auto c = dev->GetDefaultClientWait<Robot>(5000);
    ASSERT_EQ(node->GetObjectServicePath(c), service_name);
}

TEST(DeviceConnector, TestDeviceConnector3)
{
    DevConnectorTestFixture test_fixture;
    test_fixture.Init();

    RR_Util::DeviceConnector con(test_fixture.client_node);
    con.Init();

    RR_Util::DeviceConnectorDetails d1("robot1", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"});
    RR_Util::DeviceConnectorDetails d2("robot2", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"},
                                       {RR_Util::StringToIdentifier("my_tag1")});
    RR_Util::DeviceConnectorDetails d3("robot3", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"},
                                       {RR_Util::StringToIdentifier("my_tag2")});
    RR_Util::DeviceConnectorDetails d4("robot4", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"},
                                       {RR_Util::StringToIdentifier("my_tag10")});
    RR_Util::DeviceConnectorDetails d5(
        "robot5", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
        {"com.robotraconteur.robotics.robot.Robot"},
        {RR_Util::StringToIdentifier("my_tag1"), RR_Util::StringToIdentifier("my_tag2")});
    RR_Util::DeviceConnectorDetails d6(
        "robot6", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
        {"com.robotraconteur.robotics.robot.Robot"},
        {RR_Util::StringToIdentifier("my_tag1"), RR_Util::StringToIdentifier("my_tag11")});
    RR_Util::DeviceConnectorDetails d7("robot7", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"},
                                       {RR_Util::StringToIdentifier("my_tag5|25f9682d-932e-44cd-89a5-13d724c2583a")});
    RR_Util::DeviceConnectorDetails d8("robot8", RR_Util::CreateIdentifierFromName("robot3_another_robot"),
                                       {"com.robotraconteur.robotics.robot.Robot"},
                                       {RR_Util::StringToIdentifier("385e3ec4-5faa-4c2f-b766-7a9295604a4a")});

    con.AddDevice(d1);
    con.AddDevice(d2);
    con.AddDevice(d3);
    con.AddDevice(d4);
    con.AddDevice(d5);
    con.AddDevice(d6);
    con.AddDevice(d7);
    con.AddDevice(d8);

    _assert_connected_device_count(con.GetDevice("robot1"), 2);
    _assert_connected_device_count(con.GetDevice("robot2"), 1);
    _assert_connected_device_count(con.GetDevice("robot3"), 1);
    _assert_connected_device_count(con.GetDevice("robot4"), 0);
    _assert_connected_device_count(con.GetDevice("robot5"), 1);
    _assert_connected_device_count(con.GetDevice("robot6"), 0);
    _assert_connected_device_count(con.GetDevice("robot7"), 1);
    _assert_connected_device_count(con.GetDevice("robot8"), 1);

    _assert_service_name(test_fixture.client_node, con.GetDevice("robot1"), "robot3");
    _assert_service_name(test_fixture.client_node, con.GetDevice("robot2"), "robot3");
    _assert_service_name(test_fixture.client_node, con.GetDevice("robot5"), "robot3");
    _assert_service_name(test_fixture.client_node, con.GetDevice("robot7"), "robot4");
    _assert_service_name(test_fixture.client_node, con.GetDevice("robot8"), "robot4");
}

TEST(DeviceConnector, TestDeviceConnectorYaml)
{
    DevConnectorTestFixture test_fixture;
    test_fixture.Init();

    std::string yaml = R"(
    devices:
      robot1:
        device: robot1
        root_object_type: com.robotraconteur.robotics.robot.Robot
      robot2:
        device:
          name: robot2
        root_object_type: com.robotraconteur.robotics.robot.Robot
      robot3:
        urls:
        - rr+intra:///?nodename=server_node&service=robot1
        root_object_type: com.robotraconteur.robotics.robot.Robot
      robot4:
        device: robot3_another_robot
        tags:
        - my_tag1
        root_object_type: com.robotraconteur.robotics.robot.Robot
      robot5:
        device:
          name: robot3_another_robot
        tags:
        - my_tag2
        root_object_type: com.robotraconteur.robotics.robot.Robot
      robot6:
        device:
          name: robot3_another_robot
        tags:
        - name: my_tag5
          uuid: 25f9682d-932e-44cd-89a5-13d724c2583a
        root_object_type: com.robotraconteur.robotics.robot.Robot
    )";

    RR_Util::DeviceConnector con(test_fixture.client_node);
    con.InitFromYamlStr(yaml);

    _assert_connected_device_count(con.GetDevice("robot1"), 1);
    _assert_connected_device_count(con.GetDevice("robot2"), 1);
    _assert_connected_device_count(con.GetDevice("robot3"), 1);
    _assert_connected_device_count(con.GetDevice("robot4"), 1);
    _assert_connected_device_count(con.GetDevice("robot5"), 1);
    _assert_connected_device_count(con.GetDevice("robot6"), 1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
