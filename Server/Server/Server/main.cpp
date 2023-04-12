#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

// Multithreading
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>

// Server
#pragma comment(lib, "ws2_32.lib")
#include <winsock.h>

//Custom
#include "User.h"
#include "server_functions.h"
#include "ServerData.h"

//constexpr int MAX_PLAYERS = 16;

int main()
{
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
    // Checking the DLL version
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        std::cout << "The Winsock DLL not found " << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Winsock DLL is OK" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
    }
   
    // Socket creation and TCP selection
    SOCKET serverListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    // Socket address
    sockaddr_in serverAddr;
    int sizeOfserverAddr = sizeof(serverAddr);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_family = AF_INET;

    // Local address and socket association (address and port binding)
    if (bind(serverListen, (SOCKADDR*)&serverAddr, sizeOfserverAddr) == SOCKET_ERROR)
    {
        std::cout << "bind failed " << WSAGetLastError() << std::endl;
        closesocket(serverListen);
        WSACleanup();
        return 1;
    }
    else
    {
        std::cout << "bind() is OK" << std::endl;
    }

    // Listening in search of connection
    if (listen(serverListen, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "listen(): Error listening on socket " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "listen() is OK, Waiting for connections" << std::endl;
    }
    
    ServerData serverData;

    // Connection process
    SOCKET newConnection;
    while (true)
    {
        // Checking for availability of slots
        if (serverData.is_full())
        {
            // Sleep for 5 seconds.
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        else
        {
            // Accepting the connection
            newConnection = accept(serverListen, (SOCKADDR*)&serverAddr, &sizeOfserverAddr);

            if (newConnection == 0)
            {
                std::cout << "Connection Error!" << std::endl;
            }
            else
            {
                std::cout << "User connected! " << newConnection << std::endl;
                User user(newConnection);
                std::async(std::launch::async, userHandler, user, std::ref(serverData));
            }
        }
    }


	return 0;
}