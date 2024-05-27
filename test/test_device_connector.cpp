/*
Python implementation of the tests for DeviceConnector. Convert to C++

import RobotRaconteur as RR
from RobotRaconteurCompanion.Util.TestFixtures import IntraTaskFixture

from RobotRaconteurCompanion.Util.InfoFileLoader import InfoFileLoader
from RobotRaconteurCompanion.Util.AttributesUtil import AttributesUtil

from RobotRaconteurCompanion.Util.DeviceConnector import DeviceConnector, DeviceConnectorDetails

import importlib_resources
from .. import infoparser as test_infoparser_m
import yaml

import time
import pytest

import io


class _RobotStub:
    def __init__(self, robot_info):
        self.device_info = robot_info.device_info
        self.robot_info = robot_info

        self.tool_changed = RR.EventHook()
        self.payload_changed = RR.EventHook()
        self.param_changed = RR.EventHook()


class _DevConnectorTestFixture:
    def __init__(self):
        self.fixture = IntraTaskFixture()
        self.fixture.register_standard_service_types()

        self.info_loader = InfoFileLoader(self.fixture.server_node)
        self.attributes_util = AttributesUtil(self.fixture.server_node)

        robot1_info = self.load_info("robot1")
        robot2_info = self.load_info("robot2", "54738")
        robot3_info = self.load_info("robot3_another_robot", tags=[
            "my_tag1",
            {
                "name": "my_tag2",
                "uuid": "5a85724f-8533-4a7a-b955-698e1740eff9"
            },
            {
                "uuid": "a3a7fbc2-52b0-426f-8ea9-4934bd24aa8c"
            }
        ])
        robot4_info = self.load_info("robot3_another_robot", tags=[
            "my_tag4",
            {
                "name": "my_tag5",
                "uuid": "25f9682d-932e-44cd-89a5-13d724c2583a"
            },
            {
                "uuid": "385e3ec4-5faa-4c2f-b766-7a9295604a4a"
            }
        ], category="test2")

        self.register_robot_stub(robot1_info, "robot1")
        self.register_robot_stub(robot2_info, "robot2")
        self.register_robot_stub(robot3_info, "robot3")
        self.register_robot_stub(robot4_info, "robot4")

        self.client_node = self.fixture.client_node
        self.client_node.SetLogLevelFromEnvVariable()

    def load_info(self, device_ident, serial_number=None, tags=None, category="test"):
        with (importlib_resources.files(test_infoparser_m) / ('sawyer_robot_default_config.yml')).open() as info_f:
            info_dict = yaml.safe_load(info_f)
        if device_ident is not None:
            info_dict["device_info"]["device"] = device_ident
        if serial_number is not None:
            info_dict["device_info"]["serial_number"] = serial_number
        if tags is not None:
            info_dict["device_info"]["tags"] = tags
        robot_info, fd = self.info_loader.LoadInfoFileFromDict(
            info_dict, "com.robotraconteur.robotics.robot.RobotInfo", category)
        return robot_info

    def register_robot_stub(self, robot_info, service_name):
        attributes = self.attributes_util.GetDefaultServiceAttributesFromDeviceInfo(robot_info.device_info)
        robot_stub = _RobotStub(robot_info)
        ctx = self.fixture.register_service(
            service_name, "com.robotraconteur.robotics.robot.Robot", robot_stub)
        ctx.SetServiceAttributes(attributes)
        return robot_stub

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        self.fixture.shutdown()


def test_device_connector():
    with _DevConnectorTestFixture() as test_fixture:
        con = DeviceConnector(node=test_fixture.client_node)

        d1 = DeviceConnectorDetails(device_nickname="robot1", device="robot1")

        con.AddDevice(d1)

        dev1 = con.GetDevice("robot1")
        c1 = dev1.GetDefaultClientWait(5)

        d1 = c1.device_info
        assert d1.device.name == "robot1"

        con.RemoveDevice("robot1")

        time.sleep(0.5)

        with pytest.raises(Exception):
            con.GetDevice("robot1")

        with pytest.raises(Exception):
            dev1.GetDefaultClientWait(0.1)


def test_device_connector2():
    with _DevConnectorTestFixture() as test_fixture:
        con = DeviceConnector(node=test_fixture.client_node)

        d1 = DeviceConnectorDetails(device_nickname="robot1", urls=["rr+intra:///?nodename=server_node&service=robot1"])

        con.AddDevice(d1)

        dev1 = con.GetDevice("robot1")
        c1 = dev1.GetDefaultClientWait(5)

        d1 = c1.device_info
        assert d1.device.name == "robot1"

        con.RemoveDevice("robot1")

        con.Close()


def _assert_connected_device_count(dev, count):
    if count == 0:
        time.sleep(0.5)
        c = dev.GetConnectedClients()
        assert len(c) == 0
        return
    c1 = dev.GetDefaultClientWait(5)
    for _ in range(5):
        c = dev.GetConnectedClients()
        if len(c) == count:
            break
        time.sleep(0.5)
    assert len(c) == count


def _assert_service_name(node, dev, service_name):
    c = dev.GetDefaultClientWait(5)
    assert node.GetObjectServicePath(c) == service_name


def test_device_connector3():
    with _DevConnectorTestFixture() as test_fixture:
        con = DeviceConnector(node=test_fixture.client_node)

        d1 = DeviceConnectorDetails(device_nickname="robot1", device="robot3_another_robot")
        d2 = DeviceConnectorDetails(device_nickname="robot2", device="robot3_another_robot", tags=["my_tag1"])
        d3 = DeviceConnectorDetails(device_nickname="robot3", device="robot3_another_robot", tags=["my_tag2"])
        d4 = DeviceConnectorDetails(device_nickname="robot4", device="robot3_another_robot", tags=["my_tag10"])
        d5 = DeviceConnectorDetails(device_nickname="robot5", device="robot3_another_robot",
                                    tags=["my_tag1", "my_tag2"])
        d6 = DeviceConnectorDetails(device_nickname="robot6", device="robot3_another_robot",
                                    tags=["my_tag1", "my_tag11"])
        d7 = DeviceConnectorDetails(device_nickname="robot7", device="robot3_another_robot",
                                    tags=["my_tag5|25f9682d-932e-44cd-89a5-13d724c2583a"])
        d8 = DeviceConnectorDetails(device_nickname="robot8", device="robot3_another_robot",
                                    tags=["385e3ec4-5faa-4c2f-b766-7a9295604a4a"])

        con.AddDevice(d1)
        con.AddDevice(d2)
        con.AddDevice(d3)
        con.AddDevice(d4)
        con.AddDevice(d5)
        con.AddDevice(d6)
        con.AddDevice(d7)
        con.AddDevice(d8)

        _assert_connected_device_count(con.GetDevice("robot1"), 2)
        _assert_connected_device_count(con.GetDevice("robot2"), 1)
        _assert_connected_device_count(con.GetDevice("robot3"), 1)
        _assert_connected_device_count(con.GetDevice("robot4"), 0)
        _assert_connected_device_count(con.GetDevice("robot5"), 1)
        _assert_connected_device_count(con.GetDevice("robot6"), 0)
        _assert_connected_device_count(con.GetDevice("robot7"), 1)
        _assert_connected_device_count(con.GetDevice("robot8"), 1)

        _assert_service_name(test_fixture.client_node, con.GetDevice("robot1"), "robot3")
        _assert_service_name(test_fixture.client_node, con.GetDevice("robot2"), "robot3")
        _assert_service_name(test_fixture.client_node, con.GetDevice("robot5"), "robot3")
        _assert_service_name(test_fixture.client_node, con.GetDevice("robot7"), "robot4")
        _assert_service_name(test_fixture.client_node, con.GetDevice("robot8"), "robot4")


def test_device_connector_yaml():
    yaml = \
        """
    devices:
      robot1:
        device: robot1
      robot2:
        device:
          name: robot2
      robot3:
        urls:
        - rr+intra:///?nodename=server_node&service=robot1
      robot4:
        device: robot3_another_robot
        tags:
        - my_tag1
      robot5:
        device:
          name: robot3_another_robot
        tags:
        - my_tag2
      robot6:
        device:
          name: robot3_another_robot
        tags:
        - name: my_tag5
          uuid: 25f9682d-932e-44cd-89a5-13d724c2583a
    """
    with _DevConnectorTestFixture() as test_fixture:
        f = io.StringIO(yaml)
        con = DeviceConnector(devices_yaml_f=f, node=test_fixture.client_node)

        _assert_connected_device_count(con.GetDevice("robot1"), 1)
        _assert_connected_device_count(con.GetDevice("robot2"), 1)
        _assert_connected_device_count(con.GetDevice("robot3"), 1)
        _assert_connected_device_count(con.GetDevice("robot4"), 1)
        _assert_connected_device_count(con.GetDevice("robot5"), 1)
        _assert_connected_device_count(con.GetDevice("robot6"), 1)
*/

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

    RobotStub(RobotInfoPtr robot_info) { this->robot_info = robot_info; }
};

void LoadTags(RobotInfoPtr robot_info, const std::string& tags)
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

    RR_SHARED_PTR<RobotStub> RegisterRobotStub(RobotInfoPtr robot_info, const std::string& service_name)
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

void _assert_service_name(RR::RobotRaconteurNodePtr node, const RR::ServiceSubscriptionPtr& dev,
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
