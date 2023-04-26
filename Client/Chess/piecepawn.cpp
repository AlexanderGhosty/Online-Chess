
#include "piecepawn.h"

PiecePawn::PiecePawn(GameState::StateTeam team)
{
    setTeam(team);
    setType(Type::Pawn);

    if(getTeam() == GameState::StateTeam::White){
        QPixmap pix(":/images/images/white_pawn");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/images/images/black_pawn");
        this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    }
    this->setZValue(2.0);

    setZeroMovesAMount();
}

void PiecePawn::calculateMoves()
{
    if(getTeam() != getGameState()->getTeamToMove())
        return;
    /*
    int moveLength;
    if(getMovesAmount() == 0){
        moveLength = 2;
    }
    else{
        moveLength = 1;
    }
    */
    qDebug() << "piece Pawn calculating";
    int maxMoveLength;
    int moveLength = 1;
    QList<QGraphicsItem *> items;
    ChessPiece *chessPiece = nullptr;

    if(getMovesAmount() == 0){
        maxMoveLength = 2;
    }
    else{
        maxMoveLength = 1;
    }

    if (getTeam() == GameState::StateTeam::White) {
        if(getPosPiece().second >= 1){
            for(moveLength; moveLength <= maxMoveLength; ++moveLength){
                QList<QGraphicsItem *> items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 + 25,
                            (getPosPiece().second - moveLength) * 50 + 25));

                ChessPiece *chessPiece = nullptr;

                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }

                if(!chessPiece){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50,
                                                          (getPosPiece().second - moveLength) * 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
            items.clear();
            if(getPosPiece().first > 0){
                items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 - 25,
                            (getPosPiece().second - 1) * 50 + 25));

                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }
                if(chessPiece && chessPiece->getTeam() != this->getTeam()){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50 - 50,
                                                          getPosPiece().second * 50 - 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
            items.clear();
            if(getPosPiece().first < 7){
                items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 + 75,
                            (getPosPiece().second - 1) * 50 + 25)); // kill check right

                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }
                if(chessPiece && chessPiece->getTeam() != this->getTeam()){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50 + 50,
                                                          getPosPiece().second * 50 - 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
        }
    } else { // BLACK
        if (getPosPiece().second <= 6) {
            for(moveLength; moveLength <= maxMoveLength; ++moveLength){
                items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 + 25,
                            (getPosPiece().second + moveLength) * 50 + 25));

                /*
                qDebug() << "x y move" << getPosPiece().first << getPosPiece().second << moveLength;
                qDebug() << "mapToParent"
                         << QPointF(getPosPiece().first * 50 + 25,
                                    (getPosPiece().second + moveLength) * 50 + 25);
                */


                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }

                if(!chessPiece){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50,
                                                          (getPosPiece().second + moveLength) * 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
            items.clear();
            if(getPosPiece().first > 0){ // kill check left side
                items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 - 25,
                            (getPosPiece().second + 1) * 50 + 25));

                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }
                if(chessPiece && chessPiece->getTeam() != this->getTeam()){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50 - 50,
                                                          getPosPiece().second * 50 + 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
            items.clear();
            if(getPosPiece().first < 7){
                items = this->scene()->items(
                    QPointF(getPosPiece().first * 50 + 75,
                            (getPosPiece().second + 1) * 50 + 25));

                for (QGraphicsItem *item : items) {
                    chessPiece = dynamic_cast<ChessPiece *>(item);
                    if (chessPiece) {
                        break;
                    }
                }
                if(chessPiece && chessPiece->getTeam() != this->getTeam()){
                    ChessSquare *square = new ChessSquare(Qt::green,
                                                          getPosPiece().first * 50 + 50,
                                                          getPosPiece().second * 50 + 50,
                                                          50);
                    addMoveSquare(square);
                    square->setZValue(1.0);
                    this->scene()->addItem(square);
                }
            }
        }
    }
    qDebug() << "move squares" << getMoveSquares();
}


