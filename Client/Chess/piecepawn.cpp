
#include "piecepawn.h"

PiecePawn::PiecePawn(Team team)
{
    setTeam(team);
    setType(Type::Pawn);

    //QPixmap pixmap(50, 50);
    //pixmap.fill(Qt::red);
    //setPixmap(pixmap);

    QPixmap pix(":/images/images/white_pawn.png");
    this->setZValue(2.0);
    this->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
}

void PiecePawn::calculateMoves()
{
    qDebug() << "piece Pawn calculating";
    if (getTeam() == Team::White) {
        qDebug();
    } else {
        qDebug();
        if (getPosPiece().second <= 6) {
            qDebug() << "Вы сможете сходить на:" << getPosPiece().second + 1;
            ChessSquare *square = new ChessSquare(Qt::green,
                                                  getPosPiece().first * 50,
                                                  (getPosPiece().second + 1) * 50,
                                                  50);
            addMoveSquare(square);
            qDebug() << getMoveSquares();
            square->setZValue(1.0);
            this->scene()->addItem(square);
        }
    }
}


