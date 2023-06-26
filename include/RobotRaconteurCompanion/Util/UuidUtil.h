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

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    /**
     * @brief Parse a UUID from a string
     * 
     * @param string_uuid The string to parse
     * @return com::robotraconteur::uuid::UUID The parsed UUID
     */
    static com::robotraconteur::uuid::UUID ParseUuid(const std::string& string_uuid)
    {
        com::robotraconteur::uuid::UUID ret;
        boost::uuids::uuid boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret.a.begin());
        return ret;
    }

    /**
     * @brief Convert a UUID to a string
     * 
     * @param uuid The UUID to convert
     * @return std::string The string
     */
    static std::string UuidToString(com::robotraconteur::uuid::UUID uuid)
    {
        boost::uuids::uuid boost_uuid;
        std::copy(uuid.a.begin(),uuid.a.end(),boost_uuid.begin());
        return boost::lexical_cast<std::string>(boost_uuid);
    }
}
}
}