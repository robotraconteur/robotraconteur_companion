/**
 * @file InfoFileLoader.h
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
 */

#include "IdentifierUtil.h"
#include "LocalIdentifiersManager.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
namespace detail
{
    template <typename T>
    class LoadInfoFile_traits
    {
    public:
        static bool LoadDeviceIdentifier(const T& info_file, const std::string& category, std::vector<LocalIdentifierLockPtr>& locks, boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node)
        {
            if (info_file && info_file->device_info && info_file->device_info->device && !IsIdentifierAnyName(info_file->device_info->device) && IsIdentifierAnyUuid(info_file->device_info->device))
            {
                LocalIdentifierLockPtr l = GetIdentifierForNameAndLock(category, info_file->device_info->device->name, node);
                info_file->device_info->device = l->GetIdentifier();
                locks.push_back(l);
                return true;
            }
            return false;
        }
    };

    template <>
    class LoadInfoFile_traits<com::robotraconteur::device::DeviceInfoPtr>
    {
    public:
        static bool LoadDeviceIdentifier(const com::robotraconteur::device::DeviceInfoPtr& info_file, const std::string& category, std::vector<LocalIdentifierLockPtr>& locks,  boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node)
        {
            if (info_file && info_file && info_file->device && !IsIdentifierAnyName(info_file->device) && IsIdentifierAnyUuid(info_file->device))
            {
                LocalIdentifierLockPtr l = GetIdentifierForNameAndLock(category, info_file->device->name, node);
                info_file->device = l->GetIdentifier();
                locks.push_back(l);
                return true;
            }
            return false;
        }
    };
}

/**
 * @brief Load an info file from a string
 * 
 * Device information structures store metadata about devices that are provided to clients at runtime. The
 * metadata is used to allow clients to determine the parameters and capabilities of the device. The exact
 * type of the device info file depends on the device type. A number of device info structures are supported;
 * see the documentation and examples.
 * 
 * The device info file is loaded from a string. The string is parsed as YAML. The YAML must be a valid
 * representation of the device info structure.
 * 
 * The loader will "lock" the device identifier on the filesystem. It will automatically generate a UUID
 * for the device name that will be persisted to the filesystem. This allows the device to be uniquely
 * identified. Keep the contents of identifiers_lock in scope for the lifetime of the device. 
 * 
 * @tparam T The type of the device info structure
 * @param file_text The YAML text
 * @param identifier_locks Vector to store the identifier locks
 * @param category The category of the device. Should be "device" for most cases
 * @param node The Robot Raconteur node
 * @return T The populated device info structure
 */
template<typename T>
static T LoadInfoFileFromString(const std::string& file_text, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified", boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>())
{
    auto map = YAML::Load(file_text);
    auto info = map.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks, node);
    return info;
}

/**
 * @brief Load an info file from a file
 * 
 * Device information structures store metadata about devices that are provided to clients at runtime. The
 * metadata is used to allow clients to determine the parameters and capabilities of the device. The exact
 * type of the device info file depends on the device type. A number of device info structures are supported;
 * see the documentation and examples.
 * 
 * The device info file is loaded from a file. The file is parsed as YAML. The YAML must be a valid
 * representation of the device info structure.
 * 
 * The loader will "lock" the device identifier on the filesystem. It will automatically generate a UUID
 * for the device name that will be persisted to the filesystem. This allows the device to be uniquely
 * identified. Keep the contents of identifiers_lock in scope for the lifetime of the device.
 * 
 * @tparam T The type of the device info structure
 * @param file_name The file name
 * @param identifier_locks The vector to store the identifier locks
 * @param category The category of the device. Should be "device" for most cases
 * @param node The Robot Raconteur node
 * @return T The populated device info structure
 */
template<typename T>
static T LoadInfoFile(const std::string& file_name, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified", boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>())
{
    auto map = YAML::LoadFile(file_name);
    auto info = map.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks, node);
    return info;
}

/**
 * @brief Load an info file from a YAML node
 * 
 * Device information structures store metadata about devices that are provided to clients at runtime. The
 * metadata is used to allow clients to determine the parameters and capabilities of the device. The exact
 * type of the device info file depends on the device type. A number of device info structures are supported;
 * see the documentation and examples.
 * 
 * The device info file is loaded from a YAML node. The YAML must be a valid
 * representation of the device info structure.
 * 
 * The loader will "lock" the device identifier on the filesystem. It will automatically generate a UUID
 * for the device name that will be persisted to the filesystem. This allows the device to be uniquely
 * identified. Keep the contents of identifiers_lock in scope for the lifetime of the device.
 * 
 * @tparam T The type of the device info structure
 * @param node The YAML node
 * @param identifier_locks The vector to store the identifier locks
 * @param category The category of the device. Should be "device" for most cases
 * @param rr_node The Robot Raconteur node
 * @return T The populated device info structure
 */
template<typename T>
static T LoadInfoFileFromNode(YAML::Node& node, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified", boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> rr_node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>())
{
    auto info = node.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks, rr_node);
    return info;
}

}
}
}