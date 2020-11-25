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
        static bool LoadDeviceIdentifier(const T& info_file, const std::string& category, std::vector<LocalIdentifierLockPtr>& locks)
        {
            if (info_file && info_file->device_info && info_file->device_info->device && !IsIdentifierAnyName(info_file->device_info->device) && IsIdentifierAnyUuid(info_file->device_info->device))
            {
                LocalIdentifierLockPtr l = GetIdentifierForNameAndLock(category, info_file->device_info->device->name);
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
        static bool LoadDeviceIdentifier(const com::robotraconteur::device::DeviceInfoPtr& info_file, const std::string& category, std::vector<LocalIdentifierLockPtr>& locks)
        {
            if (info_file && info_file && info_file->device && !IsIdentifierAnyName(info_file->device) && IsIdentifierAnyUuid(info_file->device))
            {
                LocalIdentifierLockPtr l = GetIdentifierForNameAndLock(category, info_file->device->name);
                info_file->device = l->GetIdentifier();
                locks.push_back(l);
                return true;
            }
            return false;
        }
    };
}

template<typename T>
static T LoadInfoFileFromString(const std::string& file_text, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified")
{
    auto map = YAML::Load(file_text);
    auto info = map.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks);
    return info;
}
 
template<typename T>
static T LoadInfoFile(const std::string& file_name, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified")
{
    auto map = YAML::LoadFile(file_name);
    auto info = map.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks);
    return info;
}

template<typename T>
static T LoadInfoFileFromNode(YAML::Node& node, std::vector<LocalIdentifierLockPtr>& identifier_locks, const std::string& category = "unspecified")
{
    auto info = node.as<T>();
    detail::LoadInfoFile_traits<T>::LoadDeviceIdentifier(info, category, identifier_locks);
    return info;
}

}
}
}