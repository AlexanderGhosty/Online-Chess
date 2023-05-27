
#include "gamestate.h"


// 0 - white, 1 - black
// 0, 1, 2, 3, 4, 5, 6, 7 - pawns
// 8, 9 - knights
// 10, 11 - bishops
// 12, 13 - rooks
// 14 - queen
// 15 - king

GameState::GameState(QObject *parent)
{
    // yourTeam = StateTeam::White; // потом исправить. Сейчас для тестов
    teamToMove = StateTeam::White;
    pieceIdCounter = 0;
    // positions.resize(2, std::vector<std::pair<int, int>>(16));
}


// --------------------  team --------------------

GameState::StateTeam GameState::getYourTeam(){
    return this->yourTeam;
}

void GameState::setYourTeam(GameState::StateTeam team){
    this->yourTeam = team;
}

GameState::StateTeam GameState::getTeamToMove(){
    return this->teamToMove;
}

void GameState::changeTeamToMove(){
    if(this->teamToMove == StateTeam::Black){
        this->teamToMove = StateTeam::White;
    }
    else{
        this->teamToMove = StateTeam::Black;
    }
}


//  -------------------- id --------------------

void GameState::changePieceIdCounter(){
    pieceIdCounter = (pieceIdCounter + 1) % 16;
}

int GameState::getPieceIdCounter(){
    return this->pieceIdCounter;
}

std::array<std::array<std::pair<int, int>, 16>,2> GameState::getGameStatePositions(){
    return this->positions;
}

void GameState::resetPieceIdCounter(){
    this->pieceIdCounter = 0;
}

// -------------------- position --------------------

void GameState::changeGameStatePosition(GameState::StateTeam team, int id, int x, int y){
    if(team == StateTeam::White){
        positions[0][id] = std::make_pair(x, y);
    }
    else{
        positions[1][id] = std::make_pair(x, y);
    }
}


// ------------------- server ---------------------

//void GameState::startReceivingSig(){
//    qDebug() << "receive signal";
// }
