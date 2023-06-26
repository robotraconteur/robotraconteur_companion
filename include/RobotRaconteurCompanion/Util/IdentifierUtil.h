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
    static bool IsIdentifierAnyUuid(com::robotraconteur::identifier::IdentifierPtr identifier)
    {
        if (!identifier)
        {
            return true;
        }

        for(auto b : identifier->uuid.a)
        {
            if (b != 0) return false;
        }
        return true;
    }
    
    /**
     * @brief Check if an identifier is "any" name (Name is empty)
     * 
     * @param identifier The identifier to check
     * @return true 
     * @return false 
     */
    static bool IsIdentifierAnyName(com::robotraconteur::identifier::IdentifierPtr identifier)
    {
        if (!identifier)
        {
            return true;
        }

        return identifier->name.empty();
    }

    /**
     * @brief Check if an identifier is "any" (UUID is all zeros and name is empty)
     * 
     * @param identifier The identifier to check
     * @return true 
     * @return false 
     */
    static bool IsIdentifierAny(com::robotraconteur::identifier::IdentifierPtr identifier)
    {
        if (!identifier)
        {
            return true;
        }
        if (!IsIdentifierAnyUuid(identifier))
        {
            return false;
        }
        if (!IsIdentifierAnyName(identifier))
        {
            return false;
        }
        return true;
    }

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
    static bool IsIdentifierMatch(com::robotraconteur::identifier::IdentifierPtr expected, com::robotraconteur::identifier::IdentifierPtr test)
    {
        if (IsIdentifierAny(expected) || IsIdentifierAny(test))
        {
            return true;
        }

        bool name_match = false;
        bool uuid_match = false;
        
        if (IsIdentifierAnyName(expected) || IsIdentifierAnyName(test))
        {
            name_match = true;
        }
        else
        {
            if (expected->name == test->name)
            {
                name_match = true;
            }
        }

        if (IsIdentifierAnyUuid(expected) || IsIdentifierAnyUuid(test))
        {
            uuid_match = true;
        }
        else
        {
            if (std::equal(expected->uuid.a.begin(), expected->uuid.a.end(), test->uuid.a.begin()))
            {
                uuid_match = true;
            }
        }

        return name_match && uuid_match;
    }

    /**
     * @brief Create an identifier from a name and UUID
     * 
     * @param name The name
     * @param uuid The UUID
     * @return com::robotraconteur::identifier::IdentifierPtr 
     */
    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const std::string& uuid)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        boost::uuids::uuid boost_uuid = boost::lexical_cast<boost::uuids::uuid>(uuid);
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
        return ret;
    }

    /**
     * @brief Create an identifier from a name and UUID
     * 
     * @param name The name
     * @param boost_uuid The UUID
     * @return com::robotraconteur::identifier::IdentifierPtr 
     */
    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const boost::uuids::uuid& boost_uuid)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
        return ret;
    }

    /**
     * @brief Create a Identifier From Name object
     * 
     * The UUID will be set to all zeros
     * 
     * @param name The name
     * @return com::robotraconteur::identifier::IdentifierPtr 
     */
    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifierFromName(const std::string& name)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        std::fill(ret->uuid.a.begin(), ret->uuid.a.end(), 0);
        return ret;
    }

    /**
     * @brief Convert an identifier to a string
     * 
     * The string format is "name|uuid". If the name is empty, it is omitted. If the UUID is all zeros, it is omitted.
     * 
     * @param id The identifier to convert
     * @return std::string The string representation of the identifier
     */
    static std::string IdentifierToString(const com::robotraconteur::identifier::IdentifierPtr& id)
    {
        if (!id)
        {
            return "";
        }
        if (!IsIdentifierAnyName(id) && !IsIdentifierAnyUuid(id))
        {
            return id->name + "|" + UuidToString(id->uuid);
        }
        if (!IsIdentifierAny(id))
        {
            return id->name;
        }
        if (!IsIdentifierAnyUuid(id))
        {
            return UuidToString(id->uuid);
        }
    }

    /**
     * @brief Convert a string to an identifier
     * 
     * The string format is "name|uuid". If the name is empty, it is omitted. If the UUID is all zeros, it is omitted.
     * 
     * @param string_id The string representation of the identifier
     * @return com::robotraconteur::identifier::IdentifierPtr The identifier
     */
    static com::robotraconteur::identifier::IdentifierPtr StringToIdentifier(const std::string& string_id)
    {
        static std::string name_regex_str = "(?:[a-zA-Z](?:\\w*[a-zA-Z0-9])?)(?:\\.[a-zA-Z](?:\\w*[a-zA-Z0-9])?)*";
        static std::string uuid_regex_str = "\\{?[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{12}\\}?";
        static std::string identifier_regex = "(?:(" + name_regex_str + ")\\|(" + uuid_regex_str + "))|(" + name_regex_str + ")|(" + uuid_regex_str + ")";
        static boost::regex r_identifier = boost::regex(identifier_regex);

        boost::smatch r_res;
        if (!boost::regex_match(string_id, r_res, r_identifier))
        {
            throw RobotRaconteur::InvalidArgumentException("Invalid identifier string");
        }

        if(r_res[1].matched && r_res[2].matched)
        {
            return CreateIdentifier(r_res[1].str(), r_res[2].str());
        }

        if (r_res[3].matched)
        {
            return CreateIdentifierFromName(r_res[3].str());
        }

        if (r_res[4].matched)
        {
            return CreateIdentifier("", r_res[4].str());
        }

        throw RobotRaconteur::InvalidArgumentException("Invalid identifier string");
    }

}
}
}