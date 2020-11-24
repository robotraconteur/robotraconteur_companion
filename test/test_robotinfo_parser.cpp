#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>

using namespace YAML;
using namespace RobotRaconteur::Companion::InfoParser::yaml;
using namespace com::robotraconteur::robotics::robot;

int main(int ac, char** av)
{
    auto map = YAML::LoadFile("sawyer_robot_default_config.yml");
    auto robot_info = map.as<RobotInfoPtr>();
    return 0;
}