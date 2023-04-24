#include "room.h"
#include "ui_room.h"
#include <QDebug>


Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    m_objectCreated = false;

    ui->setupUi(this);
    qDebug() << "ui setup done";
    view = new ChessView(this);
    qDebug() << "chessView created";
    ui->plateLayout->addWidget(view);
    qDebug() << "view added to ui";
    view->setMaximumSize(450,450);


    GameState* state = new GameState();
    qDebug() << "GameState created";
/*
    PiecePawn *piece = new PiecePawn(GameState::StateTeam::Black);
    piece->setGameState(state);
    piece->setNewPos(00, 50);
    piece->setId(state->getPieceIdCounter());
    state->changePieceIdCounter();
    view->board->addItem(piece);
*/
    for(int i = 0; i < 8; ++i){
        PiecePawn *pawn = new PiecePawn(GameState::StateTeam::Black);
        // qDebug() << "id:" << state->getPieceIdCounter();
        // qDebug() << "0";
        pawn->setGameState(state);
        // qDebug() << "1";
        pawn->setId(state->getPieceIdCounter());
        // qDebug() << "2";
        state->changePieceIdCounter();
        // qDebug() << "3";
        pawn->setNewPos(i * 50, 50);
        // qDebug() << "4";
        view->board->addItem(pawn);
        // qDebug() << i << "pawn created";
    }

    qDebug() << "Black team created";

    for(int i = 0; i < 8; ++i){
        PiecePawn *pawn = new PiecePawn(GameState::StateTeam::White);
        pawn->setGameState(state);
        pawn->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        pawn->setNewPos(i * 50, 300);
        view->board->addItem(pawn);
    }
    qDebug() << "White team created";
    m_objectCreated = true;
    qDebug() << "Constructor end";
}

Room::~Room()
{
    delete ui;
}

bool Room::isObjectCreated() const{
    return m_objectCreated;
}
