
#include "piecepawn.h"

PiecePawn::PiecePawn(Team team)
{
    setTeam(team);
    setType(Type::Pawn);

    //QPixmap pixmap(50, 50);
    //pixmap.fill(Qt::red);
    //setPixmap(pixmap);

<<<<<<< Updated upstream
    QPixmap pix(":/images/images/pawn_black.png");
    this->setZValue(2.0);
    this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    setZeroMoves();
=======
    QPixmap pix(":/images/images/black_pawn.png");
    this->setZValue(2.0);
    this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
    this->setZeroMoveAmount();
>>>>>>> Stashed changes
}

void PiecePawn::calculateMoves()
{
    qDebug() << "piece Pawn calculating";
    if (getTeam() == Team::White) {
        qDebug();
    } else {
        if (getPosPiece().second <= 6) {
            int moveLength;
<<<<<<< Updated upstream
            if (getMovesMade() == 0) {
                moveLength = 2;
            } else {
                moveLength = 1;
            }
            qDebug() << "Вы сможете сходить на:" << getPosPiece().second + moveLength;
=======
            if(this->getMoveAmount() == 0){
                moveLength = 2;
            }
            else{
                moveLength = 1;
            }
>>>>>>> Stashed changes

            QList<QGraphicsItem *> items = this->scene()->items(
                QPointF(getPosPiece().first * 50 + 25,
                        (getPosPiece().second + moveLength) * 50 + 25));

<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
            if(chessPiece && chessPiece->getTeam() != this->getTeam() || !chessPiece){
=======
            if((chessPiece && chessPiece->getTeam() != this->getTeam()) || !chessPiece){
>>>>>>> Stashed changes
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


