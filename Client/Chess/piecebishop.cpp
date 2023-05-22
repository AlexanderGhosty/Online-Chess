
#include "piecebishop.h"

PieceBishop::PieceBishop(GameState::StateTeam team)
{
    setTeam(team);
    setType(Type::Bishop);

    if(getTeam() == GameState::StateTeam::White){
        QPixmap pix(":/images/images/white_bishop");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/images/images/black_bishop");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    this->setZValue(2.0);

    setZeroMovesAMount();
}

void PieceBishop::calculateMoves(){
    if(getTeam() != getGameState()->getTeamToMove()) // !!! after tests need to check a your team !!!
        return;
    qDebug() << "piece bishop calculating";
    std::pair<int, int> moveCoordinates; // scene coordinates (pixels)

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


