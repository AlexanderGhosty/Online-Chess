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


    GameState* state = new GameState();

    PiecePawn *piece = new PiecePawn(GameState::StateTeam::Black);
    piece->setGameState(state);
    piece->setNewPos(50, 50);
    piece->setParent(view->board);
    piece->setId(state->getPieceIdCounter());
    state->changePieceIdCounter();
    view->board->addItem(piece);

    PiecePawn *piece1 = new PiecePawn(GameState::StateTeam::White);
    piece1->setGameState(state);
    piece1->setNewPos(0, 300);
    piece1->setParent(view->board);
    piece1->setId(state->getPieceIdCounter());
    state->changePieceIdCounter();
    view->board->addItem(piece1);

    PiecePawn *piece2 = new PiecePawn(GameState::StateTeam::White);
    piece2->setGameState(state);
    piece2->setNewPos(100, 300);
    piece2->setParent(view->board);
    piece2->setId(state->getPieceIdCounter());
    state->changePieceIdCounter();
    view->board->addItem(piece2);

    PiecePawn *piece3 = new PiecePawn(GameState::StateTeam::Black);
    piece3->setGameState(state);
    piece3->setNewPos(150, 50);
    piece3->setParent(view->board);
    piece3->setId(state->getPieceIdCounter());
    state->changePieceIdCounter();
    view->board->addItem(piece3);
}

Room::~Room()
{
    delete ui;
}
