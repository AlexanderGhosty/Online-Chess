
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "room.h"
#include <QProgressDialog>
#include <thread>
#include <chrono>
#include <future>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createRoomBtn_clicked();

private:
    Ui::MainWindow *ui;
    Room *roomWindow;
};

#endif // MAINWINDOW_H
