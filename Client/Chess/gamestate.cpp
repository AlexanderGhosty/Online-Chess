
#include "gamestate.h"


// 0 - белые, 1 - Черные
// 0, 1, 2, 3, 4, 5, 6, 7, 8 - пешки
// 9, 10 - кони белых
// 11, 12 - слоны
// 13, 14 - ладья
// 15 - ферзь
// 16 - слон

GameState::GameState()
{
    yourTeam = StateTeam::White;
    positions.resize(2, std::vector<std::pair<int, int>>(16));
    teamToMove = StateTeam::White; // потом исправить. Сейчасд для тестов
    pieceIdCounter = 0;
}

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
/*
void changePieceIdCounter();
int getPieceIdCounter();
*/

void GameState::changePieceIdCounter(){
    ++pieceIdCounter;
}

int GameState::getPieceIdCounter(){
    return pieceIdCounter;
}

std::vector<std::vector<std::pair<int, int>>> GameState::getGameStatePositions(){
    return this->positions;
}

void GameState::changeGameStatePosition(GameState::StateTeam team, int id, int x, int y){
    if(team == StateTeam::White){
        positions[0][id] = std::make_pair(x, y);
    }
    else{
        positions[1][id] = std::make_pair(x, y);
    }
}
