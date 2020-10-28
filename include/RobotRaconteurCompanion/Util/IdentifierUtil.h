#include "com__robotraconteur__identifier.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

    

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

    static bool IsIdentifierAnyName(com::robotraconteur::identifier::IdentifierPtr identifier)
    {
        if (!identifier)
        {
            return true;
        }

        return identifier->name.empty();
    }

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

    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const std::string& uuid)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        boost::uuids::uuid boost_uuid = boost::lexical_cast<boost::uuids::uuid>(uuid);
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
        return ret;
    }

    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifier(const std::string& name, const boost::uuids::uuid& boost_uuid)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret->uuid.a.begin());
        return ret;
    }

    static com::robotraconteur::identifier::IdentifierPtr CreateIdentifierFromName(const std::string& name)
    {
        com::robotraconteur::identifier::IdentifierPtr ret(new com::robotraconteur::identifier::Identifier());
        ret->name = name;
        std::fill(ret->uuid.a.begin(), ret->uuid.a.end(), 0);
        return ret;
    }

}
}
}