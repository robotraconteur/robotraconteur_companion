#include "RobotRaconteurCompanion/Util/LocalIdentifiersManager.h"
#include <boost/filesystem.hpp>
#include "RobotRaconteurCompanion/Util/IdentifierUtil.h"

#ifdef ROBOTRACONTEUR_WINDOWS
#include <Shlobj.h>
#else

#endif

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

LocalIdentifierLock::LocalIdentifierLock(const com::robotraconteur::identifier::IdentifierPtr& id, boost::shared_ptr<RobotRaconteur::NodeDirectoriesFD> fd)
{
    this->id = id;
    this->fd = fd;
}

com::robotraconteur::identifier::IdentifierPtr LocalIdentifierLock::GetIdentifier()
{
    return id;
}

LocalIdentifierLockPtr GetIdentifierForNameAndLock(const std::string& category, const std::string& name, boost::shared_ptr<RobotRaconteur::RobotRaconteurNode> node)
{		

    if (!node)
    {
        node = RobotRaconteur::RobotRaconteurNode::sp();
    }
    
    if (!boost::regex_match(name.begin(), name.end(), boost::regex("^[a-zA-Z][a-zA-Z0-9_\\.\\-]*$")))
    {
        throw InvalidArgumentException("\"" + name + "\" is an invalid identifier name");
    }

    NodeDirectories node_dirs = node->GetNodeDirectories();

    GetUuidForNameAndLockResult p = GetUuidForNameAndLock(node_dirs, name, boost::assign::list_of(std::string("identifiers"))(category));

    com::robotraconteur::identifier::IdentifierPtr ret_id = CreateIdentifier(name,p.uuid.ToString("D"));

    return boost::make_shared<LocalIdentifierLock>(ret_id,p.fd);

    }

}
}
}