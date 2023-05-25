
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "room.h"
#include <QProgressDialog>
#include <thread>
#include <chrono>
#include <future>
#include <QThread>>

// SERVER include
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>

#include <QThread>
// END SERVER

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setConnection(SOCKET connection);
    SOCKET getConnection();

private slots:
    void on_createRoomBtn_clicked();


    void on_joinRoomBtn_clicked();

private:
    Ui::MainWindow *ui;
    Room *roomWindow;
    SOCKET connection;
};

#endif // MAINWINDOW_H
