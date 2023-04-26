
#include "pieceknight.h"

PieceKnight::PieceKnight(GameState::StateTeam team)
{
    setTeam(team);
    setType(Type::Bishop);

    if(getTeam() == GameState::StateTeam::White){
        QPixmap pix(":/images/images/white_knight");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/images/images/black_knight");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    this->setZValue(2.0);

    setZeroMovesAMount();
}


void PieceKnight::calculateMoves(){
    if(getTeam() != getGameState()->getTeamToMove()) // !!! after tests need to check a your team !!!
        return;
    qDebug() << "piece knight calculating";
    std::pair<int, int> moveCoordinates; // scene coordinates (pixels)

    // top -> left
    moveCoordinates.first = getPos().first * 50 - 50;
    moveCoordinates.second = getPos().second * 50 - 50 * 2;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // left -> top
    moveCoordinates.first = getPos().first * 50 - 50 * 2;
    moveCoordinates.second = getPos().second * 50 - 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // top -> right
    moveCoordinates.first = getPos().first * 50 + 50;
    moveCoordinates.second = getPos().second * 50 - 50 * 2;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // right -> top
    moveCoordinates.first = getPos().first * 50 + 50 * 2;
    moveCoordinates.second = getPos().second * 50 - 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // bottom -> left
    moveCoordinates.first = getPos().first * 50 - 50;
    moveCoordinates.second = getPos().second * 50 + 50 * 2;
    tryMove(moveCoordinates.first, moveCoordinates.second);
    // left -> bottom
    moveCoordinates.first = getPos().first * 50 - 50 * 2;
    moveCoordinates.second = getPos().second * 50 + 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // bottom -> right
    moveCoordinates.first = getPos().first * 50 + 50;
    moveCoordinates.second = getPos().second * 50 + 50 * 2;
    tryMove(moveCoordinates.first, moveCoordinates.second);
    // right -> bottom
    moveCoordinates.first = getPos().first * 50 + 50 * 2;
    moveCoordinates.second = getPos().second * 50 + 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);
}

