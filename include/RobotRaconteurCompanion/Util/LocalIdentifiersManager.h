#include "com__robotraconteur__identifier.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
class LocalIdentifierLock
{
public:
    LocalIdentifierLock(const com::robotraconteur::identifier::IdentifierPtr& id, boost::shared_ptr<RobotRaconteur::NodeDirectoriesFD> fd);

    com::robotraconteur::identifier::IdentifierPtr GetIdentifier();

protected:
    com::robotraconteur::identifier::IdentifierPtr id;
    boost::shared_ptr<RobotRaconteur::NodeDirectoriesFD> fd;

};

using LocalIdentifierLockPtr = boost::shared_ptr<LocalIdentifierLock>;

/**
 * @brief Get the Identifier For Name And Lock object
 * 
 * This function is used to get a local identifier for a name. The identifier is locked to prevent
 * other processes from using the same identifier. The identifier is locked until the LocalIdentifierLockPtr
 * is destroyed.
 * 
 * This function is used to automatically generate UUID identifiers for services from a name
 * and persist them to the local system.
 * 
 * 
 * @param category The category of the identifier. Should be "device" in most cases.
 * @param name The name of the identifier
 * @param node The Robot Raconteur node
 * @return LocalIdentifierLockPtr 
 */
LocalIdentifierLockPtr GetIdentifierForNameAndLock(const std::string& category, const std::string& name, boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>());

}
}
}