#include <RobotRaconteur/Subscription.h>
#include <RobotRaconteur/RobotRaconteurNode.h>
#include "com__robotraconteur__identifier.h"
#include <yaml-cpp/yaml.h>

#include "UtilMacros.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
struct ROBOTRACONTEUR_COMPANION_UTIL_API DeviceConnectorDetails
{
    std::string DeviceNickname;
    com::robotraconteur::identifier::IdentifierPtr Device;
    std::string SerialNumber;
    std::vector<com::robotraconteur::identifier::IdentifierPtr> Tags;
    std::vector<RobotRaconteur::ServiceSubscriptionFilterNodePtr> ServiceNodes;
    std::vector<std::string> Urls;
    std::vector<std::string> RootObjectType;
    RobotRaconteur::ServiceSubscriptionFilterPtr SubscriptionFilter;
    std::vector<std::string> TransportSchemes;
    RobotRaconteur::ServiceSubscriptionFilterNodePtr UrlAuth;
    int32_t MaxConnections = 0;
    RobotRaconteur::ServiceSubscriptionFilterAttributeGroupOperation TagMatchOperation;

    DeviceConnectorDetails() = default;
    DeviceConnectorDetails(const std::string& device_nickname);
    DeviceConnectorDetails(const std::string& device_nickname,
                           const com::robotraconteur::identifier::IdentifierPtr& device,
                           const std::vector<com::robotraconteur::identifier::IdentifierPtr>& tags = {},
                           const std::vector<RobotRaconteur::ServiceSubscriptionFilterNodePtr>& service_nodes = {});
    DeviceConnectorDetails(const std::string& device_nickname, const std::string& url,
                           const RobotRaconteur::ServiceSubscriptionFilterNodePtr& url_auth = nullptr);
    DeviceConnectorDetails(const std::string& device_nickname, const std::vector<std::string>& root_object_type,
                           const RobotRaconteur::ServiceSubscriptionFilterPtr& subscription_filter);
};

class ROBOTRACONTEUR_COMPANION_UTIL_API DeviceConnector
{
  public:
    DeviceConnector(RobotRaconteur::RobotRaconteurNodePtr node = nullptr, bool autoconnect = true);

    void Init();
    void Init(const std::vector<DeviceConnectorDetails>& devices);
    void InitFromYamlStr(const std::string& yaml);
    void InitFromYamlFile(std::istream& file);
    void InitFromYamlFile(const boost::filesystem::path& filename);

    void AddDevice(const DeviceConnectorDetails& device_details, bool force_connect = false);

    void RemoveDevice(const std::string& device_nickname, bool close = true);

    void ConnectDevice(const std::string& device_nickname);

    void DisconnectDevice(const std::string& device_nickname, bool close = true);

    RobotRaconteur::ServiceSubscriptionPtr GetDevice(const std::string& device_nickname, bool force_create = false);

    bool TryGetDevice(const std::string& device_nickname, RobotRaconteur::ServiceSubscriptionPtr& device);

    void Close();

    std::vector<std::string> GetDeviceNicknames();

    RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager> GetServiceSubscriptionManager();

  protected:
    void DoUpdateDevice(const DeviceConnectorDetails& device_details, bool force_connect = false);

    RobotRaconteur::RobotRaconteurNodePtr node;
    bool autoconnect = true;
    RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager> subscription_manager;
};

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromFile(const boost::filesystem::path& filename);

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromString(const std::string& yaml_str);

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromStream(std::istream& stream);

std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromYAMLNode(const YAML::Node& node);

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
