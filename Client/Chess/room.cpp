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



    // --------------------- CREATING WHITE TEAM ---------------------
    // ---- creating pawn ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 8; ++i){
        PiecePawn *pawn = new PiecePawn(GameState::StateTeam::White);
        pawn->setGameState(state);
        pawn->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        pawn->setNewPos(i * 50, 300);
        view->board->addItem(pawn);
    }

    // ---- creating knight ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceKnight *knight = new PieceKnight(GameState::StateTeam::White);
        knight->setGameState(state);
        knight->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        knight->setNewPos(50 + i * 50 * 5, 50 * 7);
        view->board->addItem(knight);
    }

    // ---- creating bishop ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceBishop *bishop = new PieceBishop(GameState::StateTeam::White);
        bishop->setGameState(state);
        bishop->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        bishop->setNewPos(50 * 2 + i * 50 * 3, 50 * 7);
        view->board->addItem(bishop);
    }
    qDebug() << "White team created";


    // --------------------- CREATING BLACK TEAM ---------------------
    // ---- creating pawn ----
    state->resetPieceIdCounter();
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 8; ++i){
        PiecePawn *pawn = new PiecePawn(GameState::StateTeam::Black);
        pawn->setGameState(state);
        pawn->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        pawn->setNewPos(i * 50, 50);
        view->board->addItem(pawn);
    }

    // ---- creating knight ----
    qDebug() <<  state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceKnight *knight = new PieceKnight(GameState::StateTeam::Black);
        knight->setGameState(state);
        knight->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        knight->setNewPos(50 + i * 50 * 5, 0);
        view->board->addItem(knight);
    }

    qDebug() << "Black team created";

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
