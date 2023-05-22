
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    SOCKET Connection;
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 2);
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        // std::cout << "Error" << std::endl;
        exit(1);
    }

    // IP translation to special numeric format
    in_addr ip_to_num;
    if (inet_pton(AF_INET, "26.154.166.60", &ip_to_num) <= 0)
    {
        // std::cout << "Error in IP translation to special numeric format" << std::endl;
        return 1;
    }

    SOCKADDR_IN addr;
    int sizeOfaddr = sizeof(addr);
    addr.sin_addr = ip_to_num;
    addr.sin_port = htons(4899);
    addr.sin_family = AF_INET;

    // создание сокета для подключения
    Connection = socket(AF_INET, SOCK_STREAM, NULL);

    // подключение к серверу (ждет 75 сек. ответа от сервера)
    do
    {
        qDebug() << "Error: failed connect to server.\n";
    } while(connect(Connection, (SOCKADDR*)&addr, sizeOfaddr) != 0);
    // std::cout << "Connection established\n";

    QApplication a(argc, argv);
    MainWindow w;
    w.setConnection(Connection);
    w.show();
    return a.exec();
}
