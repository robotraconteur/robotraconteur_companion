/**
 * @file UuidUtil.h
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

#include "com__robotraconteur__uuid.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "UtilMacros.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    /**
     * Parse a UUID from a string.
     * 
     * Parses a string representation of a UUID and returns a com::robotraconteur::uuid::UUID object.
     * 
     * @param string_uuid The string to parse.
     * @return The parsed UUID.
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::uuid::UUID ParseUuid(const std::string& string_uuid);

    /**
     * Convert a UUID to a string.
     * 
     * Converts a com::robotraconteur::uuid::UUID object into a string representation.
     * 
     * @param uuid The UUID to convert.
     * @return The string representation of the UUID.
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API std::string UuidToString(com::robotraconteur::uuid::UUID uuid);

    /**
     * Convert a boost::uuids::uuid to com::robotraconteur::uuid::UUID.
     * 
     * Converts a boost::uuids::uuid object to a com::robotraconteur::uuid::UUID object.
     * 
     * @param boost_uuid The boost::uuids::uuid to convert.
     * @return The converted UUID.
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::uuid::UUID BoostUuidToUuid(const boost::uuids::uuid& boost_uuid);

    /**
     * Convert a com::robotraconteur::uuid::UUID to boost::uuids::uuid.
     * 
     * Converts a com::robotraconteur::uuid::UUID object to a boost::uuids::uuid object.
     * 
     * @param uuid The com::robotraconteur::uuid::UUID to convert.
     * @return The converted boost::uuids::uuid.
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API boost::uuids::uuid UuidToBoostUuid(const com::robotraconteur::uuid::UUID& uuid);

    /**
     * @brief Generate a new random UUID
     * 
     * Generates a new random UUID using boost::uuids::random_generator().
     * 
     * @return com::robotraconteur::uuid::UUID The generated random UUID
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::uuid::UUID NewRandomUuid();
}
}
}