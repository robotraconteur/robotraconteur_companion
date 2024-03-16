/**
 * @file TestFixtures.h
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

#include <RobotRaconteur.h>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
    /**
     * @brief A test fixture for intra-process testing using Robot Raconteur.
     * 
     * The IntraTestFixture class provides a convenient way to set up and tear down
     * the necessary components for intra-process testing using Robot Raconteur.
     * It initializes client and server nodes, registers transport, service types,
     * and provides methods to register services and connect to services.
     * 
     * To use this test fixture, create an instance of IntraTestFixture in your test
     * and call the necessary methods to set up the test environment. The fixture will
     * automatically clean up the resources when it goes out of scope.
     */
    class IntraTestFixture
    {
    public:
        /**
         * @brief The client node
         * 
         */
        RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> client_node;
        /**
         * @brief The server node
         * 
         */
        RR_SHARED_PTR<RobotRaconteur::RobotRaconteurNode> server_node;

        /**
         * @brief The client transport
         * 
         */
        RR_SHARED_PTR<RobotRaconteur::IntraTransport> client_transport;
        /**
         * @brief The server transport
         * 
         */
        RR_SHARED_PTR<RobotRaconteur::IntraTransport> server_transport;

        /**
         * @brief Construct a new IntraTestFixture object
         * 
         * The constructor initializes the client and server nodes, registers the
         * intra-process transport, and starts the transport.
         * 
         */
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

        /**
         * @brief Register a service type to the client and server nodes
         * 
         * This method registers a service type to the client and server nodes.
         * 
         * @tparam T The service type to register
         */
        template<typename T>
        void RegisterServiceType()
        {
            client_node->RegisterServiceType(RR_MAKE_SHARED<T>());
            server_node->RegisterServiceType(RR_MAKE_SHARED<T>());
        }

        /**
         * @brief Register a service to the server node
         * 
         * 
         * @param name The name of the service
         * @param type The service type
         * @param obj The service object
         */
        void RegisterService(const std::string& name, const std::string& type, const RR_SHARED_PTR<RRObject>& obj) const
        {
            server_node->RegisterService(name, type, obj);
        }

        /**
         * @brief Connect to a service on the server node
         * 
         * 
         * @param url The URL of the service
         * @return RR_SHARED_PTR<RRObject> 
         */
        RR_SHARED_PTR<RRObject> ConnectService(const std::string& url) const
        {
            return client_node->ConnectService(url);
        }

        /**
         * @brief Shutdown the client and server nodes
         * 
         * This method shuts down the client and server nodes and stops the transport.
         * Shutdown is also automatically called when the fixture goes out of scope.
         * 
         */
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