#include "room.h"
#include "ui_room.h"
#include <QDebug>


Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
    // qDebug() << "1";
    view = new ChessView(this);
    // qDebug() << "2";
    ui->plateLayout->addWidget(view);
    // qDebug() << "3";
    view->setMaximumSize(450,450);

    // ChessPiece* piece = new ChessPiece(ChessPiece::Team::White);
    /*QPixmap pixmap;
    pixmap.load("C:/Programming/GitHub/Online-Chess/Client/Chess/imageswhite_pawn.png");
    piece->setPixmap(pixmap);*/
    // qDebug() << "4";
    GameState* state;
    PiecePawn *piece = new PiecePawn(PiecePawn::Team::Black);
    piece->setGameState(state);
    // qDebug() << "5";
    piece->setNewPos(0,0);
    // qDebug() << "6";
    piece->setParent(view->board);
    // qDebug() << "7";
    view->board->addItem(piece);
    // qDebug() << "8";
    PiecePawn *piece1 = new PiecePawn(PiecePawn::Team::White);
    piece1->setGameState(state);
    piece1->setNewPos(0,350);
    piece1->setParent(view->board);
    view->board->addItem(piece1);
}

Room::~Room()
{
    delete ui;
}
