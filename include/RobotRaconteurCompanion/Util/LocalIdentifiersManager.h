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

LocalIdentifierLockPtr GetIdentifierForNameAndLock(const std::string& category, const std::string& name, boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node = boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>());

}
}
}