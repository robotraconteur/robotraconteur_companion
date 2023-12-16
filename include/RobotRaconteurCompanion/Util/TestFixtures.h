#include <RobotRaconteur.h>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    class IntraTestFixture
    {
    public:
        RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> client_node;
        RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> server_node;

        RR_SHARED_PTR<RobotRaconteur::IntraTransport> client_transport;
        RR_SHARED_PTR<RobotRaconteur::IntraTransport> server_transport;

        IntraTestFixture()
        {
            client_node = RR_MAKE_SHARED<RobotRaconteur::RobotRaconteurNode>();
            server_node = RR_MAKE_SHARED<RobotRaconteur::RobotRaconteurNode>();

            client_node->SetNodeName("client_node");
            server_node->SetNodeName("server_node");

            client_node->Init();
            server_node->Init();

            client_transport = RR_MAKE_SHARED<RobotRaconteur::IntraTransport>(client_node);
            server_transport = RR_MAKE_SHARED<RobotRaconteur::IntraTransport>(server_node);

            client_node->RegisterTransport(client_transport);
            server_node->RegisterTransport(server_transport);

            client_transport->StartClient();
            server_transport->StartServer();
        }

        template<typename T>
        void RegisterServiceType()
        {
            client_node->RegisterServiceType(RR_MAKE_SHARED<T>());
            server_node->RegisterServiceType(RR_MAKE_SHARED<T>());
        }

        void RegisterService(const std::string& name, const std::string& type, RR_SHARED_PTR<RRObject> obj)
        {
            server_node->RegisterService(name, type, obj);
        }

        RR_SHARED_PTR<RRObject> ConnectService(const std::string& url)
        {
            return client_node->ConnectService(url);
        }

        void Shutdown()
        {
            if (!client_node) return;
            client_node->Shutdown();
            server_node->Shutdown();
            client_node.reset();
            server_node.reset();
        }

        ~IntraTestFixture()
        {
            Shutdown();
        }
    };
}
}
}