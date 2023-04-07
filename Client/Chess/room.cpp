#include "room.h"
#include "ui_room.h"
#include <QDebug>


Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);

    view = new ChessView(this);
    ui->plateLayout->addWidget(view);
    view->setMaximumSize(450,450);

    ChessPiece* piece = new ChessPiece(ChessPiece::Type::Pawn, ChessPiece::Team::White);
    /*QPixmap pixmap;
    pixmap.load("C:/Programming/GitHub/Online-Chess/Client/Chess/imageswhite_pawn.png");
    piece->setPixmap(pixmap);*/
    piece->setPos(0,0);
    view->board->addItem(piece);
}

Room::~Room()
{
    delete ui;
}
