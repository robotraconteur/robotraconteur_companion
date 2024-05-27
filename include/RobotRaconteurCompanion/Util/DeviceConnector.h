/**
 * @file DeviceConnector.h
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2024 Wason Technology, LLC
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
 */

#include <RobotRaconteur/RobotRaconteurNode.h>
#include <RobotRaconteur/Subscription.h>
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

/**
 * @brief Device connection information for use with DeviceConnector class.
 *
 * The DeviceConnectorDetails contains information that is used by the DeviceConnector class to connect to devices.
 * The DeviceConnector can connect to devicues using three different methods:
 *
 *   1. Discovery devices using device identifier (name, uuid) in combination with optional serial
 *      number and/or device tags
 *   2. Connection using a list of URLs. Using URLs is the most direct way to connect to a device.
 *   3. Connection using specified list of service root object types and optional subscription filter.
 *
 * Different combinations of fields are valid depending on the connection method used. See the DeviceConnector
 * documentation for more information on how to use the DeviceConnectorDetails class.
 */
struct ROBOTRACONTEUR_COMPANION_UTIL_API DeviceConnectorDetails
{
    /** @brief The nickname of the device */
    std::string DeviceNickname;
    /** @brief The device identifier (name, uuid) of the device. null if not used */
    com::robotraconteur::identifier::IdentifierPtr Device;
    /** @brief The serial number of the device. Empty if not used */
    std::string SerialNumber;
    /** @brief The tags of the device. Empty if not used */
    std::vector<com::robotraconteur::identifier::IdentifierPtr> Tags;
    /** @brief The service nodes of the device. Empty if not used */
    std::vector<RobotRaconteur::ServiceSubscriptionFilterNodePtr> ServiceNodes;
    /** @brief A list of URLs to use for direct connection to the device. Empty if not used */
    std::vector<std::string> Urls;
    /** @brief The root object type of the device. Empty if not used. May be necessary when "device" is used. */
    std::vector<std::string> RootObjectType;
    /** @brief The subscription filter to use when connecting to the device. Not used with Url or "device" */
    RobotRaconteur::ServiceSubscriptionFilterPtr SubscriptionFilter;
    /** @brief The transport schemes to use when connecting to the device. Not used with Url or Filter */
    std::vector<std::string> TransportSchemes;
    /** @brief The URL auth to use when connecting to the device. Not used with Filter or "device" */
    RobotRaconteur::ServiceSubscriptionFilterNodePtr UrlAuth;
    /** @brief The maximum number of connections to the device. 0 for unlimited. Defaults to 10 */
    int32_t MaxConnections = 10;
    /** @brief The tag match operation to use with Tags. Defaults to "AND" */
    RobotRaconteur::ServiceSubscriptionFilterAttributeGroupOperation TagMatchOperation =
        RobotRaconteur::ServiceSubscriptionFilterAttributeGroupOperation_AND;

    /**
     * @brief Construct an empty DeviceConnectorDetails
     */
    DeviceConnectorDetails() = default;
    /**
     * @brief Construct a new DeviceConnectorDetails with nickname
     *
     * @param device_nickname The nickname of the device
     */
    DeviceConnectorDetails(const std::string& device_nickname);
    /**
     * @brief Construct a new DeviceConnectorDetails for use with "device" identifier
     *
     * @param device_nickname The nickname of the device
     * @param device The identifier of the desired device
     * @param root_object_type The root object type of the device. Defaults to com::robotraconteur::device::Device.
     *                         In most cases it will be necessary to specify this, otherwise only the Device object
     *                         will be available.
     * @param tags An optional list of tags to match when connecting to the device with "AND" operation.
     * @param service_nodes An optional list of service nodes to match including authentication information.
     */
    DeviceConnectorDetails(const std::string& device_nickname,
                           const com::robotraconteur::identifier::IdentifierPtr& device,
                           const std::vector<std::string>& root_object_type,
                           const std::vector<com::robotraconteur::identifier::IdentifierPtr>& tags = {},
                           const std::vector<RobotRaconteur::ServiceSubscriptionFilterNodePtr>& service_nodes = {});
    /**
     * @brief Construct a new DeviceConnectorDetails for use with URL connection
     *
     * @param device_nickname The nickname of the device
     * @param url The URL to connect to
     * @param url_auth Authentication information for the URL connection
     */
    DeviceConnectorDetails(const std::string& device_nickname, const std::string& url,
                           const RobotRaconteur::ServiceSubscriptionFilterNodePtr& url_auth = nullptr);
    /**
     * @brief Construct a new DeviceConnectorDetails for use with Robot Raconteur subscription filter
     *
     * @param device_nickname The nickname of the device
     * @param root_object_type The desired root object types
     * @param subscription_filter The subscription filter
     */
    DeviceConnectorDetails(const std::string& device_nickname, const std::vector<std::string>& root_object_type,
                           const RobotRaconteur::ServiceSubscriptionFilterPtr& subscription_filter);
};

/**
 * @brief Device connection manager for connecting to devices using Robot Raconteur.
 *
 * The DeviceConnector class is designed to simplify connecting to devices using Robot Raconteur. Finding and
 * connecting to multiple services can be complex, especially when using advanced features such as service
 * discovery filters. The DeviceConnector takes advantage of the "device" concept introduced by the Robot Raconteur
 * standard types. The "device" concept introduces the `com.robotraconteur.device.Device` interface, which provides
 * the structure `com.robotraconteur.device.DeviceInfo` containing metadata about the device. The "device" concept
 * provides a more descriptive way to identify, connect, and interrogate devices.
 *
 * Three fields in the `com.robotraconteur.device.DeviceInfo` structure are used to identify devices by the
 * DeviceConnector:
 *
 *     1. `device`: The device identifier (name and/or uuid) of the device.
 *     2. `serial_number`: The serial number of the device.
 *     3. `tags`: A list of tags associated with the device. These tags are typically strings or identifiers.
 *
 * For the "device" concept, an identifier is a combination of a human readable name and a UUID. The name is not
 * guaranteed to be unique, but the combination of the name and UUID is expected unique. The UUID should be used
 * in a production environment, but the simple name can be used for testing and development.
 *
 * The combination of `device`, `serial_number`, and `tags` is used to generate a `ServiceSubscriptionFilter` that
 * is used to create a subscription to the device.
 *
 * The DeviceConnector is used by software like the PyRI Open Source Teaching Pendant to connect to devices. The
 * DeviceConnector should be used by production level software that provides the option to users to select and
 * connect to devices.
 *
 * The DeviceConnectorDetails structure is used to provide information to the DeviceConnector about how to connect
 * to a device. See the DeviceConnectorDetails documentation for more information on each field.
 * DeviceConnectorDetails contains information that is used by the DeviceConnector class to connect to devices.
 * The DeviceConnector can connect to devicues using three different methods:
 *
 *     1. Discovery devices using device identifier (name, uuid) in combination with optional serial
 *        number and/or device tags
 *     2. Connection using a list of URLs. Using URLs is the most direct way to connect to a device.
 *     3. Connection using specified list of service root object types and optional subscription filter.
 *
 * Different combinations of fields are valid depending on the connection method used.
 *
 * The following fields are used to connect to devices with the methods described above:
 *
 *      1. `Device`, `RootObjectType`, `SerialNumber`, `Tags`, `TagMatchOperation`, `ServiceNodes`, `TransportSchemes`,
 * `MaxConnections`
 *      2. `Urls`, `UrlAuth`
 *      3. `RootObjectType`, `SubscriptionFilter`
 *
 * For all methods, the `device_nickname` field is used to identify the device in the DeviceConnector and must
 *  be unique.
 *
 *  The device details can also be loaded from a YAML file.
 *
 *  The YAML file should match the following example format:
 *
 *  ```
 *  devices:
 *      device1:
 *          # Connect to device using URLs
 *          urls: rr+intra:///?nodename=server_node&service=robot1
 *      device2:
 *          # Connect to device using device identifier, serial number, and tags
 *          device: robot2
 *          serial_number: "1234"
 *          tags:
 *          - tag1
 *          - tag2
 *      device3:
 *          # Connect to device using device identifier and tags
 *          device:
 *              name: robot3
 *              uuid: "b92fda92-c74e-4fd1-8174-0163b4dc182a"
 *          tags:
 *          - name: tag1
 *            uuid: "a9d4e339-f248-49c7-9443-e2f3ebba9c02"
 *          - tag2
 *      device4:
 *          # Match any tags or serial number
 *          device: robot3
 * ```
 */
class ROBOTRACONTEUR_COMPANION_UTIL_API DeviceConnector
{
  public:
    /**
     * @brief Construct a new DeviceConnector
     *
     * @param node The Robot Raconteur node to use. If null, the default node is used.
     * @param autoconnect If true, the DeviceConnector will automatically connect to devices when they are added.
     *                    Default is true.
     *
     * Must call one of the Init methods to initialize the DeviceConnector.
     */
    DeviceConnector(RobotRaconteur::RobotRaconteurNodePtr node = nullptr, bool autoconnect = true);

    /**
     * @brief Initialize the DeviceConnector
     *
     * Initializes the DeviceConnector with no devices. Must call AddDevice to add devices.
     */
    void Init();
    /**
     * @brief Initialize the DeviceConnector with a list of devices
     *
     * @param devices The list of devices to add
     */
    void Init(const std::vector<DeviceConnectorDetails>& devices);
    /**
     * @brief Initialize the DeviceConnector from a YAML string
     *
     * See the DeviceConnector documentation for the YAML format
     *
     * @param yaml The YAML formatted string
     */
    void InitFromYamlStr(const std::string& yaml);
    /**
     * @brief Initialize the DeviceConnector from a YAML stream
     *
     * See the DeviceConnector documentation for the YAML format
     *
     * @param file The YAML formatted stream
     */
    void InitFromYamlFile(std::istream& file);
    /**
     * @brief Initialize the DeviceConnector from a YAML file
     *
     * See the DeviceConnector documentation for the YAML format
     *
     * @param filename The path to the YAML file
     */
    void InitFromYamlFile(const boost::filesystem::path& filename);

    /**
     * @brief Add a device to the DeviceConnector
     *
     * Also used to update a device. If the device already exists, it will be updated with the new details.
     *
     * @param device_details The device details to add
     * @param force_connect If true, the device will be connected immediately. Default is false. Ignored if autoconnect
     * is true.
     */
    void AddDevice(const DeviceConnectorDetails& device_details, bool force_connect = false);

    /**
     * @brief Remove a device from the DeviceConnector
     *
     * @param device_nickname The nickname of the device to remove
     * @param close If true, the device will be disconnected before removing. Default is true.
     */
    void RemoveDevice(const std::string& device_nickname, bool close = true);

    /**
     * @brief Connect to a device if not already connected
     *
     * If a device is disconnected or autoconnect is false, the device will be connected.
     *
     * @param device_nickname The nickname of the device to connect
     */
    void ConnectDevice(const std::string& device_nickname);

    /**
     * @brief Disconnect a device
     *
     * @param device_nickname The nickname of the device to disconnect
     * @param close If true, the device will be closed. Default is true.
     */
    void DisconnectDevice(const std::string& device_nickname, bool close = true);

    /**
     * @brief Get the Device object
     *
     * @param device_nickname The nickname of the device
     * @param force_create If true, the device will be created if it does not exist. Default is false.
     * @return RobotRaconteur::ServiceSubscriptionPtr The subscription to the device
     */
    RobotRaconteur::ServiceSubscriptionPtr GetDevice(const std::string& device_nickname, bool force_create = false);

    /**
     * @brief Try to get the Device object. Returns false if the device does not exist instead of throwing an exception.
     *
     * @param device_nickname The nickname of the device
     * @param device [out] The subscription to the device
     * @return true The device was found
     * @return false No device with the given nickname was found
     */
    bool TryGetDevice(const std::string& device_nickname, RobotRaconteur::ServiceSubscriptionPtr& device);

    /**
     * @brief Close the DeviceConnector
     *
     * All subscriptions to devices will be closed.
     *
     */
    void Close();

    /**
     * @brief Get all nicknames of the devices
     *
     * @return std::vector<std::string> The nicknames of the devices
     */
    std::vector<std::string> GetDeviceNicknames();

    /**
     * @brief Get the underlying ServiceSubscriptionManager used by the DeviceConnector
     *
     * @return RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager>
     */
    RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager> GetServiceSubscriptionManager();

  protected:
    void DoUpdateDevice(const DeviceConnectorDetails& device_details, bool force_connect = false);

    RobotRaconteur::RobotRaconteurNodePtr node;
    bool autoconnect = true;
    RR_SHARED_PTR<RobotRaconteur::ServiceSubscriptionManager> subscription_manager;
};

/**
 * @brief Load DeviceDetails list from a YAML file
 *
 * See the DeviceConnector documentation for the YAML format
 *
 * @param filename The filename to load
 * @return std::vector<DeviceConnectorDetails> The list of device details
 */
ROBOTRACONTEUR_COMPANION_UTIL_API std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromFile(
    const boost::filesystem::path& filename);

/**
 * @brief Load DeviceDetails list from a YAML string
 *
 * See the DeviceConnector documentation for the YAML format
 *
 * @param yaml_str The YAML formatted string to load
 * @return std::vector<DeviceConnectorDetails> The list of device details
 */
ROBOTRACONTEUR_COMPANION_UTIL_API std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromString(
    const std::string& yaml_str);

/**
 * @brief Load DeviceDetails list from a YAML stream
 *
 * See the DeviceConnector documentation for the YAML format
 *
 * @param stream The YAML formatted stream to load
 * @return std::vector<DeviceConnectorDetails> The list of device details
 */
ROBOTRACONTEUR_COMPANION_UTIL_API std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromStream(std::istream& stream);

/**
 * @brief Load DeviceDetails list from a YAML node
 *
 * Load from a pre-parsed YAML::Node
 *
 * See the DeviceConnector documentation for the YAML format
 *
 * @param node The YAML node to load
 * @return std::vector<DeviceConnectorDetails> The list of device details
 */
ROBOTRACONTEUR_COMPANION_UTIL_API std::vector<DeviceConnectorDetails> LoadDeviceDetailsFromYAMLNode(
    const YAML::Node& node);

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
