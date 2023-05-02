
#include "pieceking.h"

PieceKing::PieceKing(GameState::StateTeam team)
{
    setTeam(team);
    setType(Type::King);

    if(getTeam() == GameState::StateTeam::White){
        QPixmap pix(":/images/images/white_king");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/images/images/black_king");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    this->setZValue(2.0);

    setZeroMovesAMount();
}

void PieceKing::calculateMoves(){
    if(getTeam() != getGameState()->getTeamToMove()) // !!! after tests need to check a your team !!!
        return;
    qDebug() << "piece queen calculating";
    std::pair<int, int> moveCoordinates; // scene coordinates (pixels)

    // top
    moveCoordinates.first = getPos().first * 50;
    moveCoordinates.second = getPos().second * 50 - 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // top-right
    moveCoordinates.first = getPos().first * 50 + 50;
    moveCoordinates.second = getPos().second * 50 - 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // right
    moveCoordinates.first = getPos().first * 50 + 50;
    moveCoordinates.second = getPos().second * 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    //bottom-right
    moveCoordinates.first = getPos().first * 50 + 50;
    moveCoordinates.second = getPos().second * 50 + 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // bottom
    moveCoordinates.first = getPos().first * 50;
    moveCoordinates.second = getPos().second * 50 + 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // bottom-left
    moveCoordinates.first = getPos().first * 50 - 50;
    moveCoordinates.second = getPos().second * 50 + 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    //left
    moveCoordinates.first = getPos().first * 50 - 50;
    moveCoordinates.second = getPos().second * 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    //top-left
    moveCoordinates.first = getPos().first * 50 - 50;
    moveCoordinates.second = getPos().second * 50 - 50;
    tryMove(moveCoordinates.first, moveCoordinates.second);

    // castling
    if(getMovesAmount() == 0){
        // other pieces check
        bool f = false;
        for(int i = 1; i <= 3; ++i){
            f = false;

            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF((getPos().first - i) * 50 + 25, getPos().second * 50 + 25));

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece) {
                    f = true;
                    qDebug() << "u have other pieces on the left side";
                    break;
                }
            }
            if(f)
                break;
        }
        if(!f){ // if space between king and left rook is free
            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF(25, getPos().second * 50 + 25));

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece) {
                    break;
                }
            }
            if(chessPiece && chessPiece->getMovesAmount() == 0){
                ChessSquare *square = new ChessSquare(Qt::green,
                                                      2 * 50, getPos().second * 50,
                                                      50);
                addMoveSquare(square);
                square->setZValue(1.0);
                this->scene()->addItem(square);
            }
        }

        // right

        for(int i = 1; i <= 2; ++i){
            f = false;

            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF((getPos().first + i) * 50 + 25, getPos().second * 50 + 25));

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece) {
                    f = true;
                    qDebug() << "u have other pieces on the left side";
                    break;
                }
            }
            if(f)
                break;
        }
        if(!f){ // if space between king and right rook is free
            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF(7 * 50 + 25, getPos().second * 50 + 25));

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece) {
                    break;
                }
            }
            if(chessPiece && chessPiece->getMovesAmount() == 0){
                ChessSquare *square = new ChessSquare(Qt::green,
                                                      6 * 50, getPos().second * 50,
                                                      50);
                addMoveSquare(square);
                square->setZValue(1.0);
                this->scene()->addItem(square);
            }
        }

    }

}
