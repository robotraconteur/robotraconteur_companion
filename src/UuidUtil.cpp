#include "RobotRaconteurCompanion/Util/UuidUtil.h"
#include <boost/uuid/uuid_generators.hpp>

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    static com::robotraconteur::uuid::UUID ParseUuid(const std::string& string_uuid)
    {
        com::robotraconteur::uuid::UUID ret;
        boost::uuids::uuid boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret.a.begin());
        return ret;
    }

    static std::string UuidToString(com::robotraconteur::uuid::UUID uuid)
    {
        boost::uuids::uuid boost_uuid;
        std::copy(uuid.a.begin(),uuid.a.end(),boost_uuid.begin());
        return boost::lexical_cast<std::string>(boost_uuid);
    }

    static com::robotraconteur::uuid::UUID BoostUuidToUuid(const boost::uuids::uuid& boost_uuid)
    {
        com::robotraconteur::uuid::UUID ret;
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret.a.begin());
        return ret;
    }

    static boost::uuids::uuid UuidToBoostUuid(const com::robotraconteur::uuid::UUID& uuid)
    {
        boost::uuids::uuid boost_uuid;
        std::copy(uuid.a.begin(), uuid.a.end(), boost_uuid.begin());
        return boost_uuid;
    }

    static com::robotraconteur::uuid::UUID NewRandomUuid()
    {
        boost::uuids::uuid boost_uuid = boost::uuids::random_generator()();
        return BoostUuidToUuid(boost_uuid);
    }
}
}
}