
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(700, 350);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createRoomBtn_clicked()
{
    roomWindow = new Room(nullptr);

    // QProgressDialog progressDialog("Loading data...", QString(), 0, 0, qobject_cast<QWidget*>(parent()), Qt::CustomizeWindowHint);
    // progressDialog.setWindowModality(Qt::WindowModal); // Делаем окно модальным
    // progressDialog.show();
    auto waitingLambda = [=](){
        while(!roomWindow->isObjectCreated()){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            qDebug() << "Waiting for room loading";

        }
    };
    std::thread waitThread(waitingLambda);
    waitThread.join();
    qDebug() << "Room has been loaded";
    roomWindow->show();

    this->close();
}

