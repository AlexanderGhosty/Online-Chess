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

// Server
#pragma comment(lib, "ws2_32.lib")
#include <winsock.h>

//Custom
#include "User.h"
#include "server_functions.h"

constexpr int MAX_PLAYERS = 16;

int main()
{
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
    // Проверка версии DLL
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        std::cout << "The Winsock DLL not found" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Winsock DLL is OK" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
    }
   
    // Создание сокета и выбор TCP
    SOCKET serverListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    // Адрес сокета
    sockaddr_in serverAddr;
    int sizeOfserverAddr = sizeof(serverAddr);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_family = AF_INET;

    // Ассоциация локального адреса и сокета (привязка адреса и порта)
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

    // Прослушивание в поисках подключения
    if (listen(serverListen, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "listen(): Error listening on socket " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "listen() is OK, Waiting for connections" << std::endl;
    }
    
    // Создание массива пользователей
    Users users;

    // Процесс подключения
    SOCKET newConnection;
    while (true)
    {
        // Ограничение макс. числа пользователей
        if (users.get_size() > MAX_PLAYERS)
        {
            // Сон на 5 сек.
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        else
        {
            // Принятие подключения
            newConnection = accept(serverListen, (SOCKADDR*)&serverAddr, &sizeOfserverAddr);

            if (newConnection == 0)
            {
                std::cout << "Connection Error!" << std::endl;
            }
            else
            {
                std::cout << "User connected!" << std::endl;
                users.add_user(newConnection);
            }
        }
    }


	return 0;
}