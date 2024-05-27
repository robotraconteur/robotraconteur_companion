import RobotRaconteur as RR
from RobotRaconteur.RobotRaconteurPythonUtil import SplitQualifiedName
import re
from pathlib import Path

NUMBER_TYPES = {
    RR.DataTypes_double_t: "double",
    RR.DataTypes_single_t: "float",
    RR.DataTypes_int8_t: "int8_t",
    RR.DataTypes_uint8_t: "uint8_t",
    RR.DataTypes_int16_t: "int16_t",
    RR.DataTypes_uint16_t: "uint16_t",
    RR.DataTypes_int32_t: "int32_t",
    RR.DataTypes_uint32_t: "uint32_t",
    RR.DataTypes_int64_t: "int64_t",
    RR.DataTypes_uint64_t: "uint64_t",
}


def convert_bool(val):
    if val:
        return "true"
    else:
        return "false"


def get_qualified_type_string(type_def, service_def):
    assert type_def.Type == RR.DataTypes_namedtype_t

    if '.' in type_def.TypeString:
        return type_def.TypeString.replace('.', '::')
    else:
        return service_def.Name.replace('.', '::') + '::' + type_def.TypeString


def flags_override(flags_enum_type):
    return lambda fieldname, optional: f"RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<{flags_enum_type}>(node,\"{fieldname}\",{convert_bool(optional)})"


FIELD_OVERRIDES = {
    "com.robotraconteur.uuid.UUID.uuid_bytes":
        lambda fieldname, optional: f"RobotRaconteur::Companion::InfoParser::yaml::parse_uuid_bytes_override(node,\"{fieldname}\")",
    "com.robotraconteur.robotics.robot.RobotInfo.robot_capabilities":
    flags_override("com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities"),
    "com.robotraconteur.robotics.tool.ToolInfo.tool_capabilities":
    flags_override("com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities"),
    "com.robotraconteur.servo.ServoInfo.capabilities":
    flags_override("com::robotraconteur::servo::ServoCapabilities::ServoCapabilities"),
    # "com.robotraconteur.robotics.robot.RobotInfo.robot_capabilities": \
    #    flags_override("com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities"),
    # "com.robotraconteur.imaging.Camera.capabilities": \
    #    flags_override("com::robotraconteur::imaging::Capabilities::Capabilities"),
    # "com.robotraconteur.imaging.ImagePartCamera.capabilities": \
    #    flags_override("com::robotraconteur::imaging::Capabilities::Capabilities")
    "com.robotraconteur.robotics.planning.PlannerAlgorithmInfo.algorithm_capability_flags":
        lambda fieldname, optional: f"RobotRaconteur::Companion::InfoParser::yaml::parse_planner_algorithm_flags_override(node,\"{fieldname}\",{convert_bool(optional)})",
    "com.robotraconteur.imaging.camerainfo.CameraCalibration.distortion_info":
        lambda fieldname, optional: f"RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>(node,\"{fieldname}\",{convert_bool(optional)})",
}

OVERRIDE_TYPES = ["com::robotraconteur::uuid::UUID", "com::robotraconteur::identifier::Identifier"]

EXTRA_PROCESSING = {"com::robotraconteur::device::DeviceInfo": "RobotRaconteur::Companion::InfoParser::yaml::device_info_extra_parse(node,rhs);"}


def parse_namedarray_field(field_def, service_def, optional=False):
    fieldname = field_def.Name
    fieldtype = field_def.Type

    f = service_def.Name + "." + field_def.GetServiceEntry().Name + "." + field_def.Name
    if f in FIELD_OVERRIDES:
        return FIELD_OVERRIDES[f](fieldname, optional)

    if fieldtype.Type in NUMBER_TYPES:
        if (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_none):
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_number<{NUMBER_TYPES[fieldtype.Type]}>(node,\"{fieldname}\",{convert_bool(optional)})"
        elif (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_array):
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_na<{NUMBER_TYPES[fieldtype.Type]},{fieldtype.ArrayLength[0]}>(node,\"{fieldname}\")"

    if (fieldtype.Type == RR.DataTypes_namedtype_t):
        field_type_str = get_qualified_type_string(field_def.Type, service_def)
        if (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_none):
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<{field_type_str}>(node,\"{fieldname}\",{convert_bool(optional)})"
        elif (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_array):
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<{field_type_str}>(node,\"{fieldname}\",{convert_bool(optional)},false,{fieldtype.ArrayLength[0]})"

    assert False, "Invalid namedarray field type"


def parse_struct_field(field_def, service_def, service_defs, optional=True):
    fieldname = field_def.Name
    fieldtype = field_def.Type

    f = service_def.Name + "." + field_def.GetServiceEntry().Name + "." + field_def.Name
    if f in FIELD_OVERRIDES:
        return FIELD_OVERRIDES[f](fieldname, optional)

    container = ""
    if fieldtype.ContainerType == RR.DataTypes_ContainerTypes_list:
        container = "_list"
    elif fieldtype.ContainerType == RR.DataTypes_ContainerTypes_map_int32:
        container = "_map_int32"
    elif fieldtype.ContainerType == RR.DataTypes_ContainerTypes_map_string:
        container = "_map_string"

    if fieldtype.Type in NUMBER_TYPES:
        if (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_none):
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_number<{NUMBER_TYPES[fieldtype.Type]}>(node,\"{fieldname}\",{convert_bool(optional)})"
        elif (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_array):
            array_len = 0
            if len(fieldtype.ArrayLength) > 0:
                array_len = fieldtype.ArrayLength[0]
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array{container}<{NUMBER_TYPES[fieldtype.Type]}>(node,\"{fieldname}\",{convert_bool(optional)},{convert_bool(fieldtype.ArrayVarLength)},{array_len})"
        elif (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_multidimarray):
            if len(fieldtype.ArrayLength) != 2:
                return None
            array_len = fieldtype.ArrayLength
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray{container}<{NUMBER_TYPES[fieldtype.Type]}>(node,\"{fieldname}\",{convert_bool(optional)},{array_len[0]},{array_len[1]})"
    elif fieldtype.Type == RR.DataTypes_bool_t:
        return f"RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,\"{fieldname}\",{convert_bool(optional)})"
    elif fieldtype.Type == RR.DataTypes_string_t:
        return f"RobotRaconteur::Companion::InfoParser::yaml::parse_string{container}(node,\"{fieldname}\",{convert_bool(optional)})"
    elif (fieldtype.Type == RR.DataTypes_namedtype_t):
        field_type_str = get_qualified_type_string(field_def.Type, service_def)
        namedtype_def, namedtype_t = resolve_named_type(field_type_str, service_defs)
        if (namedtype_def is None):
            return None
        if namedtype_t == "na":
            if (fieldtype.ContainerType != RR.DataTypes_ContainerTypes_none):
                return None
            if (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_none):
                return f"RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray{container}<{field_type_str}>(node,\"{fieldname}\",{convert_bool(optional)})"
            elif (fieldtype.ArrayType == RR.DataTypes_ArrayTypes_array):
                array_len = 0
                if len(fieldtype.ArrayLength) > 0:
                    array_len = fieldtype.ArrayLength[0]
                return f"RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<{field_type_str}>(node,\"{fieldname}\",{convert_bool(optional)},{convert_bool(fieldtype.ArrayVarLength)},{array_len})"
        elif namedtype_t == "s":
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_structure{container}<{field_type_str}Ptr>(node,\"{fieldname}\",{convert_bool(optional)})"
        elif namedtype_t == "e":
            enum_name = field_type_str.split("::")[-1]
            return f"RobotRaconteur::Companion::InfoParser::yaml::parse_enum{container}<{field_type_str}::{enum_name}>(node,\"{fieldname}\",{convert_bool(optional)})"

    return None


def resolve_named_type(type_str, service_defs):
    def find_type(v, n):
        for t in v:
            if n == t.Name:
                return t
        return None
    service_str, type_str1 = SplitQualifiedName(type_str.replace("::", "."))
    service_def1 = service_defs[service_str]
    na_t = find_type(service_def1.NamedArrays, type_str1)
    if na_t is not None:
        return na_t, "na"
    s_t = find_type(service_def1.Structures, type_str1)
    if s_t is not None:
        return s_t, "s"
    e_t = find_type(service_def1.Enums, type_str1)
    if e_t is not None:
        return e_t, "e"
    return None, None


my_service_defs = {}
source_dir = Path.cwd().joinpath('..').absolute()
assert source_dir.joinpath('include').is_dir(), "Script must be run in tools directory"
assert source_dir.joinpath('robdef/group1').is_dir(), "Standard robdef must be cloned recursively"
robdef_dir = source_dir.joinpath("robdef/group1")


for file in robdef_dir.glob("*.robdef"):
    filed = open(file)
    my_service_def = filed.read()

    service_def = RR.ServiceDefinition()
    service_def.FromString(my_service_def)

    my_service_defs[service_def.Name] = service_def

Named_arrayslist = []
Structureslist = []
enum_list = []
enum_dict = {}
usingdict = {}
for key in my_service_defs:
    name = my_service_defs[key].Name.replace(".", "::")
    print(name)
    for n in my_service_defs[key].NamedArrays:

        # name=my_service_defs[key].Name.replace(".","::")
        qualifiedname = name + "::" + n.Name
        Named_arrayslist.append(qualifiedname)
        usingdict[n.Name] = qualifiedname

    for e in my_service_defs[key].Structures:

        # name=my_service_defs[key].Name.replace(".","::")
        qualifiedname = name + "::" + e.Name
        Structureslist.append(qualifiedname)
        usingdict[e.Name] = qualifiedname
    for use in my_service_defs[key].Using:
        # print(use.UnqualifiedName)
        if (use.UnqualifiedName not in usingdict.keys()):
            usingdict[use.UnqualifiedName] = use.QualifiedName.replace(".", "::")
    for enum in my_service_defs[key].Enums:
        # if(enum.Name not in usingdict.keys()):
        qualifiedname = name + "::" + enum.Name
        enum_dict[enum.Name] = qualifiedname
        enum_list.append((enum.Name, qualifiedname))
        # usingdict[enum.Name]=qualifiedname
# file1 = open("GeometryEnum.txt","w")
error_names = []
print(enum_dict)
yaml_dir = source_dir.joinpath("include/RobotRaconteurCompanion/InfoParser/yaml")
yaml_dir.mkdir(parents=True, exist_ok=True)
filename4 = yaml_dir.joinpath("yaml_parser_all.h")
file4 = open(filename4, "w")
filenames = []
filename5 = yaml_dir.joinpath("yaml_loader_enums_impl.h")
file5 = open(filename5, "w")
file5.write("#pragma once\n")
file5.write("#include <string>\n")
file5.write("#include \"yaml-cpp/yaml.h\"\n")
file5.write("#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>\n")
file5.write("#include <RobotRaconteurCompanion/InfoParser/InfoParserMacros.h>\n")

file5.write("namespace RobotRaconteur{\n")
file5.write("namespace Companion{\n")
file5.write("namespace InfoParser{\n")
file5.write("namespace yaml{\n")
file5.write("template<typename T> struct string_to_enum_traits { };\n")
enum_list2 = enum_list.copy()
enum_list2.sort(key=lambda x: x[0])
for entry in enum_list2:
    file5.write(
        "ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_%s(const std::string &input, const YAML::Node& node);\n" % (entry[0]))
    file5.write("template<> struct string_to_enum_traits<%s::%s> { static %s::%s string_to_enum(const std::string& s, const YAML::Node& node) { return (%s::%s)string_to_enum_%s(s,node); } };\n" % (
        entry[1], entry[0], entry[1], entry[0], entry[1], entry[0], entry[0]))
file5.write("}\n")
file5.write("}\n")
file5.write("}\n")
file5.write("}\n")
file5.close()
src_dir = source_dir.joinpath("src")
filename8 = src_dir.joinpath("yaml_loader_enums.cpp")
filename9 = src_dir.joinpath("yaml_loader_impl.cpp")
file2 = open(filename8, "w")
file6 = open(filename9, "w")
file2.write("#include \"RobotRaconteurCompanion/InfoParser/yaml/yaml_loader_enums.h\"\n")
file2.write("#include <string>\n\n")
file2.write("namespace RobotRaconteur{\n")
file2.write("namespace Companion{\n")
file2.write("namespace InfoParser{\n")
file2.write("namespace yaml{\n")

file6.write("#include \"RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h\"\n")
file6.write("namespace YAML {\n")

file4.write("""/**
 * @file yaml_parser_all.h
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
 */\n\n\n""")
file4.write("#pragma once\n")

test_dir = source_dir.joinpath("test")
testfilename = test_dir.joinpath("test_infoparser.cpp")
testfile = open(testfilename, "w")
testfile.write("#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>\n")
testfile.write("#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>\n\n")
testfile.write("void testfunction()\n{\n")
testfile.write("// Not a full test, just make sure everything compiles\n")
testfile.write("YAML::Node node = YAML::Load(\"[1, 2, 3]\");\n")

my_service_defs_keys = list(my_service_defs.keys())
my_service_defs_keys.sort()

for key in my_service_defs_keys:

    usingdict = {}
    for e in my_service_defs[key].Enums:

        enum_list.append(e.Name)
    # filename="YAMLconverter__"+my_service_defs[key].Name+".h"
    if ("com.robotraconteur." in my_service_defs[key].Name):
        filename = my_service_defs[key].Name.replace("com.robotraconteur.", "")
    else:
        filename = my_service_defs[key].Name
    filename = yaml_dir.joinpath(filename.replace(".", "__") + "_parser.h")
    file4.write("#include \"%s\"\n" % (filename.name))
    file1 = open(filename, "w")
    filenames.append(filename)

    file1.write("#include \"yaml_parser_common_include.h\"\n\n")
    file1.write("#pragma once\n\n")
    file1.write("namespace YAML {\n")

    for e in my_service_defs[key].Enums:
        file2.write("int string_to_enum_%s(const std::string &input, const YAML::Node& node){\n" % (e.Name))
        file2.write("\tRR_UNUSED(node);\n")
        # Compare e.Name to the enum you are looking for
        # print(e.Values[-1].Name)
        enum_list.append(e.Name)
        for e_value in e.Values:
            # if(e_value.Name==e.Values[-1].Name):
            file2.write("\tif(input ==\"" + e_value.Name + "\") return " + str(e_value.Value) + ";\n")
            # else:
            #    file1.write("\t"+e_value.Name + " = " + str(e_value.Value)+",\n")
        file2.write("\tthrow RobotRaconteur::InvalidArgumentException(\"Invalid enum value\");\n")
        file2.write("}\n")
        file2.write("\n")

    for use in my_service_defs[key].Using:
        # print(use.UnqualifiedName)
        if (use.UnqualifiedName not in usingdict.keys()):
            usingdict[use.UnqualifiedName] = use.QualifiedName.replace(".", "::")
    name = my_service_defs[key].Name.replace(".", "::")

    for n in my_service_defs[key].NamedArrays:
        if (name + "::" + n.Name) in OVERRIDE_TYPES:
            continue
        file1.write(
            "\ttemplate<> \n\tstruct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<%s::%s>{\n" % (name, n.Name))
        file1.write("\t\tstatic Node encode(const %s::%s& rhs);\n" % (name, n.Name))
        file1.write("\t\tstatic bool decode(const Node& node, %s::%s& rhs);\n" % (name, n.Name))
        file1.write("\t};\n\n")

        file6.write("\tNode convert<%s::%s>::encode(const %s::%s& rhs){\n" % (name, n.Name, name, n.Name))
        file6.write("\t\tRR_UNUSED(rhs);\n")
        file6.write("\t\tNode node;\n")
        file6.write("\t\treturn node;\n")
        file6.write("\t}\n\n")
        file6.write("\tbool convert<%s::%s>::decode(const Node& node, %s::%s& rhs){\n" % (name, n.Name, name, n.Name))
        qualifiedname = name + "::" + n.Name
        # print(qualifiedname)
        usingdict[n.Name] = qualifiedname
        count = 0
        for i in range(len(n.Members)):
            field_def = n.Members[i]
            fieldname = field_def.Name

            # print(f)
            if (isinstance(field_def, RR.PropertyDefinition)):
                file6.write(f"\t\trhs.s.{fieldname} = {parse_namedarray_field(field_def, my_service_defs[key])};\n")
            count += 1
        file6.write("\t\treturn true;\n")
        file6.write("\t}\n")

        testfile.write("node.as<%s::%s>();\n" % (name, n.Name))

    for e in my_service_defs[key].Structures:
        if (name + "::" + e.Name) in OVERRIDE_TYPES:
            continue

        file1.write(
            "\n\ttemplate<> \n\tstruct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<%s::%sPtr>{\n" % (name, e.Name))
        file1.write("\t\tstatic Node encode(const %s::%sPtr& rhs);\n" % (name, e.Name))
        file1.write("\t\tstatic bool decode(const Node& node, %s::%sPtr& rhs);\n" % (name, e.Name))
        file1.write("\t};\n\n")

        file6.write("\tNode convert<%s::%sPtr>::encode(const %s::%sPtr& rhs){\n" % (name, e.Name, name, e.Name))
        file6.write("\t\tRR_UNUSED(rhs);\n")
        file6.write("\t\tNode node;\n")
        file6.write("\t\treturn node;\n")
        file6.write("\t}\n\n")
        file6.write("\tbool convert<%s::%sPtr>::decode(const Node& node, %s::%sPtr& rhs){\n" % (
            name, e.Name, name, e.Name))
        file6.write("\t\t// NOLINTBEGIN(cppcoreguidelines-owning-memory)\n")
        file6.write("\t\tif (!rhs) rhs.reset(new %s::%s);\n" % (name, e.Name))
        file6.write("\t\t// NOLINTEND(cppcoreguidelines-owning-memory)\n")
        qualifiedname = name + "::" + e.Name
        # usingdict[e.Name]=qualifiedname
        for i in range(len(e.Members)):
            field_def = e.Members[i]
            fieldname = field_def.Name
            # print(f)
            # TODO implement var value parsing as a map of type and value
            if (isinstance(field_def, RR.PropertyDefinition)):
                field_parse_str = parse_struct_field(field_def, my_service_defs[key], my_service_defs)
                if field_parse_str is not None:
                    file6.write(f"\t\trhs->{fieldname} = {field_parse_str};\n")
                else:
                    file6.write(f"\t\t// TODO: parse field {field_def.Type.ToString().split()[0]} {fieldname}\n")
        if (name + "::" + e.Name) in EXTRA_PROCESSING:
            file6.write(EXTRA_PROCESSING[name + "::" + e.Name] + "\n")
        file6.write("\t\treturn true;\n")
        file6.write("\t}\n")

        testfile.write("node.as<%s::%sPtr>();\n" % (name, e.Name))

    if (len(error_names) > 0):
        file1.write("//TODO: Fix the following structures or namedarrays: \n")
        for i in error_names:
            file1.write("// " + i + " \n")

    file1.write("\n}")
    error_names = []

file2.write("}\n")
file2.write("}\n")
file2.write("}\n")
file2.write("}\n")

file6.write("}\n")

testfile.write("}\n\n")
testfile.write("int main(int ac, char** av) // NOLINT\n{\n")
testfile.write("return 0;\n}\n")

print(error_names)
