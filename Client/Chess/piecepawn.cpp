
#include "piecepawn.h"

PiecePawn::PiecePawn(Team team)
{
    setTeam(team);
    setType(Type::Pawn);

    //QPixmap pixmap(50, 50);
    //pixmap.fill(Qt::red);
    //setPixmap(pixmap);

    QPixmap pix(":/images/images/black_pawn.png");
    this->setZValue(2.0);
    this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    setZeroMovesAMount();
}

void PiecePawn::calculateMoves()
{
    qDebug() << "piece Pawn calculating";
    if (getTeam() == Team::White) {
        qDebug();
    } else {
        if (getPosPiece().second <= 6) {

            int moveLength;
            if(getMovesAmount() == 0){
                moveLength = 2;
            }
            else{
                moveLength = 1;
            }
            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF(getPosPiece().first * 50 + 25,
                        (getPosPiece().second + moveLength) * 50 + 25));

            qDebug() << "x y move" << getPosPiece().first << getPosPiece().second << moveLength;
            qDebug() << "mapToParent"
                     << QPointF(getPosPiece().first * 50 + 25,
                                (getPosPiece().second + moveLength) * 50 + 25);

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece) {
                    break;
                }
            }

            if((chessPiece && chessPiece->getTeam() != this->getTeam()) || !chessPiece){
                ChessSquare *square = new ChessSquare(Qt::green,
                                                      getPosPiece().first * 50,
                                                      (getPosPiece().second + moveLength) * 50,
                                                      50);
                addMoveSquare(square);
                qDebug() << "ЩА МОЖЕМ ХОДИТЬ";
                square->setZValue(1.0);
                this->scene()->addItem(square);
            }
        }
    }
}


