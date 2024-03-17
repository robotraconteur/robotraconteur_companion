#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>
#include <RobotRaconteurCompanion/Util/InfoFileLoader.h>

using namespace YAML;
using namespace RobotRaconteur::Companion::InfoParser::yaml;
using namespace com::robotraconteur::robotics::robot;

int main(int ac, char** av) // NOLINT
{
    auto map = YAML::LoadFile("sawyer_robot_default_config.yml");
    auto robot_info = map.as<RobotInfoPtr>();

    std::vector<RobotRaconteur::Companion::Util::LocalIdentifierLockPtr> identifier_locks;
    auto robot_info2 = RobotRaconteur::Companion::Util::LoadInfoFile<RobotInfoPtr>("sawyer_robot_default_config.yml",
                                                                                   identifier_locks, "robot");
    auto dev_info2 =
        RobotRaconteur::Companion::Util::LoadInfoFileFromString<com::robotraconteur::device::DeviceInfoPtr>(
            "{}", identifier_locks);
    return 0;
}
