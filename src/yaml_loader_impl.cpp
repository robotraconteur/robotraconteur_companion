#include "RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h"
namespace YAML {
	Node convert<com::robotraconteur::actuator::ActuatorStatePtr>::encode(const com::robotraconteur::actuator::ActuatorStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::actuator::ActuatorStatePtr>::decode(const Node& node, com::robotraconteur::actuator::ActuatorStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::actuator::ActuatorState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->actuator_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"actuator_state_flags",true);
		rhs->actuator_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"actuator_command",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::actuator::ActuatorInfoPtr>::encode(const com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::actuator::ActuatorInfoPtr>::decode(const Node& node, com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::actuator::ActuatorInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->actuator_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode>(node,"actuator_type",true);
		rhs->command_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"command_units",true);
		rhs->command_data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"command_data_type",true);
		rhs->command_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command_resolution",true,true,0);
		rhs->analog_output = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"analog_output",true);
		rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::bignum::BigNumPtr>::encode(const com::robotraconteur::bignum::BigNumPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::bignum::BigNumPtr>::decode(const Node& node, com::robotraconteur::bignum::BigNumPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigNum); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::bignum::UnsignedBigNumPtr>::encode(const com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::bignum::UnsignedBigNumPtr>::decode(const Node& node, com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::bignum::UnsignedBigNum); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::bignum::BigFloatPtr>::encode(const com::robotraconteur::bignum::BigFloatPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::bignum::BigFloatPtr>::decode(const Node& node, com::robotraconteur::bignum::BigFloatPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigFloat); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->num = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"num",true);
		rhs->den = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"den",true);
		rhs->radix = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"radix",true);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBA>::encode(const com::robotraconteur::color::ColorRGBA& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBA>::decode(const Node& node, com::robotraconteur::color::ColorRGBA& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBAf>::encode(const com::robotraconteur::color::ColorRGBAf& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBAf>::decode(const Node& node, com::robotraconteur::color::ColorRGBAf& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"b",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBAu>::encode(const com::robotraconteur::color::ColorRGBAu& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBAu>::decode(const Node& node, com::robotraconteur::color::ColorRGBAu& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBAh>::encode(const com::robotraconteur::color::ColorRGBAh& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBAh>::decode(const Node& node, com::robotraconteur::color::ColorRGBAh& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"b",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGB>::encode(const com::robotraconteur::color::ColorRGB& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGB>::decode(const Node& node, com::robotraconteur::color::ColorRGB& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBf>::encode(const com::robotraconteur::color::ColorRGBf& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBf>::decode(const Node& node, com::robotraconteur::color::ColorRGBf& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"b",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBu>::encode(const com::robotraconteur::color::ColorRGBu& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBu>::decode(const Node& node, com::robotraconteur::color::ColorRGBu& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
		return true;
	}
	Node convert<com::robotraconteur::color::ColorRGBh>::encode(const com::robotraconteur::color::ColorRGBh& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::color::ColorRGBh>::decode(const Node& node, com::robotraconteur::color::ColorRGBh& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"b",false);
		return true;
	}
	Node convert<com::robotraconteur::datatype::DataTypePtr>::encode(const com::robotraconteur::datatype::DataTypePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::datatype::DataTypePtr>::decode(const Node& node, com::robotraconteur::datatype::DataTypePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::datatype::DataType); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"name",true);
		rhs->type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::DataTypeCode::DataTypeCode>(node,"type_code",true);
		rhs->type_string = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"type_string",true);
		rhs->array_type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode>(node,"array_type_code",true);
		rhs->array_var_len = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"array_var_len",true);
		rhs->array_len = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"array_len",true,true,0);
		rhs->container_type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode>(node,"container_type_code",true);
		return true;
	}
	Node convert<com::robotraconteur::datetime::TimeSpec3>::encode(const com::robotraconteur::datetime::TimeSpec3& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::datetime::TimeSpec3>::decode(const Node& node, com::robotraconteur::datetime::TimeSpec3& rhs){
		rhs.s.microseconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int64_t>(node,"microseconds",false);
		return true;
	}
	Node convert<com::robotraconteur::datetime::DateTimeLocalPtr>::encode(const com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::datetime::DateTimeLocalPtr>::decode(const Node& node, com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::datetime::DateTimeLocal); // NOLINT(cppcoreguidelines-owning-memory)
		// TODO: parse field ClockInfo clock_info
		rhs->seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int64_t>(node,"seconds",true);
		rhs->nanoseconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"nanoseconds",true);
		rhs->utc_offset_seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"utc_offset_seconds",true);
		rhs->timezone_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"timezone_name",true);
		return true;
	}
	Node convert<com::robotraconteur::datetime::clock::ClockDeviceInfoPtr>::encode(const com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::datetime::clock::ClockDeviceInfoPtr>::decode(const Node& node, com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::datetime::clock::ClockDeviceInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->clock_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode>(node,"clock_type",true);
		rhs->timezone_utc_offset_seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"timezone_utc_offset_seconds",true);
		rhs->timezone_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"timezone_name",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceOptionPtr>::encode(const com::robotraconteur::device::DeviceOptionPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceOptionPtr>::decode(const Node& node, com::robotraconteur::device::DeviceOptionPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceOption); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->option_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"option_identifier",true);
		rhs->suboptions = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceSubOptionPtr>(node,"suboptions",true);
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceSubOptionPtr>::encode(const com::robotraconteur::device::DeviceSubOptionPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceSubOptionPtr>::decode(const Node& node, com::robotraconteur::device::DeviceSubOptionPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubOption); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->suboption_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"suboption_name",true);
		rhs->suboption_level = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"suboption_level",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceCapabilityPtr>::encode(const com::robotraconteur::device::DeviceCapabilityPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceCapabilityPtr>::decode(const Node& node, com::robotraconteur::device::DeviceCapabilityPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceCapability); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->capability_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"capability_identifier",true);
		rhs->subcapabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceSubCapabilityPtr>(node,"subcapabilities",true);
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceSubCapabilityPtr>::encode(const com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceSubCapabilityPtr>::decode(const Node& node, com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubCapability); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->subcapability_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"subcapability_name",true);
		rhs->subcapability_level = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"subcapability_level",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceClassPtr>::encode(const com::robotraconteur::device::DeviceClassPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceClassPtr>::decode(const Node& node, com::robotraconteur::device::DeviceClassPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceClass); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->class_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"class_identifier",true);
		rhs->subclasses = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"subclasses",true);
		return true;
	}
	Node convert<com::robotraconteur::device::DeviceInfoPtr>::encode(const com::robotraconteur::device::DeviceInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::DeviceInfoPtr>::decode(const Node& node, com::robotraconteur::device::DeviceInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"device",true);
		rhs->parent_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_device",true);
		rhs->manufacturer = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"manufacturer",true);
		rhs->model = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"model",true);
		rhs->options = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceOptionPtr>(node,"options",true);
		rhs->capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceCapabilityPtr>(node,"capabilities",true);
		rhs->serial_number = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"serial_number",true);
		rhs->device_classes = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceClassPtr>(node,"device_classes",true);
		rhs->user_description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"user_description",true);
		rhs->description_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"description_resource",true);
		rhs->implemented_types = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"implemented_types",true);
		rhs->device_origin_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"device_origin_pose",true);
		rhs->associated_devices = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_string<com::robotraconteur::identifier::IdentifierPtr>(node,"associated_devices",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::device::isoch::IsochInfoPtr>::encode(const com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::device::isoch::IsochInfoPtr>::decode(const Node& node, com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::device::isoch::IsochInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->update_rate = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"update_rate",true);
		// TODO: parse field com.robotraconteur.datetime.TimeSpec2 isoch_epoch
		rhs->max_downsample = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"max_downsample",true);
		return true;
	}
	Node convert<com::robotraconteur::eventlog::EventLogTypePtr>::encode(const com::robotraconteur::eventlog::EventLogTypePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::eventlog::EventLogTypePtr>::decode(const Node& node, com::robotraconteur::eventlog::EventLogTypePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogType); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->event_category = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"event_category",true);
		rhs->event_type = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"event_type",true);
		return true;
	}
	Node convert<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>::encode(const com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>::decode(const Node& node, com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessageHeader); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::eventlog::EventLogTypePtr>(node,"type",true);
		rhs->level = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::eventlog::EventLogLevel::EventLogLevel>(node,"level",true);
		rhs->source_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"source_device",true);
		rhs->source_component = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_component",true);
		rhs->source_object = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_object",true);
		rhs->message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"message_number",true);
		// TODO: parse field com.robotraconteur.datetime.DateTimeUTC timestamp
		return true;
	}
	Node convert<com::robotraconteur::eventlog::EventLogMessagePtr>::encode(const com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::eventlog::EventLogMessagePtr>::decode(const Node& node, com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessage); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>(node,"header",true);
		rhs->title = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"title",true);
		rhs->message = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"message",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::eventlog::EventLogInfoPtr>::encode(const com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::eventlog::EventLogInfoPtr>::decode(const Node& node, com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->logged_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"logged_device",true);
		rhs->min_message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"min_message_number",true);
		rhs->max_message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"max_message_number",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::fiducial::FiducialPtr>::encode(const com::robotraconteur::fiducial::FiducialPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::FiducialPtr>::decode(const Node& node, com::robotraconteur::fiducial::FiducialPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::Fiducial); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
		rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
		rhs->fiducial_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"fiducial_pose",true);
		rhs->fiducial_scale = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"fiducial_scale",true);
		rhs->foreground_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"foreground_color",true);
		rhs->background_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"background_color",true);
		return true;
	}
	Node convert<com::robotraconteur::fiducial::FiducialInfoPtr>::encode(const com::robotraconteur::fiducial::FiducialInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::FiducialInfoPtr>::decode(const Node& node, com::robotraconteur::fiducial::FiducialInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
		rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
		rhs->fiducial_marker_range = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker_range",true);
		rhs->default_size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"default_size",true);
		rhs->default_foreground_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"default_foreground_color",true);
		rhs->default_background_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"default_background_color",true);
		rhs->marker_template = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::CompressedImagePtr>(node,"marker_template",true);
		rhs->marker_template_centroid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"marker_template_centroid",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::fiducial::RecognizedFiducialPtr>::encode(const com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::RecognizedFiducialPtr>::decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::RecognizedFiducial); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
		rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>(node,"pose",true);
		rhs->confidence = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"confidence",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::fiducial::RecognizedFiducialsPtr>::encode(const com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::RecognizedFiducialsPtr>::decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::RecognizedFiducials); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->recognized_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::RecognizedFiducialPtr>(node,"recognized_fiducials",true);
		// TODO: parse field varvalue source_data
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::fiducial::FiducialSensorInfoPtr>::encode(const com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::FiducialSensorInfoPtr>::decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialSensorInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->range = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"range",true);
		rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
		rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
		rhs->fiducial_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialInfoPtr>(node,"fiducial_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::fiducial::FiducialSensorDataPtr>::encode(const com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::fiducial::FiducialSensorDataPtr>::decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"sensor_data",true);
		rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::fiducial::RecognizedFiducialsPtr>(node,"fiducials",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Vector2>::encode(const com::robotraconteur::geometry::Vector2& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Vector2>::decode(const Node& node, com::robotraconteur::geometry::Vector2& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Vector3>::encode(const com::robotraconteur::geometry::Vector3& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Vector3>::decode(const Node& node, com::robotraconteur::geometry::Vector3& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Vector6>::encode(const com::robotraconteur::geometry::Vector6& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Vector6>::decode(const Node& node, com::robotraconteur::geometry::Vector6& rhs){
		rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"alpha",false);
		rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"beta",false);
		rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"gamma",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Point2D>::encode(const com::robotraconteur::geometry::Point2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Point2D>::decode(const Node& node, com::robotraconteur::geometry::Point2D& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Point>::encode(const com::robotraconteur::geometry::Point& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Point>::decode(const Node& node, com::robotraconteur::geometry::Point& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Size2D>::encode(const com::robotraconteur::geometry::Size2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Size2D>::decode(const Node& node, com::robotraconteur::geometry::Size2D& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Size>::encode(const com::robotraconteur::geometry::Size& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Size>::decode(const Node& node, com::robotraconteur::geometry::Size& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",false);
		rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"depth",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Rect>::encode(const com::robotraconteur::geometry::Rect& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Rect>::decode(const Node& node, com::robotraconteur::geometry::Rect& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Box>::encode(const com::robotraconteur::geometry::Box& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Box>::decode(const Node& node, com::robotraconteur::geometry::Box& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Quaternion>::encode(const com::robotraconteur::geometry::Quaternion& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Quaternion>::decode(const Node& node, com::robotraconteur::geometry::Quaternion& rhs){
		rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"w",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Plane>::encode(const com::robotraconteur::geometry::Plane& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Plane>::decode(const Node& node, com::robotraconteur::geometry::Plane& rhs){
		rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"normal",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Transform>::encode(const com::robotraconteur::geometry::Transform& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Transform>::decode(const Node& node, com::robotraconteur::geometry::Transform& rhs){
		rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Quaternion>(node,"rotation",false);
		rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"translation",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Pose>::encode(const com::robotraconteur::geometry::Pose& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Pose>::decode(const Node& node, com::robotraconteur::geometry::Pose& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Quaternion>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Pose2D>::encode(const com::robotraconteur::geometry::Pose2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Pose2D>::decode(const Node& node, com::robotraconteur::geometry::Pose2D& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::SpatialVelocity>::encode(const com::robotraconteur::geometry::SpatialVelocity& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::SpatialVelocity>::decode(const Node& node, com::robotraconteur::geometry::SpatialVelocity& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::SpatialAcceleration>::encode(const com::robotraconteur::geometry::SpatialAcceleration& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::SpatialAcceleration>::decode(const Node& node, com::robotraconteur::geometry::SpatialAcceleration& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::Wrench>::encode(const com::robotraconteur::geometry::Wrench& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::Wrench>::decode(const Node& node, com::robotraconteur::geometry::Wrench& rhs){
		rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"torque",false);
		rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"force",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::SpatialInertia>::encode(const com::robotraconteur::geometry::SpatialInertia& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::SpatialInertia>::decode(const Node& node, com::robotraconteur::geometry::SpatialInertia& rhs){
		rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"m",false);
		rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"com",false);
		rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixx",false);
		rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixy",false);
		rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixz",false);
		rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"iyy",false);
		rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"iyz",false);
		rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"izz",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedTransformPtr>::encode(const com::robotraconteur::geometry::NamedTransformPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedTransformPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedTransformPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedTransform); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
		rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Transform>(node,"transform",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedPosePtr>::encode(const com::robotraconteur::geometry::NamedPosePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedPosePtr>::decode(const Node& node, com::robotraconteur::geometry::NamedPosePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPose); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::PoseWithCovariancePtr>::encode(const com::robotraconteur::geometry::PoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::PoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometry::PoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::PoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>::encode(const com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedPose2DPtr>::encode(const com::robotraconteur::geometry::NamedPose2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedPose2DPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedPose2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPose2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose2D>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedSpatialVelocityPtr>::encode(const com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedSpatialVelocityPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialVelocity); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"velocity",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedSpatialAccelerationPtr>::encode(const com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedSpatialAccelerationPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialAcceleration); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"acceleration",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedWrenchPtr>::encode(const com::robotraconteur::geometry::NamedWrenchPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedWrenchPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedWrenchPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedWrench); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Wrench>(node,"wrench",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::NamedSpatialInertiaPtr>::encode(const com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::NamedSpatialInertiaPtr>::decode(const Node& node, com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialInertia); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::BoundingBox2DPtr>::encode(const com::robotraconteur::geometry::BoundingBox2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::BoundingBox2DPtr>::decode(const Node& node, com::robotraconteur::geometry::BoundingBox2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::BoundingBox2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPose2DPtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::BoundingBoxPtr>::encode(const com::robotraconteur::geometry::BoundingBoxPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::BoundingBoxPtr>::decode(const Node& node, com::robotraconteur::geometry::BoundingBoxPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::BoundingBox); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::MeshTriangle>::encode(const com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::MeshTriangle>::decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
		rhs.s.v1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v1",false);
		rhs.s.v2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v2",false);
		rhs.s.v3 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v3",false);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::BoxPtr>::encode(const com::robotraconteur::geometry::shapes::BoxPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::BoxPtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::BoxPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Box); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",true);
		rhs->y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",true);
		rhs->z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::SpherePtr>::encode(const com::robotraconteur::geometry::shapes::SpherePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::SpherePtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::SpherePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Sphere); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::CylinderPtr>::encode(const com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::CylinderPtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cylinder); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
		rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::ConePtr>::encode(const com::robotraconteur::geometry::shapes::ConePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::ConePtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::ConePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cone); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
		rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::CapsulePtr>::encode(const com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::CapsulePtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Capsule); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
		rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::PlanePtr>::encode(const com::robotraconteur::geometry::shapes::PlanePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::PlanePtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::PlanePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Plane); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",true);
		rhs->b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",true);
		rhs->c = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"c",true);
		rhs->d = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"d",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::MeshTexturePtr>::encode(const com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::MeshTexturePtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::MeshTexture); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::CompressedImagePtr>(node,"image",true);
		rhs->uvs = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector2>(node,"uvs",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::MeshPtr>::encode(const com::robotraconteur::geometry::shapes::MeshPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::MeshPtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::MeshPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Mesh); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->triangles = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::shapes::MeshTriangle>(node,"triangles",true,true,0);
		rhs->vertices = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"vertices",true,true,0);
		rhs->normals = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"normals",true,true,0);
		rhs->colors = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::color::ColorRGB>(node,"colors",true,true,0);
		rhs->textures = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::MeshTexturePtr>(node,"textures",true);
		rhs->mesh_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::geometry::shapes::MeshType::MeshType>(node,"mesh_type",true);
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::MaterialPtr>::encode(const com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::MaterialPtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Material); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->base_color_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"base_color_factor",true);
		rhs->metallic_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"metallic_factor",true);
		rhs->roughness_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"roughness_factor",true);
		rhs->emissive_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"emissive_factor",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::geometry::shapes::ShapeObjectPtr>::encode(const com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometry::shapes::ShapeObjectPtr>::decode(const Node& node, com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::ShapeObject); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"name",true);
		// TODO: parse field varvalue{list} shapes
		// TODO: parse field com.robotraconteur.geometry.Pose{list} shape_poses
		rhs->shape_materials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::MaterialPtr>(node,"shape_materials",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
		rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Vector2>::encode(const com::robotraconteur::geometryf::Vector2& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Vector2>::decode(const Node& node, com::robotraconteur::geometryf::Vector2& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Vector3>::encode(const com::robotraconteur::geometryf::Vector3& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Vector3>::decode(const Node& node, com::robotraconteur::geometryf::Vector3& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Vector6>::encode(const com::robotraconteur::geometryf::Vector6& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Vector6>::decode(const Node& node, com::robotraconteur::geometryf::Vector6& rhs){
		rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"alpha",false);
		rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"beta",false);
		rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"gamma",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Point2D>::encode(const com::robotraconteur::geometryf::Point2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Point2D>::decode(const Node& node, com::robotraconteur::geometryf::Point2D& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Point>::encode(const com::robotraconteur::geometryf::Point& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Point>::decode(const Node& node, com::robotraconteur::geometryf::Point& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Size2D>::encode(const com::robotraconteur::geometryf::Size2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Size2D>::decode(const Node& node, com::robotraconteur::geometryf::Size2D& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"height",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Size>::encode(const com::robotraconteur::geometryf::Size& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Size>::decode(const Node& node, com::robotraconteur::geometryf::Size& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"height",false);
		rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"depth",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Rect>::encode(const com::robotraconteur::geometryf::Rect& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Rect>::decode(const Node& node, com::robotraconteur::geometryf::Rect& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point2D>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size2D>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Box>::encode(const com::robotraconteur::geometryf::Box& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Box>::decode(const Node& node, com::robotraconteur::geometryf::Box& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Quaternion>::encode(const com::robotraconteur::geometryf::Quaternion& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Quaternion>::decode(const Node& node, com::robotraconteur::geometryf::Quaternion& rhs){
		rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"w",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Plane>::encode(const com::robotraconteur::geometryf::Plane& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Plane>::decode(const Node& node, com::robotraconteur::geometryf::Plane& rhs){
		rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"normal",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Transform>::encode(const com::robotraconteur::geometryf::Transform& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Transform>::decode(const Node& node, com::robotraconteur::geometryf::Transform& rhs){
		rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Quaternion>(node,"rotation",false);
		rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"translation",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Pose>::encode(const com::robotraconteur::geometryf::Pose& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Pose>::decode(const Node& node, com::robotraconteur::geometryf::Pose& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Quaternion>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Pose2D>::encode(const com::robotraconteur::geometryf::Pose2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Pose2D>::decode(const Node& node, com::robotraconteur::geometryf::Pose2D& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point2D>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::SpatialVelocity>::encode(const com::robotraconteur::geometryf::SpatialVelocity& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::SpatialVelocity>::decode(const Node& node, com::robotraconteur::geometryf::SpatialVelocity& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::SpatialAcceleration>::encode(const com::robotraconteur::geometryf::SpatialAcceleration& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::SpatialAcceleration>::decode(const Node& node, com::robotraconteur::geometryf::SpatialAcceleration& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::Wrench>::encode(const com::robotraconteur::geometryf::Wrench& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::Wrench>::decode(const Node& node, com::robotraconteur::geometryf::Wrench& rhs){
		rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"torque",false);
		rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"force",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::SpatialInertia>::encode(const com::robotraconteur::geometryf::SpatialInertia& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::SpatialInertia>::decode(const Node& node, com::robotraconteur::geometryf::SpatialInertia& rhs){
		rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"m",false);
		rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"com",false);
		rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixx",false);
		rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixy",false);
		rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixz",false);
		rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"iyy",false);
		rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"iyz",false);
		rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"izz",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedTransformPtr>::encode(const com::robotraconteur::geometryf::NamedTransformPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedTransformPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedTransformPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedTransform); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
		rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Transform>(node,"transform",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedPosePtr>::encode(const com::robotraconteur::geometryf::NamedPosePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedPosePtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedPosePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPose); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::PoseWithCovariancePtr>::encode(const com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::PoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::PoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<float>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedPoseWithCovariancePtr>::encode(const com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedPoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPosePtr>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<float>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedPose2DPtr>::encode(const com::robotraconteur::geometryf::NamedPose2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedPose2DPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedPose2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPose2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose2D>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedSpatialVelocityPtr>::encode(const com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedSpatialVelocityPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialVelocity); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialVelocity>(node,"velocity",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedSpatialAccelerationPtr>::encode(const com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedSpatialAccelerationPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialAcceleration); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialAcceleration>(node,"acceleration",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedWrenchPtr>::encode(const com::robotraconteur::geometryf::NamedWrenchPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedWrenchPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedWrenchPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedWrench); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Wrench>(node,"wrench",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::NamedSpatialInertiaPtr>::encode(const com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::NamedSpatialInertiaPtr>::decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialInertia); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialInertia>(node,"inertia",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::BoundingBox2DPtr>::encode(const com::robotraconteur::geometryf::BoundingBox2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::BoundingBox2DPtr>::decode(const Node& node, com::robotraconteur::geometryf::BoundingBox2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::BoundingBox2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPose2DPtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size2D>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryf::BoundingBoxPtr>::encode(const com::robotraconteur::geometryf::BoundingBoxPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryf::BoundingBoxPtr>::decode(const Node& node, com::robotraconteur::geometryf::BoundingBoxPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryf::BoundingBox); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPosePtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Vector2>::encode(const com::robotraconteur::geometryi::Vector2& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Vector2>::decode(const Node& node, com::robotraconteur::geometryi::Vector2& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Vector3>::encode(const com::robotraconteur::geometryi::Vector3& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Vector3>::decode(const Node& node, com::robotraconteur::geometryi::Vector3& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Vector6>::encode(const com::robotraconteur::geometryi::Vector6& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Vector6>::decode(const Node& node, com::robotraconteur::geometryi::Vector6& rhs){
		rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"alpha",false);
		rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"beta",false);
		rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"gamma",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Point2D>::encode(const com::robotraconteur::geometryi::Point2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Point2D>::decode(const Node& node, com::robotraconteur::geometryi::Point2D& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Point>::encode(const com::robotraconteur::geometryi::Point& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Point>::decode(const Node& node, com::robotraconteur::geometryi::Point& rhs){
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Size2D>::encode(const com::robotraconteur::geometryi::Size2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Size2D>::decode(const Node& node, com::robotraconteur::geometryi::Size2D& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"height",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Size>::encode(const com::robotraconteur::geometryi::Size& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Size>::decode(const Node& node, com::robotraconteur::geometryi::Size& rhs){
		rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"width",false);
		rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"height",false);
		rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"depth",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Rect>::encode(const com::robotraconteur::geometryi::Rect& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Rect>::decode(const Node& node, com::robotraconteur::geometryi::Rect& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point2D>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Box>::encode(const com::robotraconteur::geometryi::Box& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Box>::decode(const Node& node, com::robotraconteur::geometryi::Box& rhs){
		rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point>(node,"origin",false);
		rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size>(node,"size",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Quaternion>::encode(const com::robotraconteur::geometryi::Quaternion& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Quaternion>::decode(const Node& node, com::robotraconteur::geometryi::Quaternion& rhs){
		rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"w",false);
		rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
		rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
		rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Plane>::encode(const com::robotraconteur::geometryi::Plane& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Plane>::decode(const Node& node, com::robotraconteur::geometryi::Plane& rhs){
		rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"normal",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Transform>::encode(const com::robotraconteur::geometryi::Transform& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Transform>::decode(const Node& node, com::robotraconteur::geometryi::Transform& rhs){
		rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Quaternion>(node,"rotation",false);
		rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"translation",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Pose>::encode(const com::robotraconteur::geometryi::Pose& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Pose>::decode(const Node& node, com::robotraconteur::geometryi::Pose& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Quaternion>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Pose2D>::encode(const com::robotraconteur::geometryi::Pose2D& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Pose2D>::decode(const Node& node, com::robotraconteur::geometryi::Pose2D& rhs){
		rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"orientation",false);
		rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point2D>(node,"position",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::SpatialVelocity>::encode(const com::robotraconteur::geometryi::SpatialVelocity& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::SpatialVelocity>::decode(const Node& node, com::robotraconteur::geometryi::SpatialVelocity& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::SpatialAcceleration>::encode(const com::robotraconteur::geometryi::SpatialAcceleration& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::SpatialAcceleration>::decode(const Node& node, com::robotraconteur::geometryi::SpatialAcceleration& rhs){
		rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"angular",false);
		rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"linear",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::Wrench>::encode(const com::robotraconteur::geometryi::Wrench& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::Wrench>::decode(const Node& node, com::robotraconteur::geometryi::Wrench& rhs){
		rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"torque",false);
		rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"force",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::SpatialInertia>::encode(const com::robotraconteur::geometryi::SpatialInertia& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::SpatialInertia>::decode(const Node& node, com::robotraconteur::geometryi::SpatialInertia& rhs){
		rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"m",false);
		rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"com",false);
		rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixx",false);
		rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixy",false);
		rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixz",false);
		rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"iyy",false);
		rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"iyz",false);
		rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"izz",false);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedTransformPtr>::encode(const com::robotraconteur::geometryi::NamedTransformPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedTransformPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedTransformPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedTransform); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
		rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Transform>(node,"transform",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedPosePtr>::encode(const com::robotraconteur::geometryi::NamedPosePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedPosePtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedPosePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::PoseWithCovariancePtr>::encode(const com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::PoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::PoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<int32_t>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedPoseWithCovariancePtr>::encode(const com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedPoseWithCovariancePtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPosePtr>(node,"pose",true);
		rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<int32_t>(node,"covariance",true,6,6);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedPose2DPtr>::encode(const com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedPose2DPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose2D>(node,"pose",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedSpatialVelocityPtr>::encode(const com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedSpatialVelocityPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialVelocity); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialVelocity>(node,"velocity",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedSpatialAccelerationPtr>::encode(const com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedSpatialAccelerationPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialAcceleration); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialAcceleration>(node,"acceleration",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedWrenchPtr>::encode(const com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedWrenchPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedWrench); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Wrench>(node,"wrench",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::NamedSpatialInertiaPtr>::encode(const com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::NamedSpatialInertiaPtr>::decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialInertia); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialInertia>(node,"inertia",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::BoundingBox2DPtr>::encode(const com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::BoundingBox2DPtr>::decode(const Node& node, com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox2D); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPose2DPtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::geometryi::BoundingBoxPtr>::encode(const com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::geometryi::BoundingBoxPtr>::decode(const Node& node, com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPosePtr>(node,"center",true);
		rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size>(node,"size",true);
		return true;
	}
	Node convert<com::robotraconteur::gps::GpsStatusPtr>::encode(const com::robotraconteur::gps::GpsStatusPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::gps::GpsStatusPtr>::decode(const Node& node, com::robotraconteur::gps::GpsStatusPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsStatus); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->satellites_used = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"satellites_used",true);
		rhs->satellite_used_prn = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_used_prn",true,true,0);
		rhs->satellites_visible = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"satellites_visible",true);
		rhs->satellite_visible_prn = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_prn",true,true,0);
		rhs->satellite_visible_z = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_z",true,true,0);
		rhs->satellite_visible_azimuth = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_azimuth",true,true,0);
		rhs->satellite_visible_snr = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_snr",true,true,0);
		rhs->status_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::gps::GpsMeasurementStatusCode::GpsMeasurementStatusCode>(node,"status_code",true);
		rhs->motion_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"motion_source_flags",true);
		rhs->orientation_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"orientation_source_flags",true);
		rhs->position_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"position_source_flags",true);
		return true;
	}
	Node convert<com::robotraconteur::gps::GpsStatePtr>::encode(const com::robotraconteur::gps::GpsStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::gps::GpsStatePtr>::decode(const Node& node, com::robotraconteur::gps::GpsStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->status = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::gps::GpsStatusPtr>(node,"status",true);
		// TODO: parse field com.robotraconteur.datetime.DateTimeUTC time
		rhs->latitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"latitude_deg",true);
		rhs->longitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"longitude_deg",true);
		rhs->altitude = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"altitude",true);
		rhs->track_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"track_deg",true);
		rhs->speed = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"speed",true);
		rhs->climb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"climb",true);
		rhs->pitch = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"pitch",true);
		rhs->roll = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"roll",true);
		rhs->dip = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"dip",true);
		rhs->gdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"gdop",true);
		rhs->pdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"pdop",true);
		rhs->hdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"hdop",true);
		rhs->vdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vdop",true);
		rhs->tdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"tdop",true);
		rhs->err = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err",true);
		rhs->err_horz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_horz",true);
		rhs->err_track = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_track",true);
		rhs->err_speed = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_speed",true);
		rhs->err_climb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_climb",true);
		rhs->err_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_time",true);
		rhs->err_pitch = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_pitch",true);
		rhs->err_roll = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_roll",true);
		rhs->err_dip = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_dip",true);
		rhs->position_covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"position_covariance",true,3,3);
		rhs->position_covariance_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::gps::GpsCovarianceTypeCode::GpsCovarianceTypeCode>(node,"position_covariance_type",true);
		return true;
	}
	Node convert<com::robotraconteur::hid::joystick::JoystickInfoPtr>::encode(const com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::hid::joystick::JoystickInfoPtr>::decode(const Node& node, com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->id = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"id",true);
		rhs->axes_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"axes_count",true);
		rhs->button_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"button_count",true);
		rhs->hat_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"hat_count",true);
		rhs->joystick_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"joystick_capabilities",true);
		rhs->joystick_device_vendor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_vendor",true);
		rhs->joystick_device_product = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_product",true);
		rhs->joystick_device_version = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_version",true);
		rhs->joystick_uuid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::uuid::UUID>(node,"joystick_uuid",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::hid::joystick::JoystickStatePtr>::encode(const com::robotraconteur::hid::joystick::JoystickStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::hid::joystick::JoystickStatePtr>::decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->axes = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int16_t>(node,"axes",true,true,0);
		rhs->buttons = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"buttons",true,true,0);
		rhs->hats = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"hats",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::hid::joystick::GamepadStatePtr>::encode(const com::robotraconteur::hid::joystick::GamepadStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::hid::joystick::GamepadStatePtr>::decode(const Node& node, com::robotraconteur::hid::joystick::GamepadStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::GamepadState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->left_x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"left_x",true);
		rhs->left_y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"left_y",true);
		rhs->right_x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"right_x",true);
		rhs->right_y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"right_y",true);
		rhs->trigger_left = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"trigger_left",true);
		rhs->trigger_right = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"trigger_right",true);
		rhs->buttons = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"buttons",true);
		return true;
	}
	Node convert<com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr>::encode(const com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr>::decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickStateSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->joystick_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::hid::joystick::JoystickStatePtr>(node,"joystick_state",true);
		rhs->gamepad_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::hid::joystick::GamepadStatePtr>(node,"gamepad_state",true);
		return true;
	}
	Node convert<com::robotraconteur::image::PixelRGB>::encode(const com::robotraconteur::image::PixelRGB& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::PixelRGB>::decode(const Node& node, com::robotraconteur::image::PixelRGB& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
		return true;
	}
	Node convert<com::robotraconteur::image::PixelRGBA>::encode(const com::robotraconteur::image::PixelRGBA& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::PixelRGBA>::decode(const Node& node, com::robotraconteur::image::PixelRGBA& rhs){
		rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
		rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
		rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
		rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"a",false);
		return true;
	}
	Node convert<com::robotraconteur::image::PixelRGBFloatPacked>::encode(const com::robotraconteur::image::PixelRGBFloatPacked& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::PixelRGBFloatPacked>::decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPacked& rhs){
		rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"rgb",false);
		return true;
	}
	Node convert<com::robotraconteur::image::PixelRGBFloatPackedf>::encode(const com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::PixelRGBFloatPackedf>::decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
		rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"rgb",false);
		return true;
	}
	Node convert<com::robotraconteur::image::ImageInfoPtr>::encode(const com::robotraconteur::image::ImageInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::ImageInfoPtr>::decode(const Node& node, com::robotraconteur::image::ImageInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::ImageInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"height",true);
		rhs->width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"width",true);
		rhs->step = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"step",true);
		rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::image::ImageEncoding::ImageEncoding>(node,"encoding",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::image::FreeformImageInfoPtr>::encode(const com::robotraconteur::image::FreeformImageInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::FreeformImageInfoPtr>::decode(const Node& node, com::robotraconteur::image::FreeformImageInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImageInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
		rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::image::ImagePtr>::encode(const com::robotraconteur::image::ImagePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::ImagePtr>::decode(const Node& node, com::robotraconteur::image::ImagePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::Image); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::image::CompressedImagePtr>::encode(const com::robotraconteur::image::CompressedImagePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::CompressedImagePtr>::decode(const Node& node, com::robotraconteur::image::CompressedImagePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImage); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::image::FreeformImagePtr>::encode(const com::robotraconteur::image::FreeformImagePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::FreeformImagePtr>::decode(const Node& node, com::robotraconteur::image::FreeformImagePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImage); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::FreeformImageInfoPtr>(node,"image_info",true);
		// TODO: parse field varvalue data
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::image::ImagePartPtr>::encode(const com::robotraconteur::image::ImagePartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::ImagePartPtr>::decode(const Node& node, com::robotraconteur::image::ImagePartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::ImagePart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		rhs->data_part = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data_part",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::image::CompressedImagePartPtr>::encode(const com::robotraconteur::image::CompressedImagePartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::CompressedImagePartPtr>::decode(const Node& node, com::robotraconteur::image::CompressedImagePartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImagePart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		rhs->data_part = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data_part",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::image::FreeformImagePartPtr>::encode(const com::robotraconteur::image::FreeformImagePartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::FreeformImagePartPtr>::decode(const Node& node, com::robotraconteur::image::FreeformImagePartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImagePart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::FreeformImageInfoPtr>(node,"image_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		// TODO: parse field varvalue data_part
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::image::ImageResourcePtr>::encode(const com::robotraconteur::image::ImageResourcePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::image::ImageResourcePtr>::decode(const Node& node, com::robotraconteur::image::ImageResourcePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::image::ImageResource); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"image_resource",true);
		return true;
	}
	Node convert<com::robotraconteur::imaging::CameraStatePtr>::encode(const com::robotraconteur::imaging::CameraStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imaging::CameraStatePtr>::decode(const Node& node, com::robotraconteur::imaging::CameraStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imaging::CameraState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"state_flags",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>::encode(const com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>::decode(const Node& node, com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->k1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k1",true);
		rhs->k2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k2",true);
		rhs->p1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p1",true);
		rhs->p2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p2",true);
		rhs->k3 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k3",true);
		return true;
	}
	Node convert<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>::encode(const com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>::decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraCalibration); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->image_size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"image_size",true);
		rhs->distortion_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>(node,"distortion_info",true);
		rhs->K = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"K",true,3,3);
		rhs->parent_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_device",true);
		rhs->camera_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"camera_pose",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>::encode(const com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>::decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->calibration = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>(node,"calibration",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr>::encode(const com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr>::decode(const Node& node, com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::MultiCameraInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->camera_info_all = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_int32<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>(node,"camera_info_all",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::imu::ImuStatePtr>::encode(const com::robotraconteur::imu::ImuStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::imu::ImuStatePtr>::decode(const Node& node, com::robotraconteur::imu::ImuStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::imu::ImuState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->angular_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"angular_velocity",true);
		rhs->angular_velocity_covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"angular_velocity_covariance",true,3,3);
		rhs->linear_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"linear_acceleration",true);
		rhs->linear_acceleration_covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"linear_acceleration_covariance",true,3,3);
		rhs->orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Quaternion>(node,"orientation",true);
		rhs->orientation_covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"orientation_covariance",true,3,3);
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanInfoPtr>::encode(const com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanInfoPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_min",true);
		rhs->angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_max",true);
		rhs->angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_increment",true);
		rhs->angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"angle_count",true);
		rhs->vertical_angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_min",true);
		rhs->vertical_angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_max",true);
		rhs->vertical_angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_increment",true);
		rhs->vertical_angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"vertical_angle_count",true);
		rhs->time_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_increment",true);
		rhs->scan_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"scan_time",true);
		rhs->range_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_min",true);
		rhs->range_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_max",true);
		rhs->range_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_resolution",true);
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanPtr>::encode(const com::robotraconteur::laserscan::LaserScanPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScan); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfoPtr>(node,"scan_info",true);
		rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"ranges",true,true,0);
		rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"intensities",true,true,0);
		rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
		rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanInfofPtr>::encode(const com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanInfofPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfof); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_min",true);
		rhs->angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_max",true);
		rhs->angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_increment",true);
		rhs->angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"angle_count",true);
		rhs->vertical_angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_min",true);
		rhs->vertical_angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_max",true);
		rhs->vertical_angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_increment",true);
		rhs->vertical_angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"vertical_angle_count",true);
		rhs->time_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"time_increment",true);
		rhs->scan_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"scan_time",true);
		rhs->range_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_min",true);
		rhs->range_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_max",true);
		rhs->range_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_resolution",true);
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanfPtr>::encode(const com::robotraconteur::laserscan::LaserScanfPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanfPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanfPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanf); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scan_info",true);
		rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"ranges",true,true,0);
		rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"intensities",true,true,0);
		rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
		rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanPartPtr>::encode(const com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanPartPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfoPtr>(node,"scan_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"ranges",true,true,0);
		rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"intensities",true,true,0);
		rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
		rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::laserscan::LaserScanPartfPtr>::encode(const com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscan::LaserScanPartfPtr>::decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPartf); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scan_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"ranges",true,true,0);
		rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"intensities",true,true,0);
		rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
		rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::laserscanner::LaserScannerInfoPtr>::encode(const com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::laserscanner::LaserScannerInfoPtr>::decode(const Node& node, com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::laserscanner::LaserScannerInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->scanner_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scanner_info",true);
		rhs->scan_rate = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"scan_rate",true);
		rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::lighting::LightInfoPtr>::encode(const com::robotraconteur::lighting::LightInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::lighting::LightInfoPtr>::decode(const Node& node, com::robotraconteur::lighting::LightInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::lighting::LightInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->max_lumens = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"max_lumens",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr>::encode(const com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr>::decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionTemplate); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->object_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"object_identifier",true);
		rhs->object_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"object_class",true);
		rhs->object_shape = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::shapes::ShapeObjectPtr>(node,"object_shape",true);
		rhs->object_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"object_fiducials",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::objectrecognition::RecognizedObjectPtr>::encode(const com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::objectrecognition::RecognizedObjectPtr>::decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObject); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->recognized_object = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"recognized_object",true);
		rhs->recognized_object_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"recognized_object_class",true);
		rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>(node,"pose",true);
		rhs->confidence = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"confidence",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>::encode(const com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>::decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObjects); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->recognized_objects = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::objectrecognition::RecognizedObjectPtr>(node,"recognized_objects",true);
		// TODO: parse field varvalue source_data
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr>::encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr>::decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->range = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"range",true);
		rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
		rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
		rhs->object_template_identifiers = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::identifier::IdentifierPtr>(node,"object_template_identifiers",true);
		rhs->object_template_classes = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceClassPtr>(node,"object_template_classes",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr>::encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr>::decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"sensor_data",true);
		rhs->recognized_objects = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>(node,"recognized_objects",true);
		return true;
	}
	Node convert<com::robotraconteur::octree::OcTreeInfoPtr>::encode(const com::robotraconteur::octree::OcTreeInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::octree::OcTreeInfoPtr>::decode(const Node& node, com::robotraconteur::octree::OcTreeInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding>(node,"encoding",true);
		rhs->id = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"id",true);
		rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"resolution",true);
		return true;
	}
	Node convert<com::robotraconteur::octree::OcTreePtr>::encode(const com::robotraconteur::octree::OcTreePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::octree::OcTreePtr>::decode(const Node& node, com::robotraconteur::octree::OcTreePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTree); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->octree_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::octree::OcTreeInfoPtr>(node,"octree_info",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::octree::OcTreePartPtr>::encode(const com::robotraconteur::octree::OcTreePartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::octree::OcTreePartPtr>::decode(const Node& node, com::robotraconteur::octree::OcTreePartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreePart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->octree_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::octree::OcTreeInfoPtr>(node,"octree_info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
		rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::octree::OcTreeResourcePtr>::encode(const com::robotraconteur::octree::OcTreeResourcePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::octree::OcTreeResourcePtr>::decode(const Node& node, com::robotraconteur::octree::OcTreeResourcePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeResource); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->octree_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"octree_resource",true);
		return true;
	}
	Node convert<com::robotraconteur::param::ParameterInfoPtr>::encode(const com::robotraconteur::param::ParameterInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::param::ParameterInfoPtr>::decode(const Node& node, com::robotraconteur::param::ParameterInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::param::ParameterInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->parameter_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parameter_identifier",true);
		rhs->parameter_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"parameter_class",true);
		rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
		rhs->data_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"data_units",true);
		rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
		// TODO: parse field varvalue default_value
		// TODO: parse field varvalue min_value
		// TODO: parse field varvalue max_value
		// TODO: parse field varvalue{string} enum_values
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pid::PIDParamPtr>::encode(const com::robotraconteur::pid::PIDParamPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pid::PIDParamPtr>::decode(const Node& node, com::robotraconteur::pid::PIDParamPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pid::PIDParam); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->p = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p",true);
		rhs->i = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"i",true);
		rhs->d = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"d",true);
		rhs->imax = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"imax",true);
		rhs->imin = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"imin",true);
		rhs->cmd_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"cmd_max",true);
		rhs->cmd_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"cmd_min",true);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2Point>::encode(const com::robotraconteur::pointcloud::PointCloud2Point& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2Point>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Point& rhs){
		rhs.s.point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"point",false);
		rhs.s.intensity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"intensity",false);
		rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"normal",false);
		rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::image::PixelRGBFloatPacked>(node,"rgb",false);
		rhs.s.moment_invariants = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_na<double,3>(node,"moment_invariants");
		rhs.s.channel = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"channel",false);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2Pointf>::encode(const com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2Pointf>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
		rhs.s.point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"point",false);
		rhs.s.intensity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"intensity",false);
		rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"normal",false);
		rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::image::PixelRGBFloatPackedf>(node,"rgb",false);
		rhs.s.moment_invariants = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_na<float,3>(node,"moment_invariants");
		rhs.s.channel = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"channel",false);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloudPtr>::encode(const com::robotraconteur::pointcloud::PointCloudPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloudPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloudPartPtr>::encode(const com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloudPartPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
		rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloudfPtr>::encode(const com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloudfPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudf); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometryf::Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloudPartfPtr>::encode(const com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloudPartfPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPartf); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
		rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometryf::Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2Ptr>::encode(const com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2Ptr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2PartPtr>::encode(const com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2PartPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Part); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
		rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Point>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2fPtr>::encode(const com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2fPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2f); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Pointf>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::PointCloud2PartfPtr>::encode(const com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::PointCloud2PartfPtr>::decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Partf); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
		rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
		rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Pointf>(node,"points",true,true,0);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::FreeformPointCloudPtr>::encode(const com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::FreeformPointCloudPtr>::decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloud); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		// TODO: parse field varvalue points
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::FreeformPointCloudPartPtr>::encode(const com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::FreeformPointCloudPartPtr>::decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloudPart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
		rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
		rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
		rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
		// TODO: parse field varvalue points
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>::encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>::decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
		rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
		rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr>::encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr>::decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
		rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudfPtr>(node,"point_cloud",true);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr>::encode(const com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr>::decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudPartSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
		rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudPartfPtr>(node,"point_cloud",true);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr>::encode(const com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr>::decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2SensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
		rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2fPtr>(node,"point_cloud",true);
		return true;
	}
	Node convert<com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr>::encode(const com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr>::decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
		rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2PartfPtr>(node,"point_cloud",true);
		return true;
	}
	Node convert<com::robotraconteur::resource::ResourceIdentifierPtr>::encode(const com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::resource::ResourceIdentifierPtr>::decode(const Node& node, com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceIdentifier); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->bucket = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"bucket",true);
		rhs->key = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"key",true);
		return true;
	}
	Node convert<com::robotraconteur::resource::BucketInfoPtr>::encode(const com::robotraconteur::resource::BucketInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::resource::BucketInfoPtr>::decode(const Node& node, com::robotraconteur::resource::BucketInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::resource::BucketInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"identifier",true);
		rhs->keys = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"keys",true);
		rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::resource::ResourceInfoPtr>::encode(const com::robotraconteur::resource::ResourceInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::resource::ResourceInfoPtr>::decode(const Node& node, com::robotraconteur::resource::ResourceInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"identifier",true);
		rhs->key = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"key",true);
		// TODO: parse field com.robotraconteur.datetime.DateTimeUTC created
		// TODO: parse field com.robotraconteur.datetime.DateTimeUTC modified
		rhs->total_size = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"total_size",true);
		rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::resource::ResourcePtr>::encode(const com::robotraconteur::resource::ResourcePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::resource::ResourcePtr>::decode(const Node& node, com::robotraconteur::resource::ResourcePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::resource::Resource); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceInfoPtr>(node,"info",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::resource::ResourcePartPtr>::encode(const com::robotraconteur::resource::ResourcePartPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::resource::ResourcePartPtr>::decode(const Node& node, com::robotraconteur::resource::ResourcePartPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourcePart); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceInfoPtr>(node,"info",true);
		rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"data_offset",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::robotics::joints::JointLimitsPtr>::encode(const com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::joints::JointLimitsPtr>::decode(const Node& node, com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointLimits); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->lower = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"lower",true);
		rhs->upper = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"upper",true);
		rhs->home = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"home",true);
		rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"velocity",true);
		rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"acceleration",true);
		rhs->jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"jerk",true);
		rhs->effort = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"effort",true);
		rhs->reduced_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_velocity",true);
		rhs->reduced_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_acceleration",true);
		rhs->reduced_jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_jerk",true);
		rhs->reduced_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_effort",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::joints::JointInfoPtr>::encode(const com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::joints::JointInfoPtr>::decode(const Node& node, com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joint_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"joint_identifier",true);
		rhs->joint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointType::JointType>(node,"joint_type",true);
		rhs->joint_limits = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::joints::JointLimitsPtr>(node,"joint_limits",true);
		rhs->default_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"default_units",true);
		rhs->default_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"default_effort_units",true);
		rhs->passive = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"passive",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::payload::PayloadInfoPtr>::encode(const com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::payload::PayloadInfoPtr>::decode(const Node& node, com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::payload::PayloadInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
		rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>::encode(const com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>::decode(const Node& node, com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotKinChainInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->kin_chain_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"kin_chain_identifier",true);
		rhs->H = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"H",true,true,0);
		rhs->P = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"P",true,true,0);
		rhs->link_inertias = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialInertia>(node,"link_inertias",true,true,0);
		rhs->link_identifiers = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::identifier::IdentifierPtr>(node,"link_identifiers",true);
		rhs->link_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"link_fiducials",true);
		rhs->joint_numbers = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"joint_numbers",true,true,0);
		rhs->flange_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"flange_pose",true);
		rhs->flange_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"flange_identifier",true);
		rhs->current_tool = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::tool::ToolInfoPtr>(node,"current_tool",true);
		rhs->current_payload = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::payload::PayloadInfoPtr>(node,"current_payload",true);
		rhs->tcp_max_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"tcp_max_velocity",true);
		rhs->tcp_max_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"tcp_max_acceleration",true);
		rhs->tcp_reduced_max_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"tcp_reduced_max_velocity",true);
		rhs->tcp_reduced_max_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"tcp_reduced_max_acceleration",true);
		rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::RobotInfoPtr>::encode(const com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::RobotInfoPtr>::decode(const Node& node, com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->robot_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode>(node,"robot_type",true);
		rhs->joint_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::joints::JointInfoPtr>(node,"joint_info",true);
		rhs->chains = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>(node,"chains",true);
		rhs->robot_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities>(node,"robot_capabilities",true);
		rhs->signal_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::signal::SignalInfoPtr>(node,"signal_info",true);
		rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
		rhs->config_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"config_seqno",true);
		rhs->trajectory_interpolation_modes = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"trajectory_interpolation_modes",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::RobotStatePtr>::encode(const com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::RobotStatePtr>::decode(const Node& node, com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->command_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode>(node,"command_mode",true);
		rhs->operational_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode>(node,"operational_mode",true);
		rhs->controller_state = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState>(node,"controller_state",true);
		rhs->robot_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"robot_state_flags",true);
		rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
		rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
		rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_effort",true,true,0);
		rhs->joint_position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position_command",true,true,0);
		rhs->joint_velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity_command",true,true,0);
		rhs->kin_chain_tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Pose>(node,"kin_chain_tcp",true,true,0);
		rhs->kin_chain_tcp_vel = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialVelocity>(node,"kin_chain_tcp_vel",true,true,0);
		rhs->trajectory_running = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"trajectory_running",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>::encode(const com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>::decode(const Node& node, com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::AdvancedRobotState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->command_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode>(node,"command_mode",true);
		rhs->operational_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode>(node,"operational_mode",true);
		rhs->controller_state = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState>(node,"controller_state",true);
		rhs->robot_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"robot_state_flags",true);
		rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
		rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
		rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_effort",true,true,0);
		rhs->joint_position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position_command",true,true,0);
		rhs->joint_velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity_command",true,true,0);
		rhs->joint_position_units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"joint_position_units",true,true,0);
		rhs->joint_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"joint_effort_units",true,true,0);
		rhs->kin_chain_tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Pose>(node,"kin_chain_tcp",true,true,0);
		rhs->kin_chain_tcp_vel = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialVelocity>(node,"kin_chain_tcp_vel",true,true,0);
		rhs->trajectory_running = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"trajectory_running",true);
		rhs->trajectory_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_time",true);
		rhs->trajectory_max_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_max_time",true);
		rhs->trajectory_current_waypoint = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"trajectory_current_waypoint",true);
		rhs->config_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"config_seqno",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::RobotStateSensorDataPtr>::encode(const com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::RobotStateSensorDataPtr>::decode(const Node& node, com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotStateSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->robot_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>(node,"robot_state",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::robot::RobotJointCommandPtr>::encode(const com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::robot::RobotJointCommandPtr>::decode(const Node& node, com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotJointCommand); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->state_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"state_seqno",true);
		rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command",true,true,0);
		rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"units",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::robotics::tool::ToolInfoPtr>::encode(const com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::tool::ToolInfoPtr>::decode(const Node& node, com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->tool_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode>(node,"tool_type",true);
		rhs->tool_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities>(node,"tool_capabilities",true);
		rhs->tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Transform>(node,"tcp",true);
		rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
		rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
		rhs->actuation_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"actuation_time",true);
		rhs->close_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"close_position",true);
		rhs->open_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"open_position",true);
		rhs->command_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_min",true);
		rhs->command_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_max",true);
		rhs->command_close = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_close",true);
		rhs->command_open = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_open",true);
		rhs->sensor_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode>(node,"sensor_type",true);
		rhs->sensor_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_min",true,true,0);
		rhs->sensor_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_max",true,true,0);
		rhs->sensor_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"sensor_units",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::tool::ToolStatePtr>::encode(const com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::tool::ToolStatePtr>::decode(const Node& node, com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->tool_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"tool_state_flags",true);
		rhs->position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"position",true);
		rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command",true);
		rhs->sensor = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::robotics::tool::ToolStateSensorDataPtr>::encode(const com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::tool::ToolStateSensorDataPtr>::decode(const Node& node, com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolStateSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->robot_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::tool::ToolStatePtr>(node,"robot_state",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>::encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
		rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
		rhs->position_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_tolerance",true,true,0);
		rhs->velocity_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_tolerance",true,true,0);
		rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"interpolation_mode",true);
		rhs->waypoint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType>(node,"waypoint_type",true);
		rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>::encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
		rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"joint_units",true);
		rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>(node,"waypoints",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr>::encode(const com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::TrajectoryStatus); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->action_status = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::action::ActionStatusCode::ActionStatusCode>(node,"action_status",true);
		rhs->current_waypoint = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"current_waypoint",true);
		rhs->trajectory_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_time",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>::encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_position",true,true,0);
		rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_velocity",true,true,0);
		rhs->joint_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_acceleration",true,true,0);
		rhs->joint_jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_jerk",true,true,0);
		rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_effort",true,true,0);
		rhs->position_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"position_tolerance",true,true,0);
		rhs->velocity_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"velocity_tolerance",true,true,0);
		rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"interpolation_mode",true);
		rhs->waypoint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType>(node,"waypoint_type",true);
		// TODO: parse field varvalue{string} signals
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>::encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>(node,"joints",true);
		rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>::encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevice); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"device",true);
		rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
		rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"joint_units",true);
		rhs->joint_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"joint_effort_units",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr>::encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->devices = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>(node,"devices",true);
		rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>(node,"waypoints",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>::encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
		// TODO: parse field varvalue{list} joint_position
		// TODO: parse field varvalue{list} joint_velocity
		// TODO: parse field varvalue{list} position_tolerance
		// TODO: parse field varvalue{list} velocity_tolerance
		rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"interpolation_mode",true);
		// TODO: parse field varvalue{string} signals
		rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr>::encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr>::decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
		rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_units",true);
		rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>(node,"waypoints",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::sensor::SensorInfoPtr>::encode(const com::robotraconteur::sensor::SensorInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::sensor::SensorInfoPtr>::decode(const Node& node, com::robotraconteur::sensor::SensorInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->sensor_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode>(node,"sensor_type",true);
		rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"units",true);
		rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
		rhs->sensor_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_resolution",true,true,0);
		rhs->analog_sensor = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"analog_sensor",true);
		rhs->update_frequency = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"update_frequency",true);
		rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::sensor::SensorDataPtr>::encode(const com::robotraconteur::sensor::SensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::sensor::SensorDataPtr>::decode(const Node& node, com::robotraconteur::sensor::SensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->data_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_flags",true);
		rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"data",true,true,0);
		rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
		rhs->data_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"data_units",true);
		// TODO: parse field varvalue{string} parameters
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::sensordata::SensorDataHeaderPtr>::encode(const com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::sensordata::SensorDataHeaderPtr>::decode(const Node& node, com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataHeader); // NOLINT(cppcoreguidelines-owning-memory)
		// TODO: parse field com.robotraconteur.datetime.TimeSpec2 ts
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->source_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>(node,"source_info",true);
		return true;
	}
	Node convert<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>::encode(const com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>::decode(const Node& node, com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataSourceInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->source = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"source",true);
		rhs->source_world_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"source_world_pose",true);
		rhs->source_config_nonce = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_config_nonce",true);
		// TODO: parse field varvalue{string} source_params
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::servo::ServoInfoPtr>::encode(const com::robotraconteur::servo::ServoInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::servo::ServoInfoPtr>::decode(const Node& node, com::robotraconteur::servo::ServoInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
		rhs->servo_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::servo::ServoTypeCode::ServoTypeCode>(node,"servo_type",true);
		rhs->capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::servo::ServoCapabilities::ServoCapabilities>(node,"capabilities",true);
		rhs->axis_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"axis_count",true);
		rhs->position_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"position_units",true);
		rhs->effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"effort_units",true);
		rhs->position_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_min",true,true,0);
		rhs->position_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_max",true,true,0);
		rhs->velocity_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_min",true,true,0);
		rhs->velocity_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_max",true,true,0);
		rhs->acceleration_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration_min",true,true,0);
		rhs->acceleration_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration_max",true,true,0);
		rhs->torque_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"torque_min",true,true,0);
		rhs->torque_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"torque_max",true,true,0);
		rhs->gear_ratio = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"gear_ratio",true,true,0);
		rhs->sensor_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_resolution",true,true,0);
		rhs->effort_command_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort_command_resolution",true,true,0);
		rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
		rhs->signal_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::signal::SignalInfoPtr>(node,"signal_info",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::servo::ServoStatePtr>::encode(const com::robotraconteur::servo::ServoStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::servo::ServoStatePtr>::decode(const Node& node, com::robotraconteur::servo::ServoStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->servo_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"servo_state_flags",true);
		rhs->mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::servo::ServoMode::ServoMode>(node,"mode",true);
		rhs->position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position",true,true,0);
		rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity",true,true,0);
		rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration",true,true,0);
		rhs->effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort",true,true,0);
		rhs->position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_command",true,true,0);
		rhs->velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_command",true,true,0);
		rhs->effort_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort_command",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::servo::ServoStateSensorDataPtr>::encode(const com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::servo::ServoStateSensorDataPtr>::decode(const Node& node, com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoStateSensorData); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
		rhs->servo_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::servo::ServoStatePtr>(node,"servo_state",true);
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::servo::ServoCommandPtr>::encode(const com::robotraconteur::servo::ServoCommandPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::servo::ServoCommandPtr>::decode(const Node& node, com::robotraconteur::servo::ServoCommandPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoCommand); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->status_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"status_seqno",true);
		rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command",true,true,0);
		return true;
	}
	Node convert<com::robotraconteur::signal::SignalInfoPtr>::encode(const com::robotraconteur::signal::SignalInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::signal::SignalInfoPtr>::decode(const Node& node, com::robotraconteur::signal::SignalInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->signal_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"signal_identifier",true);
		rhs->signal_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"signal_class",true);
		rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"units",true);
		rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
		rhs->signal_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::signal::SignalType::SignalType>(node,"signal_type",true);
		rhs->access_level = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel>(node,"access_level",true);
		rhs->address = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"address",true,true,0);
		rhs->user_description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"user_description",true);
		// TODO: parse field varvalue min_value
		// TODO: parse field varvalue max_value
		// TODO: parse field varvalue{string} extended
		return true;
	}
	Node convert<com::robotraconteur::signal::SignalDeviceStatePtr>::encode(const com::robotraconteur::signal::SignalDeviceStatePtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::signal::SignalDeviceStatePtr>::decode(const Node& node, com::robotraconteur::signal::SignalDeviceStatePtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalDeviceState); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
		rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
		rhs->signal_device_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"signal_device_state_flags",true);
		return true;
	}
	Node convert<com::robotraconteur::signal::SignalGroupInfoPtr>::encode(const com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::signal::SignalGroupInfoPtr>::decode(const Node& node, com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalGroupInfo); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->signal_group_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"signal_group_identifier",true);
		rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
		return true;
	}
	Node convert<com::robotraconteur::units::SIUnitPtr>::encode(const com::robotraconteur::units::SIUnitPtr& rhs){
		RR_UNUSED(rhs);
		Node node;
		return node;
	}

	bool convert<com::robotraconteur::units::SIUnitPtr>::decode(const Node& node, com::robotraconteur::units::SIUnitPtr& rhs){
		if (!rhs) rhs.reset(new com::robotraconteur::units::SIUnit); // NOLINT(cppcoreguidelines-owning-memory)
		rhs->display_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"display_units",true);
		rhs->encoded_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoded_units",true);
		return true;
	}
}
