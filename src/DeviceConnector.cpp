#include <RobotRaconteurCompanion/Util/DeviceConnector.h>
#include <RobotRaconteurCompanion/Util/IdentifierUtil.h>

#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>

namespace RR = RobotRaconteur;

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
DeviceConnectorDetails::DeviceConnectorDetails(const std::string& device_nickname) : DeviceNickname(device_nickname) {}

DeviceConnectorDetails::DeviceConnectorDetails(
    const std::string& device_nickname, const com::robotraconteur::identifier::IdentifierPtr& device,
    const std::vector<std::string>& root_object_type,
    const std::vector<com::robotraconteur::identifier::IdentifierPtr>& tags,
    const std::vector<RobotRaconteur::ServiceSubscriptionFilterNodePtr>& service_nodes)
    : DeviceNickname(device_nickname), Device(device), RootObjectType(root_object_type), Tags(tags),
      ServiceNodes(service_nodes)
{}

DeviceConnectorDetails::DeviceConnectorDetails(const std::string& device_nickname, const std::string& url,
                                               const RobotRaconteur::ServiceSubscriptionFilterNodePtr& url_auth)
    : DeviceNickname(device_nickname), Urls({url}), UrlAuth(url_auth)
{}

DeviceConnectorDetails::DeviceConnectorDetails(const std::string& device_nickname,
                                               const std::vector<std::string>& root_object_type,
                                               const RobotRaconteur::ServiceSubscriptionFilterPtr& subscription_filter)
    : DeviceNickname(device_nickname), RootObjectType(root_object_type), SubscriptionFilter(subscription_filter)
{}

namespace detail
{

RR::ServiceSubscriptionFilterAttribute DeviceDetailsIdentifierToFilterAttribute(
    const com::robotraconteur::identifier::IdentifierPtr& id)
{
    std::string uuid_str;
    if (!IsIdentifierAnyUuid(id))
    {
        uuid_str = UuidToString(id->uuid);
    }

    return RR::CreateServiceSubscriptionFilterAttributeIdentifier(id->name, uuid_str);
}

boost::tuple<std::vector<std::string>, RR::ServiceSubscriptionFilterPtr> DeviceDetailsToSubscriptionFilter(
    const RR::RobotRaconteurNodePtr& node, const DeviceConnectorDetails& device_details)
{
    if (device_details.DeviceNickname.empty())
    {
        throw RR::InvalidArgumentException("Device details to filter must contain device_nickname");
    }

    try
    {
        if (!device_details.Urls.empty())
        {
            throw RR::InvalidArgumentException("Device details to filter must not contain urls");
        }

        if (device_details.SubscriptionFilter)
        {
            throw RR::InvalidArgumentException("Device details to filter must not contain subscription filter");
        }

        RR::ServiceSubscriptionFilterPtr sub_filter = RR_MAKE_SHARED<RR::ServiceSubscriptionFilter>();

        std::vector<std::string> root_object_type = {"com.robotraconteur.device.Device"};

        if (!device_details.RootObjectType.empty())
        {
            root_object_type = device_details.RootObjectType;
        }

        sub_filter->MaxConnections = device_details.MaxConnections;

        if (device_details.Device)
        {
            RR::ServiceSubscriptionFilterAttributeGroup dev_attr_group;
            dev_attr_group.Attributes.push_back(DeviceDetailsIdentifierToFilterAttribute(device_details.Device));

            sub_filter->Attributes.insert(std::make_pair("device", dev_attr_group));
        }

        if (!device_details.SerialNumber.empty())
        {
            RR::ServiceSubscriptionFilterAttributeGroup dev_attr_group;
            dev_attr_group.Attributes.push_back(RR::ServiceSubscriptionFilterAttribute(device_details.SerialNumber));
            sub_filter->Attributes.insert(std::make_pair("serial_number", dev_attr_group));
        }

        if (!device_details.Tags.empty())
        {
            RR::ServiceSubscriptionFilterAttributeGroup tag_grp;
            for (auto& e : device_details.Tags)
            {
                tag_grp.Attributes.push_back(DeviceDetailsIdentifierToFilterAttribute(e));
            }
            tag_grp.Operation = device_details.TagMatchOperation;

            sub_filter->Attributes.insert(std::make_pair("tags", tag_grp));
        }

        sub_filter->AttributesMatchOperation = RR::ServiceSubscriptionFilterAttributeGroupOperation_AND;

        if (!device_details.TransportSchemes.empty())
        {
            sub_filter->TransportSchemes = device_details.TransportSchemes;
        }

        if (!device_details.ServiceNodes.empty())
        {
            sub_filter->Nodes = device_details.ServiceNodes;
        }

        return boost::make_tuple(root_object_type, sub_filter);
    }
    catch (const std::exception& e)
    {
        throw RR::InvalidArgumentException("Invalid device details for device " + device_details.DeviceNickname + ": " +
                                           e.what());
    }
}

RR::ServiceSubscriptionManagerDetails DeviceDetailsToSubscriptionDetails(const RR::RobotRaconteurNodePtr& node,
                                                                         const std::string& nickname,
                                                                         const DeviceConnectorDetails& device_details)
{
    if (!device_details.Urls.empty())
    {
        std::string username;
        RR::RRMapPtr<std::string, RR::RRValue> credentials;
        if (device_details.UrlAuth)
        {
            username = device_details.UrlAuth->Username;
            credentials = device_details.UrlAuth->Credentials;
        }

        RR::ServiceSubscriptionManagerDetails d;
        d.Name = nickname;
        d.ConnectionMethod = RR::ServiceSubscriptionManager_CONNECTION_METHOD_URL;
        d.Urls = device_details.Urls;
        d.UrlUsername = username;
        d.UrlCredentials = credentials;
        return d;
    }
    else if (device_details.SubscriptionFilter)
    {
        RR::ServiceSubscriptionManagerDetails d;
        d.Name = nickname;
        d.ConnectionMethod = RR::ServiceSubscriptionManager_CONNECTION_METHOD_TYPE;
        d.Filter = device_details.SubscriptionFilter;
        d.ServiceTypes = device_details.RootObjectType;
        return d;
    }
    else
    {
        boost::tuple<std::vector<std::string>, RR::ServiceSubscriptionFilterPtr> filter =
            DeviceDetailsToSubscriptionFilter(node, device_details);
        RR::ServiceSubscriptionManagerDetails d;
        d.Name = nickname;
        d.ConnectionMethod = RR::ServiceSubscriptionManager_CONNECTION_METHOD_TYPE;
        d.Filter = filter.get<1>();
        d.ServiceTypes = filter.get<0>();
        return d;
    }
}

struct DeviceConnectorDetailsFile
{
    std::map<std::string, DeviceConnectorDetails> devices;

    std::vector<DeviceConnectorDetails> GetDevices()
    {
        std::vector<DeviceConnectorDetails> o;
        for (auto& e : devices)
        {
            o.push_back(e.second);
        }
        return o;
    }
};

} // namespace detail
} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur

namespace YAML
{

using namespace RobotRaconteur::Companion::Util;
using namespace RobotRaconteur::Companion::Util::detail;
template <>
struct convert<DeviceConnectorDetails>
{
    static Node encode(const DeviceConnectorDetails& rhs)
    {
        RR_UNUSED(rhs);
        Node node;
        return node;
    }

    static bool decode(const Node& node, DeviceConnectorDetails& rhs)
    {
        if (node["device"])
        {
            rhs.Device = node["device"].as<com::robotraconteur::identifier::IdentifierPtr>();
        }
        if (node["serial_number"])
        {
            rhs.SerialNumber = node["serial_number"].as<std::string>();
        }
        if (node["tags"])
        {
            rhs.Tags = node["tags"].as<std::vector<com::robotraconteur::identifier::IdentifierPtr> >();
        }
        if (node["urls"])
        {
            // rhs.Urls = node["urls"].as<std::vector<std::string>>();

            // Allow Urls to be string or list
            if (node["urls"].IsSequence())
            {
                rhs.Urls = node["urls"].as<std::vector<std::string> >();
            }
            else
            {
                rhs.Urls.push_back(node["urls"].as<std::string>());
            }
        }
        if (node["root_object_type"])
        {
            if (node["root_object_type"].IsSequence())
            {
                rhs.RootObjectType = node["root_object_type"].as<std::vector<std::string> >();
            }
            else
            {
                rhs.RootObjectType.push_back(node["root_object_type"].as<std::string>());
            }
        }

        return true;
    }
};

template <>
struct convert<DeviceConnectorDetailsFile>
{
    static Node encode(const DeviceConnectorDetailsFile& rhs)
    {
        RR_UNUSED(rhs);
        Node node;
        return node;
    }

    static bool decode(const Node& node, DeviceConnectorDetailsFile& rhs)
    {
        if (node["devices"])
        {
            rhs.devices = node["devices"].as<std::map<std::string, DeviceConnectorDetails> >();
        }
        // Set device_nickname to key
        for (auto& e : rhs.devices)
        {
            e.second.DeviceNickname = e.first;
        }
        return true;
    }
};

} // namespace YAML

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromFile(const boost::filesystem::path& filename)
{
    auto map = ::YAML::LoadFile(filename.string());
    return map.as<detail::DeviceConnectorDetailsFile>().GetDevices();
}

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromString(const std::string& yaml_str)
{
    auto map = ::YAML::Load(yaml_str);
    return map.as<detail::DeviceConnectorDetailsFile>().GetDevices();
}

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromStream(std::istream& stream)
{
    auto map = ::YAML::Load(stream);
    return map.as<detail::DeviceConnectorDetailsFile>().GetDevices();
}

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromYAMLNode(const YAML::Node& node)
{
    return node.as<detail::DeviceConnectorDetailsFile>().GetDevices();
}

DeviceConnector::DeviceConnector(RobotRaconteur::RobotRaconteurNodePtr node, bool autoconnect)
    : autoconnect(autoconnect)
{
    if (!node)
    {
        node = RobotRaconteur::RobotRaconteurNode::sp();
    }
    this->node = node;
}

void DeviceConnector::Init()
{
    subscription_manager = RR_MAKE_SHARED<RobotRaconteur::ServiceSubscriptionManager>(node);
}
void DeviceConnector::Init(const std::vector<DeviceConnectorDetails>& devices)
{
    Init();
    for (auto& e : devices)
    {
        AddDevice(e);
    }
}

void DeviceConnector::InitFromYamlStr(const std::string& yaml)
{
    auto devices = LoadDeviceDetailsFromString(yaml);
    Init(devices);
}

void DeviceConnector::InitFromYamlFile(std::istream& file)
{
    auto devices = LoadDeviceDetailsFromStream(file);
    Init(devices);
}

void DeviceConnector::InitFromYamlFile(const boost::filesystem::path& filename)
{
    auto devices = LoadDeviceDetailsFromFile(filename);
    Init(devices);
}

void DeviceConnector::AddDevice(const DeviceConnectorDetails& device_details, bool force_connect)
{
    DoUpdateDevice(device_details, force_connect);
}

void DeviceConnector::RemoveDevice(const std::string& device_nickname, bool close)
{
    subscription_manager->RemoveSubscription(device_nickname, close);
}

void DeviceConnector::ConnectDevice(const std::string& device_nickname)
{
    subscription_manager->EnableSubscription(device_nickname);
}

void DeviceConnector::DisconnectDevice(const std::string& device_nickname, bool close)
{
    subscription_manager->DisableSubscription(device_nickname, close);
}

RobotRaconteur::ServiceSubscriptionPtr DeviceConnector::GetDevice(const std::string& device_nickname, bool force_create)
{
    return subscription_manager->GetSubscription(device_nickname, force_create);
}

bool DeviceConnector::TryGetDevice(const std::string& device_nickname, RobotRaconteur::ServiceSubscriptionPtr& device)
{
    try
    {
        device = subscription_manager->GetSubscription(device_nickname, false);
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}

void DeviceConnector::Close() { subscription_manager->Close(); }

std::vector<std::string> DeviceConnector::GetDeviceNicknames() { return subscription_manager->GetSubscriptionNames(); }

RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager> DeviceConnector::GetServiceSubscriptionManager()
{
    return subscription_manager;
}

void DeviceConnector::DoUpdateDevice(const DeviceConnectorDetails& device_details, bool force_connect)
{
    auto d = detail::DeviceDetailsToSubscriptionDetails(node, device_details.DeviceNickname, device_details);
    d.Enabled = autoconnect || force_connect;
    subscription_manager->AddSubscription(d);
}

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
