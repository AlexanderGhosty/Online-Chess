
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
    QByteArray byteArray = this->ui->titleLineEdit->text().toUtf8();
    send(connection, byteArray.constData(),sizeof(byteArray.constData()), NULL);
    byteArray = this->ui->passwordLineEdit->text().toUtf8();
    send(connection, byteArray.constData(),sizeof(byteArray.constData()), NULL);
    char isCreate[1] = {'1'};
    send(connection, (char*)isCreate,sizeof(isCreate), NULL);
    bool isValid = false;

    recv(connection, (char*)isValid,sizeof(isValid), NULL);

    if(isValid){
        this->ui->resultLabel->setText("ТАК КОМНАТА СУЩЕСТВУЕТ");
        return;
    }

    roomWindow = new Room(nullptr);
    roomWindow->state->connection = connection;
    roomWindow->state->setYourTeam(GameState::StateTeam::White);

    // QProgressDialog progressDialog("Loading data...", QString(), 0, 0, qobject_cast<QWidget*>(parent()), Qt::CustomizeWindowHint);
    // progressDialog.setWindowModality(Qt::WindowModal); // Делаем окно модальным
    // progressDialog.show();
    /*
    auto waitingLambda = [=](){
        while(!roomWindow->isObjectCreated()){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            qDebug() << "Waiting for room loading";

        }
    };
    std::thread waitThread(waitingLambda);
    waitThread.join();
    */
    qDebug() << "Room has been loaded";
    roomWindow->show();

    this->close();
}

void MainWindow::on_joinRoomBtn_clicked()
{
    QByteArray byteArray = this->ui->titleLineEdit->text().toUtf8();
    send(connection, byteArray.constData(),sizeof(byteArray.constData()), NULL);
    byteArray = this->ui->passwordLineEdit->text().toUtf8();
    send(connection, byteArray.constData(),sizeof(byteArray.constData()), NULL);
    // bool isCreate = false;
    char isCreate[1] = {'0'};
    send(connection, (char*)isCreate,sizeof(isCreate), NULL);
    bool isValid = false;

    recv(connection, (char*)isValid,sizeof(isValid), NULL);

    if(isValid){
        this->ui->resultLabel->setText("ТАК КОМНАТА НЕ СУЩЕСТВУЕТ");
        return;
    }

    roomWindow = new Room(nullptr);
    roomWindow->state->connection = connection;
    roomWindow->state->setYourTeam(GameState::StateTeam::Black);

    qDebug() << "Room has been loaded";
    roomWindow->show();
    this->close();
    QThread::sleep(1);
    roomWindow->startReceiving();
}

void MainWindow::setConnection(SOCKET connection){
    this->connection = connection;
}

SOCKET MainWindow::getConnection(){
    return this->connection;
}




