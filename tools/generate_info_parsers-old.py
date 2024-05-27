import RobotRaconteur as RR
import re
from pathlib import Path

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
        enum_list.append(enum.Name)
        # usingdict[enum.Name]=qualifiedname
# file1 = open("GeometryEnum.txt","w")
error_names = []
print(enum_dict)
yaml_dir = source_dir.joinpath("include/RobotRaconteurCompanion/InfoParser/yaml")
yaml_dir.mkdir(parents=True, exist_ok=True)
filename4 = yaml_dir.joinpath("yaml_parser_all.h")
file4 = open(filename4, "w")
filenames = []
filename5 = yaml_dir.joinpath("yaml_loader_enums.h")
file5 = open(filename5, "w")
file5.write("#pragma once\n")
file5.write("#include <string>\n")

file5.write("namespace RobotRaconteur{\n")
file5.write("namespace Companion{\n")
file5.write("namespace InfoParser{\n")
file5.write("namespace yaml{\n")
for entry in enum_list:
    file5.write("int string_to_enum_%s(const std::string &input);\n" % (entry))
file5.write("}\n")
file5.write("}\n")
file5.write("}\n")
file5.write("}\n")
file5.close()
src_dir = source_dir.joinpath("src")
filename8 = src_dir.joinpath("yaml_loader_enums.cpp")
file2 = open(filename8, "w")
file2.write("#include \"RobotRaconteurCompanion/InfoParser/yaml/yaml_loader_enums.h\"\n")
file2.write("#include <string>\n\n")
file2.write("namespace RobotRaconteur{\n")
file2.write("namespace Companion{\n")
file2.write("namespace InfoParser{\n")
file2.write("namespace yaml{\n")

file4.write("#pragma once\n")

test_dir = source_dir.joinpath("test")
testfilename = test_dir.joinpath("test_infoparser.cpp")
testfile = open(testfilename, "w")
testfile.write("#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>\n")
testfile.write("#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>\n\n")
testfile.write("void testfunction()\n{\n")
testfile.write("// Not a full test, just make sure everything compiles\n")
testfile.write("YAML::Node node = YAML::Load(\"[1, 2, 3]\");\n")

for key in my_service_defs:

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
    file1.write("#pragma once\n")

    file1.write("#include <RobotRaconteur.h>\n")
    file1.write("#include \"yaml-cpp/yaml.h\"\n")
    file1.write("#include <boost/uuid/uuid_io.hpp>\n")
    file1.write("#include \"RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h\"\n")
    file1.write("#include \"yaml_loader_enums.h\"\n\n")
    file1.write("using namespace RobotRaconteur;\n")
    file1.write("using namespace Companion;\n")
    file1.write("using namespace boost;\n\n")
    file1.write("#pragma once\n\n")
    file1.write("namespace RR = RobotRaconteur;\n\n")
    file1.write("namespace YAML {\n")

    for e in my_service_defs[key].Enums:
        file2.write("int string_to_enum_%s(const std::string &input){\n" % (e.Name))
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
        file1.write("\ttemplate<> \n\tstruct convert<%s::%s>{\n" % (name, n.Name))
        file1.write("\t\tstatic Node encode(const %s::%s& rhs){\n" % (name, n.Name))
        file1.write("\t\t\tNode node;\n")
        file1.write("\t\t\treturn node;\n")
        file1.write("\t\t}\n\n")
        file1.write("\t\tstatic bool decode(const Node& node, %s::%s& rhs){\n" % (name, n.Name))
        qualifiedname = name + "::" + n.Name
        # print(qualifiedname)
        usingdict[n.Name] = qualifiedname
        count = 0
        for field in n.Members:
            output = field.ToString()
            fieldname = field.Name
            f = re.split('\s+', output)
            # print(f)
            if (f[0] == "property"):
                if (f[1] == "single"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<float>();\n" % (f[2], f[2]))
                elif (f[1] == "double"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<double>();\n" % (f[2], f[2]))
                elif (f[1] == "int32"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<int>();\n" % (f[2], f[2]))
                elif (f[1] == "uint32"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<uint32_t>();\n" % (f[2], f[2]))
                elif (f[1] == "bool"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<bool>();\n" % (f[2], f[2]))
                elif (f[1] == "int8"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<int8>();\n" % (f[2], f[2]))
                elif (f[1] == "uint8"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<uint8_t>();\n" % (f[2], f[2]))
                elif (f[1] == "int16"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<int16_t>();\n" % (f[2], f[2]))
                elif (f[1] == "uint16"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<uint16_t>();\n" % (f[2], f[2]))
                elif (f[1] == "int64"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<int64_t>();\n" % (f[2], f[2]))
                elif (f[1] == "uint64"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<uint64_t>();\n" % (f[2], f[2]))
                elif (f[1] == "string"):
                    file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<std::string>();\n" % (f[2], f[2]))
                elif (f[1] == "uint8[16]"):
                    file1.write("\t\t\tstd::string uuid_long = node.as<std::string>();\n")
                    file1.write("\t\t\tauto uuid_boost = boost::lexical_cast<boost::uuids::uuid>(uuid_long);\n")
                    file1.write("\t\t\tcom::robotraconteur::uuid::UUID uuid;\n")
                    file1.write("\t\t\tstd::copy(uuid_boost.begin(), uuid_boost.end(), uuid.a.begin());\n")
                    # file1.write("\t\t\trhs.s.uuid_bytes=uuid;\n")

                elif ("[" in f[1]):
                    if ("single" in f[1]):
                        # file1.write("\t\t\tRRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node[\"%s\"].size());\n"%(f[2]))
                        file1.write("\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                        file1.write("\t\t\t\trhs.s.%s[i]= node[\"%s\"][i].as<float>();\n" % (f[2], f[2]))
                        file1.write("\t\t\t}\n")
                        # file1.write("\t\t\trhs.s.%s = my_array;\n"%(f[2]))
                    elif ("double" in f[1]):
                        # file1.write("\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[\"%s\"].size());\n"%(f[2]))
                        file1.write("\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                        file1.write("\t\t\t\trhs.s.%s[i]= node[\"%s\"][i].as<double>();\n" % (f[2], f[2]))
                        file1.write("\t\t\t}\n")
                        # file1.write("\t\t\trhs.s.%s = my_array;\n"%(f[2]))
                elif (f[1] in usingdict.keys()):
                    # print(
                    if (usingdict.get(f[1]) in Structureslist):
                        file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<%sPtr>();\n" % (f[2], f[2], usingdict.get(f[1])))
                    if (usingdict.get(f[1]) in Named_arrayslist):
                        file1.write("\t\t\trhs.s.%s = node[\"%s\"].as<%s>();\n" % (f[2], f[2], usingdict.get(f[1])))

                else:
                    if (qualifiedname not in error_names):
                        error_names.append(qualifiedname)
                    # print("\n"+f[1]+"\n")
                    # print(f[2]+"\n")

            count += 1
        file1.write("\t\t\treturn true;\n")
        file1.write("\t\t}\n")
        file1.write("\t};\n\n")

        testfile.write("node.as<%s::%s>();\n" % (name, n.Name))

    for e in my_service_defs[key].Structures:
        file1.write("\n\ttemplate<> \n\tstruct convert<%s::%sPtr>{\n" % (name, e.Name))
        file1.write("\t\tstatic Node encode(const %s::%sPtr& rhs){\n" % (name, e.Name))
        file1.write("\t\t\tNode node;\n")
        file1.write("\t\t\treturn node;\n")
        file1.write("\t\t}\n\n")
        file1.write("\t\tstatic bool decode(const Node& node, %s::%sPtr& rhs){\n" % (name, e.Name))
        file1.write("\t\t\tif (!rhs) rhs.reset(new %s::%s);\n" % (name, e.Name))
        qualifiedname = name + "::" + e.Name
        # usingdict[e.Name]=qualifiedname
        for field in e.Members:
            output = field.ToString()
            fieldname = field.Name
            f = re.split('\s+', output)
            # print(f)
            # TODO implement var value parsing as a map of type and value
            if (f[0] == "property"):
                if (f[1] == "single"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<float>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "double"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<double>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "int32"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<int>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "uint32"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<uint32_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "int8"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<int8_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "uint8"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<uint8_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "int16"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<int16_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "uint16"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<uint16_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "int64"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<int64_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "uint64"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<uint64_t>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "string"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<std::string>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif (f[1] == "bool"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<bool>();\n" % (f[2], f[2]))
                    file1.write("\t\t\t}\n")
                elif ("[" in f[1]):
                    if ("," in f[1]):
                        if ("single" in f[1]):
                            size = f[1].replace("single[", "").replace("]", "")
                            numbers = size.split(",")
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write("\t\t\t\tstd::vector<uint32_t> dims = {%s,%s};\n" % (numbers[0], numbers[1]))
                            file1.write(
                                "\t\t\t\tRRMultiDimArrayPtr<float> my_multidimarray = AllocateEmptyRRMultiDimArray<float>(dims);\n")
                            file1.write("\t\t\t\tfor(int i =0; i< %s; i++){\n" % (numbers[0]))
                            file1.write("\t\t\t\t\tfor(int j=0; j< %s; j++){\n" % (numbers[1]))

                            file1.write(
                                "\t\t\t\t\t\tmy_multidimarray->Array->at(i+(j * %s)) = node[\"%s\"][j+ (i * %s)].as<float>();\n" % (numbers[0], f[2], numbers[1]))
                            file1.write("\t\t\t\t\t}\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_multidimarray;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                        elif ("double" in f[1]):
                            size = f[1].replace("double[", "").replace("]", "")
                            numbers = size.split(",")
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write("\t\t\t\tstd::vector<uint32_t> dims = {%s,%s};\n" % (numbers[0], numbers[1]))
                            file1.write(
                                "\t\t\t\tRRMultiDimArrayPtr<double> my_multidimarray = AllocateEmptyRRMultiDimArray<double>(dims);\n")
                            file1.write("\t\t\t\tfor(int i =0; i< %s; i++){\n" % (numbers[0]))
                            file1.write("\t\t\t\t\tfor(int j=0; j< %s; j++){\n" % (numbers[1]))

                            file1.write(
                                "\t\t\t\t\t\tmy_multidimarray->Array->at(i+(j * %s)) = node[\"%s\"][j+ (i * %s)].as<double>();\n" % (numbers[0], f[2], numbers[1]))
                            file1.write("\t\t\t\t\t}\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_multidimarray;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                    else:
                        if ("{string}" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write("\t\t\t\tRR::RRMapPtr<std::string, RR::RRArray<double>> joints;\n")
                            file1.write(
                                "\t\t\t\tfor (YAML::const_iterator it = node[\"%s\"].begin(); it != node[\"%s\"].end(); ++it) {\n" % (f[2], f[2]))
                            file1.write("\t\t\t\t\tstd::string name = it->first.as<std::string>();\n")
                            file1.write(
                                "\t\t\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[name].size());\n")
                            file1.write("\t\t\t\t\tfor (int i = 0; i < node[name].size(); i++) {\n")
                            file1.write("\t\t\t\t\t\tmy_array->at(i) = node[name][i].as<double>();\n")
                            file1.write("\t\t\t\t\t}\n")
                            file1.write("\t\t\t\t\tjoints->insert(std::make_pair(name,my_array));\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = joints;\n" % (f[2]))
                            file1.write("\t\t\t}\n")

                        elif ("{list}" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();\n")
                            # file1.write("\t\t\t\tRobotRaconteur::RRListPtr<%s> listy = AllocateEmptyRRList<%s>();\n"%(usingdict.get(f[1].replace("{list}","")),usingdict.get(f[1].replace("{list}",""))))
                            file1.write("\t\t\t\tfor(int i =0; i<node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write(
                                "\t\t\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[\"%s\"][i].size());\n" % (f[2]))
                            file1.write("\t\t\t\t\tfor(int k =0; k<node[\"%s\"][i].size(); k++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\t\tmy_array->at(k)=node[\"%s\"][i][k].as<double>();\n" % (f[2]))
                            file1.write("\t\t\t\t\t}\n")
                            file1.write("\t\t\t\t\tlisty->push_back(my_array);\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = listy;\n" % (f[2]))
                            file1.write("\t\t\t}\n")

                        elif ("single" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<float>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                        elif ("double" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<double>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")

                        elif ("uint32" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<uint32_t>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")

                        elif ("uint8" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<uint8_t>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                        elif ("int16" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<int16_t> my_array = AllocateEmptyRRArray<int16_t>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<int16_t>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                        elif ("int32" in f[1]):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write(
                                "\t\t\t\tRRArrayPtr<int32_t> my_array = AllocateEmptyRRArray<int32_t>(node[\"%s\"].size());\n" % (f[2]))
                            file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                            file1.write("\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<int32_t>();\n" % (f[2]))
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                            file1.write("\t\t\t}\n")

                        elif (f[1].replace("[]", "") in usingdict.keys()):
                            if (usingdict.get(f[1]) in Structureslist):
                                file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                                file1.write("\t\t\t\tRRArrayPtr<%sPtr> my_array = AllocateEmptyRRArray<%sPtr>(node[\"%s\"].size());\n" % (
                                    usingdict.get(f[1]), usingdict.get(f[1]), f[2]))
                                file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                                file1.write(
                                    "\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<%sPtr>();\n" % (f[2], usingdict.get(f[1])))
                                file1.write("\t\t\t\t}\n")
                                file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                                file1.write("\t\t\t}\n")
                            if (usingdict.get(f[1]) in Named_arrayslist):
                                file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                                file1.write("\t\t\t\tRRArrayPtr<%s> my_array = AllocateEmptyRRArray<%s>(node[\"%s\"].size());\n" % (
                                    usingdict.get(f[1]), usingdict.get(f[1]), f[2]))
                                file1.write("\t\t\t\tfor (int i = 0; i < node[\"%s\"].size(); i++) {\n" % (f[2]))
                                file1.write(
                                    "\t\t\t\t\tmy_array->at(i) = node[\"%s\"][i].as<%s>();\n" % (f[2], usingdict.get(f[1])))
                                file1.write("\t\t\t\t}\n")
                                file1.write("\t\t\t\trhs->%s = my_array;\n" % (f[2]))
                                file1.write("\t\t\t}\n")

                elif ("{list}" in f[1]):
                    # RR::RRListPtr<imaging::camerainfo::CameraInfo> camerainfos = AllocateEmptyRRList<imaging::camerainfo::CameraInfo>();

                    if (f[1].replace("{list}", "") == "string"):
                        file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                        file1.write(
                            "\t\t\t\tRobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();\n")
                        file1.write("\t\t\t\tfor(int j=0; j< node[\"%s\"].size(); j++){\n" % (f[2]))
                        file1.write("\t\t\t\t\tstd::string item= node[\"%s\"][j].as<std::string>();\n" % (f[2]))
                        file1.write("\t\t\t\t\tRRArrayPtr<char> itemRR= RR::stringToRRArray(item);\n")
                        file1.write("\t\t\t\t\tlisty->push_back(itemRR);\n")
                        file1.write("\t\t\t\t}\n")
                        file1.write("\t\t\t\trhs->%s = listy;\n" % (f[2]))
                        file1.write("\t\t\t}\n")

                    elif (f[1].replace("{list}", "") in usingdict.keys()):
                        # print(f[1].replace("{list}",""))
                        # print(usingdict.get(f[1].replace("{list}","")))
                        if (usingdict.get(f[1].replace("{list}", "")) in Structureslist):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            # file1.write("\t\t\t\tRobotRaconteur::RRListPtr<%sPtr> listy = AllocateEmptyRRList<%sPtr>();\n"%(usingdict.get(f[1].replace("{list}","")),usingdict.get(f[1].replace("{list}",""))))
                            file1.write("\t\t\t\tRobotRaconteur::RRListPtr<%s> listy = AllocateEmptyRRList<%s>();\n" % (
                                usingdict.get(f[1].replace("{list}", "")), usingdict.get(f[1].replace("{list}", ""))))
                            file1.write("\t\t\t\tfor(int j=0; j< node[\"%s\"].size(); j++){\n" % (f[2]))
                            file1.write("\t\t\t\t\t%sPtr item= node[\"%s\"][j].as<%sPtr>();\n" % (usingdict.get(
                                f[1].replace("{list}", "")), f[2], usingdict.get(f[1].replace("{list}", ""))))
                            file1.write("\t\t\t\t\tlisty->push_back(item);\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = listy;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                            # print("\t%s item= node[\"%s\"][j].as<%s>();\n"%(usingdict.get(f[1].replace("{list}","")),f[2],usingdict.get(f[1].replace("{list}",""))))
                        if (usingdict.get(f[1].replace("{list}", "")) in Named_arrayslist):
                            file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                            file1.write("\t\t\t\tRobotRaconteur::RRListPtr<RRNamedArray<%s>> listy = AllocateEmptyRRList<RRNamedArray<%s>>();\n" % (
                                usingdict.get(f[1].replace("{list}", "")), usingdict.get(f[1].replace("{list}", ""))))
                            file1.write("\t\t\t\tfor(int j=0; j< node[\"%s\"].size(); j++){\n" % (f[2]))
                            file1.write("\t\t\t\t\t%s item= node[\"%s\"][j].as<%s>();\n" % (usingdict.get(
                                f[1].replace("{list}", "")), f[2], usingdict.get(f[1].replace("{list}", ""))))

                            file1.write("\t\t\t\t\tlisty->push_back(RobotRaconteur::ScalarToRRNamedArray(item));\n")
                            file1.write("\t\t\t\t}\n")
                            file1.write("\t\t\t\trhs->%s = listy;\n" % (f[2]))
                            file1.write("\t\t\t}\n")
                            # print("\t%s item= node[\"%s\"][j].as<%s>();\n"%(usingdict.get(f[1].replace("{list}","")),f[2],usingdict.get(f[1].replace("{list}",""))))

                elif (f[1] in enum_list):
                    # std::string array_type_code = node["array_type_code"].as<std::string>();
                    # rhs->array_type_code = com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode(string_to_enum_ArrayTypeCode(array_type_code));
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\tstd::string enum_val_string= node[\"%s\"].as<std::string>();\n" % (f[2]))
                    file1.write("\t\t\t\trhs->%s = %s::%s(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_%s(enum_val_string));\n" %
                                (f[2], enum_dict.get(f[1]), f[1], f[1]))
                    file1.write("\t\t\t}\n")
                    # print("\t\t\t\trhs->%s = %s::%s(string_to_enum_%s(enum_val_string));\n"%(f[2],usingdict.get(f[1]),f[1],f[1]))

                elif (f[1] in usingdict.keys()):
                    if (usingdict.get(f[1]) in Structureslist):
                        file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                        file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<%sPtr>();\n" % (f[2], f[2], usingdict.get(f[1])))
                        file1.write("\t\t\t}\n")
                    if (usingdict.get(f[1]) in Named_arrayslist):
                        file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                        file1.write("\t\t\t\trhs->%s = node[\"%s\"].as<%s>();\n" % (f[2], f[2], usingdict.get(f[1])))
                        file1.write("\t\t\t}\n")

                elif (f[1].replace("{string}", "") in usingdict.keys()):
                    if (usingdict.get(f[1]) in Structureslist):
                        file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                        file1.write("\t\t\t\tRR::RRMapPtr<std::string, %sPtr> joints;\n" % (usingdict.get(f[1])))
                        file1.write(
                            "\t\t\t\tfor (YAML::const_iterator it = node[\"%s\"].begin(); it != node[\"%s\"].end(); ++it) {\n" % (f[2], f[2]))
                        file1.write("\t\t\t\t\tstd::string name = it->first.as<std::string>();\n")

                        file1.write(
                            "\t\t\t\t\tjoints->insert(std::make_pair(name,node[name].as<%sPtr>()));\n" % (usingdict.get(f[1])))
                        file1.write("\t\t\t\t}\n")
                        file1.write("\t\t\t\trhs->%s = joints;\n" % (f[2]))
                        file1.write("\t\t\t}\n")
                    if (usingdict.get(f[1]) in Named_arrayslist):
                        file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                        file1.write("\t\t\t\tRR::RRMapPtr<std::string, %s> joints;\n" % (usingdict.get(f[1])))
                        file1.write(
                            "\t\t\t\tfor (YAML::const_iterator it = node[\"%s\"].begin(); it != node[\"%s\"].end(); ++it) {\n" % (f[2], f[2]))
                        file1.write("\t\t\t\t\tstd::string name = it->first.as<std::string>();\n")

                        file1.write(
                            "\t\t\t\t\tjoints->insert(std::make_pair(name,node[name].as<%s>()));\n" % (usingdict.get(f[1])))
                        file1.write("\t\t\t\t}\n")
                        file1.write("\t\t\t\trhs->%s = joints;\n" % (f[2]))
                        file1.write("\t\t\t}\n")

                elif (f[1] == "varvalue{string}"):
                    # print("varvalue seen")
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))
                    file1.write("\t\t\t\tRR::RRMapPtr<std::string, RR::RRValue> vars;\n")
                    file1.write(
                        "\t\t\t\tfor (YAML::const_iterator it = node[\"%s\"].begin(); it != node[\"%s\"].end(); ++it) {\n" % (f[2], f[2]))
                    file1.write("\t\t\t\t\tstd::string name = it->first.as<std::string>();\n")
                    file1.write("\t\t\t\t\tstd::string type = node[\"%s\"][\"type\"].as<std::string>();\n" % (f[2]))
                    file1.write("\t\t\t\t\tRR::RRValuePtr varval;\n")
                    file1.write("\t\t\t\t\tif(type==\"string\"){\n")
                    file1.write("\t\t\t\t\t\tstd::string value = node[\"%s\"][\"value\"].as<std::string>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tvarval=RR::stringToRRArray(value);\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"double\"){\n")
                    file1.write("\t\t\t\t\t\tdouble value = node[\"%s\"][\"value\"].as<double>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"int32\"){\n")
                    file1.write("\t\t\t\t\t\tint value = node[\"%s\"][\"value\"].as<int>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"uint32\"){\n")
                    file1.write("\t\t\t\t\t\tuint32_t value = node[\"%s\"][\"value\"].as<uint32_t>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"double[]\"){\n")
                    file1.write(
                        "\t\t\t\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<double>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"int32[]\"){\n")
                    file1.write(
                        "\t\t\t\t\t\tRR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<int>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tif(type==\"uint32[]\"){\n")
                    file1.write(
                        "\t\t\t\t\t\tRR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<uint32_t>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t\t}\n")

                    # file1.write("\t\t\t\t\tRRValuePtr my_array = AllocateEmptyRRArray<double>(node[name].size());\n")
                    # file1.write("\t\t\t\t\tfor (int i = 0; i < node[name].size(); i++) {\n")
                    # file1.write("\t\t\t\t\t\tmy_array->at(i) = node[name][i].as<double>();\n")
                    # file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tvars->insert(std::make_pair(name,varval));\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\trhs->%s = vars;\n" % (f[2]))
                    file1.write("\t\t\t}\n")

                elif (f[1] == "varvalue"):
                    file1.write("\t\t\tif(node[\"%s\"]){\n" % (f[2]))

                    file1.write("\t\t\t\tstd::string type = node[\"%s\"][\"type\"].as<std::string>();\n" % (f[2]))
                    file1.write("\t\t\t\tRR::RRValuePtr varval;\n")
                    file1.write("\t\t\t\tif(type==\"string\"){\n")
                    file1.write("\t\t\t\t\tstd::string value = node[\"%s\"][\"value\"].as<std::string>();\n" % (f[2]))
                    file1.write("\t\t\t\t\tvarval =RR::stringToRRArray(value);\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"double\"){\n")
                    file1.write("\t\t\t\t\tdouble value = node[\"%s\"][\"value\"].as<double>();\n" % (f[2]))
                    file1.write("\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"int32\"){\n")
                    file1.write("\t\t\t\t\tint value= node[\"%s\"][\"value\"].as<int>();\n" % (f[2]))
                    file1.write("\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"uint32\"){\n")
                    file1.write("\t\t\t\t\tuint32_t value= node[\"%s\"][\"value\"].as<uint32_t>();\n" % (f[2]))
                    file1.write("\t\t\t\t\tvarval=RR::ScalarToRRArray(value);\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"double[]\"){\n")
                    file1.write(
                        "\t\t\t\t\tRRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<double>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"int32[]\"){\n")
                    file1.write(
                        "\t\t\t\t\tRR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<int>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\tif(type==\"uint32[]\"){\n")
                    file1.write(
                        "\t\t\t\t\tRR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node[\"%s\"][\"value\"].size());\n" % (f[2]))
                    file1.write("\t\t\t\t\tfor (int i = 0; i < node[\"%s\"][\"value\"].size(); i++) {\n" % (f[2]))
                    file1.write("\t\t\t\t\t\tmy_array->at(i) = node[\"%s\"][\"value\"][i].as<uint32_t>();\n" % (f[2]))
                    file1.write("\t\t\t\t\t}\n")
                    file1.write("\t\t\t\t\tvarval=my_array;\n")
                    file1.write("\t\t\t\t}\n")
                    file1.write("\t\t\t\trhs->%s=varval;\n" % (f[2]))

                    file1.write("\t\t\t}\n")
                else:

                    if (qualifiedname not in error_names):
                        error_names.append(qualifiedname)
        file1.write("\t\t\treturn true;\n")
        file1.write("\t\t}\n")
        file1.write("\t};\n\n\n")

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

testfile.write("}\n\n")
testfile.write("int main(int ac, char** av)\n{\n")
testfile.write("return 0;\n}\n")

print(error_names)
