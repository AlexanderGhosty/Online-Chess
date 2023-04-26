
#include "piecequeen.h"

PieceQueen::PieceQueen(GameState::StateTeam team)
{
    setTeam(team);
    setType(Type::Queen);

    if(getTeam() == GameState::StateTeam::White){
        QPixmap pix(":/images/images/white_queen");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/images/images/black_queen");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    this->setZValue(2.0);

    setZeroMovesAMount();
}

void PieceQueen::calculateMoves(){
    if(getTeam() != getGameState()->getTeamToMove()) // !!! after tests need to check a your team !!!
        return;
    qDebug() << "piece queen calculating";
    std::pair<int, int> moveCoordinates; // scene coordinates (pixels)

    // top
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50;
        moveCoordinates.second = getPos().second * 50 - 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }

    // bottom
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50;
        moveCoordinates.second = getPos().second * 50 + 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }
    // left
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 - 50 * i;
        moveCoordinates.second = getPos().second * 50;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }
    // right
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 + 50 * i;
        moveCoordinates.second = getPos().second * 50;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }

    // top-left
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 - 50 * i;
        moveCoordinates.second = getPos().second * 50 - 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }

    // top-right
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 + 50 * i;
        moveCoordinates.second = getPos().second * 50 - 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }

    // bottom-left
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 - 50 * i;
        moveCoordinates.second = getPos().second * 50 + 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }

    // bottom-right
    for(int i = 1;; ++i){
        moveCoordinates.first = getPos().first * 50 + 50 * i;
        moveCoordinates.second = getPos().second * 50 + 50 * i;
        if(!tryMove(moveCoordinates.first, moveCoordinates.second)){
            break;
        }
    }
}

