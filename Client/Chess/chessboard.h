
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chesssquare.h"
#include <QGraphicsScene>

class ChessBoard : public QGraphicsScene
{
public:
    ChessBoard();

private:
    QList<ChessSquare*> squares;
};


#endif // CHESSBOARD_H
