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

    // ChessPiece* piece = new ChessPiece(ChessPiece::Team::White);
    /*QPixmap pixmap;
    pixmap.load("C:/Programming/GitHub/Online-Chess/Client/Chess/imageswhite_pawn.png");
    piece->setPixmap(pixmap);*/

    PiecePawn *piece = new PiecePawn(PiecePawn::Team::Black);

    piece->setNewPos(0,0);
    piece->setParent(view->board);
    view->board->addItem(piece);

    PiecePawn *piece1 = new PiecePawn(PiecePawn::Team::Black);

    piece1->setNewPos(0,200);
    piece1->setParent(view->board);
    view->board->addItem(piece1);
}

Room::~Room()
{
    delete ui;
}
