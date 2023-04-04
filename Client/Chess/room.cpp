#include "room.h"
#include "ui_room.h"


Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
    view = new ChessView(this);
    ui->plateLayout->addWidget(view);
    scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // отключаем вертикальную полосу прокрутки
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Room::~Room()
{
    delete ui;
}
