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


    state = new GameState(nullptr);

    qDebug() << "GameState created";
    boardPieces.resize(2, std::vector<ChessPiece*>(0));

    QObject::connect(state, &GameState::startReceivingSig, this, &Room::startReceiving);

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
        boardPieces[0].push_back(pawn);

        qDebug() << "pawn" << pawn->getID();
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
        boardPieces[0].push_back(knight);

        qDebug() << "knight" << knight->getID();
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
        boardPieces[0].push_back(bishop);

        qDebug() << "bishop" << bishop->getID();
    }

    // ---- creating rook ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceRook* rook = new PieceRook(GameState::StateTeam::White);
        rook->setGameState(state);
        rook->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        rook->setNewPos(i * 50 * 7, 50 * 7);
        view->board->addItem(rook);
        boardPieces[0].push_back(rook);

        qDebug() << "rook" <<rook->getID();
    }

    // ---- creating queen ----
    qDebug() << state->getPieceIdCounter();
    for(;;){
        PieceQueen *queen = new PieceQueen(GameState::StateTeam::White);
        queen->setGameState(state);
        queen->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        queen->setNewPos(50 * 3, 50 * 7);
        view->board->addItem(queen);
        boardPieces[0].push_back(queen);

        qDebug() << "queen" <<queen->getID();
        break;
    }

    // ---- creating king ----
    qDebug() << state->getPieceIdCounter();
    for(;;){
        PieceKing *king = new PieceKing(GameState::StateTeam::White);
        king->setGameState(state);
        king->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        king->setNewPos(50 * 4, 50 * 7);
        view->board->addItem(king);
        boardPieces[0].push_back(king);

        qDebug() << "king" <<king->getID();
        break;
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
        boardPieces[1].push_back(pawn);
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
        boardPieces[1].push_back(knight);
    }

    // ---- creating bishop ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceBishop *bishop = new PieceBishop(GameState::StateTeam::Black);
        bishop->setGameState(state);
        bishop->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        bishop->setNewPos(50 * 2 + i * 50 * 3, 0);
        view->board->addItem(bishop);
        boardPieces[1].push_back(bishop);
    }

    // ---- creating rook ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 2; ++i){
        PieceRook *rook = new PieceRook(GameState::StateTeam::Black);
        rook->setGameState(state);
        rook->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        rook->setNewPos(i * 50 * 7, 0);
        view->board->addItem(rook);
        boardPieces[1].push_back(rook);
    }

    // ---- creating queen ----
    qDebug() << state->getPieceIdCounter();
    for(int i = 0; i < 1; ++i){
        PieceQueen *queen = new PieceQueen(GameState::StateTeam::Black);
        queen->setGameState(state);
        queen->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        queen->setNewPos(50 * 3, 0);
        view->board->addItem(queen);
        boardPieces[1].push_back(queen);
    }

    // ---- creating king ----
    qDebug() << state->getPieceIdCounter();
    for(;;){
        PieceKing *king = new PieceKing(GameState::StateTeam::Black);
        king->setGameState(state);
        king->setId(state->getPieceIdCounter());
        state->changePieceIdCounter();
        king->setNewPos(50 * 4, 0);
        view->board->addItem(king);
        boardPieces[1].push_back(king);
        break;
    }
    qDebug() << "Black team created";

    m_objectCreated = true;
    qDebug() << "Constructor end";


    // view->board->addItem(piece);

    // PiecePawn *piece1 = new PiecePawn(PiecePawn::Team::Black);
    //piece1->setNewPos(0,150);
}

Room::~Room()
{
    delete ui;
}

bool Room::isObjectCreated() const{
    return m_objectCreated;
}

void Room::startReceiving(){
    qDebug() << "Receiving Started";
    // ---------------------------------
    // ---- ADD RECEIVING & analyze ----
    // ---------------------------------
    std::vector<std::vector<std::pair<int, int>>> receivingPositions(2, std::vector<std::pair<int,int>>(16));

    while (recv(state->connection, (char*)&receivingPositions, sizeof(receivingPositions), NULL) == -1)
    {
        QThread::msleep(1);
    }
    qDebug() << "1";
    qDebug() << "received data" << receivingPositions[0][0].first;
    int teamNum;
    if(state->getYourTeam() == GameState::StateTeam::White){
        teamNum = 1;
    }
    else{
        teamNum = 0;
    }
    for (int id = 0; id < 16; ++id) {
        boardPieces[teamNum][id]->setNewPos(receivingPositions[teamNum][id].first, receivingPositions[teamNum][id].second);
    }
    state->changeTeamToMove();
}
