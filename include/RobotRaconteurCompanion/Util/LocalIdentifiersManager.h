/**
 * @file LocalIdentifiersManager.h
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

#include "com__robotraconteur__identifier.h"

#include <RobotRaconteurCompanion/Util/UtilMacros.h>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
class ROBOTRACONTEUR_COMPANION_UTIL_API LocalIdentifierLock
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
ROBOTRACONTEUR_COMPANION_UTIL_API LocalIdentifierLockPtr GetIdentifierForNameAndLock(const std::string& category, const std::string& name, boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>());

}
}
}