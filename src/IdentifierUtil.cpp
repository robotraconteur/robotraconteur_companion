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

#include "RobotRaconteurCompanion/Util/IdentifierUtil.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

bool IsIdentifierAnyUuid(const com::robotraconteur::identifier::IdentifierPtr& identifier)
{
    if (!identifier)
    {
        return true;
    }

    return std::all_of(identifier->uuid.a.begin(), identifier->uuid.a.end(), [](uint8_t b){ return b == 0; });
}

bool IsIdentifierAnyName(const com::robotraconteur::identifier::IdentifierPtr& identifier)
{
    if (!identifier)
    {
        return true;
    }

    return identifier->name.empty();
}

bool IsIdentifierAny(const com::robotraconteur::identifier::IdentifierPtr& identifier)
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

bool IsIdentifierMatch(const com::robotraconteur::identifier::IdentifierPtr& expected, const com::robotraconteur::identifier::IdentifierPtr& test)
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

com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const std::string& uuid)
{
    com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
    ret->name = name;
    boost::uuids::uuid boost_uuid = boost::lexical_cast<boost::uuids::uuid>(uuid);
    std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
    return ret;
}

com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const boost::uuids::uuid& boost_uuid)
{
    com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
    ret->name = name;
    std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
    return ret;
}

com::robotraconteur::identifier::IdentifierPtr CreateIdentifierFromName(const std::string& name)
{
    com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
    ret->name = name;
    std::fill(ret->uuid.a.begin(), ret->uuid.a.end(), 0);
    return ret;
}

std::string IdentifierToString(const com::robotraconteur::identifier::IdentifierPtr& id)
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
    return "";
}

com::robotraconteur::identifier::IdentifierPtr StringToIdentifier(const std::string& string_id)
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