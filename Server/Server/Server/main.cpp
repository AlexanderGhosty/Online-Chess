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
#include <WinSock2.h>
#include <WS2tcpip.h>

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
        std::cout << "Error Winsock version " << std::endl;
        std::cout << WSAGetLastError() << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Winsock DLL is OK" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
    }
   
    // Socket creation and TCP selection
    SOCKET serverListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverListen == INVALID_SOCKET)
    {
        std::cout << "Error socket initializtion  " << WSAGetLastError() << std::endl;
        closesocket(serverListen);
        WSACleanup();
        return 1;
    }
    else 
    {
        std::cout << "serverListen socket init. is OK" << std::endl;
    }

    // IP translation to special numeric format
    in_addr ip_to_num;
    if (inet_pton(AF_INET, "127.0.0.1", &ip_to_num) <= 0) 
    {
        std::cout << "Error in IP translation to special numeric format" << std::endl;
        return 1;
    }

    // Socket address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr = ip_to_num;
    serverAddr.sin_port = htons(8080);
    int sizeOfserverAddr = sizeof(serverAddr);
 

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
        std::cout << "listen() is OK, Waiting for connections..." << std::endl;
    }
    
    ServerData serverData;
    serverData.change_max_users(4);

    // Connection process
    SOCKET newConnection;
    while (true)
    {
        // Checking for availability of slots
        if (serverData.is_full())
        {
            // Sleep for 5 seconds.
            newConnection = accept(serverListen, (SOCKADDR*)&serverAddr, &sizeOfserverAddr);
            closesocket(newConnection);
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        else
        {
            // Accepting the connection
            newConnection = accept(serverListen, (SOCKADDR*)&serverAddr, &sizeOfserverAddr);

            if (newConnection == INVALID_SOCKET)
            {
                std::cout << "Client tryied to connect, but an error occurred!" << std::endl;
            }
            else
            {
                std::cout << "User connected successfully! " << newConnection << std::endl;
                User user(newConnection);
                std::thread thread(userHandler, user, std::ref(serverData));
                // std::async(std::launch::async, userHandler, user, std::ref(serverData));
                serverData.add_number_of_users();
                thread.detach();
            }
        }
    }
    closesocket(serverListen);
    closesocket(newConnection);
    WSACleanup();

	return 0;
}