/**
 * @file IdentifierUtil.h
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
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "UuidUtil.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

/**
 * @brief Check if an identifier is "any" (UUID is all zeros)
 *
 * @param identifier The identifier to check
 * @return true
 * @return false
 */
ROBOTRACONTEUR_COMPANION_UTIL_API bool IsIdentifierAnyUuid(
    const com::robotraconteur::identifier::IdentifierPtr& identifier);

/**
 * @brief Check if an identifier is "any" name (Name is empty)
 *
 * @param identifier The identifier to check
 * @return true
 * @return false
 */
ROBOTRACONTEUR_COMPANION_UTIL_API bool IsIdentifierAnyName(
    const com::robotraconteur::identifier::IdentifierPtr& identifier);

/**
 * @brief Check if an identifier is "any" (UUID is all zeros and name is empty)
 *
 * @param identifier The identifier to check
 * @return true
 * @return false
 */
ROBOTRACONTEUR_COMPANION_UTIL_API bool IsIdentifierAny(
    const com::robotraconteur::identifier::IdentifierPtr& identifier);

/**
 * @brief Check if two identifiers match
 *
 * Identifiers have a complex matching rules:
 *
 * - If both identifiers are "any", they match
 * - If either identifier is "any", they match
 * - If both identifiers have the same name and UUID, they match
 * - If the name is Any for either identifier and UUID matches, they match
 * - If the UUID is Any for either identifier and name matches, they match
 * - Otherwise, they do not match
 *
 * @param expected The expected identifier
 * @param test The identifier to test
 * @return true
 * @return false
 */
ROBOTRACONTEUR_COMPANION_UTIL_API bool IsIdentifierMatch(const com::robotraconteur::identifier::IdentifierPtr& expected,
                                                         const com::robotraconteur::identifier::IdentifierPtr& test);

/**
 * @brief Create an identifier from a name and UUID
 *
 * @param name The name
 * @param uuid The UUID
 * @return com::robotraconteur::identifier::IdentifierPtr
 */
ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(
    const std::string& name, const std::string& uuid);

/**
 * @brief Create an identifier from a name and UUID
 *
 * @param name The name
 * @param boost_uuid The UUID
 * @return com::robotraconteur::identifier::IdentifierPtr
 */
ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(
    const std::string& name, const boost::uuids::uuid& boost_uuid);

/**
 * @brief Create a Identifier From Name object
 *
 * The UUID will be set to all zeros
 *
 * @param name The name
 * @return com::robotraconteur::identifier::IdentifierPtr
 */
ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::identifier::IdentifierPtr CreateIdentifierFromName(
    const std::string& name);

/**
 * @brief Convert an identifier to a string
 *
 * The string format is "name|uuid". If the name is empty, it is omitted. If the UUID is all zeros, it is omitted.
 *
 * @param id The identifier to convert
 * @return std::string The string representation of the identifier
 */
ROBOTRACONTEUR_COMPANION_UTIL_API std::string IdentifierToString(
    const com::robotraconteur::identifier::IdentifierPtr& id);

/**
 * @brief Convert a string to an identifier
 *
 * The string format is "name|uuid". If the name is empty, it is omitted. If the UUID is all zeros, it is omitted.
 *
 * @param string_id The string representation of the identifier
 * @return com::robotraconteur::identifier::IdentifierPtr The identifier
 */
ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::identifier::IdentifierPtr StringToIdentifier(
    const std::string& string_id);

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
