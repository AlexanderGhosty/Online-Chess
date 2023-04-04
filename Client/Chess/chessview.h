
#ifndef CHESSVIEW_H
#define CHESSVIEW_H


#include "chessboard.h"
#include <QGraphicsView>

class ChessView : public QGraphicsView
{
public:
    ChessView(QWidget *parent = nullptr);
};


#endif // CHESSVIEW_H
