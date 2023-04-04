
#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsItem>

class ChessSquare : QGraphicsItem
{
public:
    ChessSquare(QGraphicsItem *parent = nullptr)
        : QGraphicsItem(parent)
    {}
    QRectF boundingRect() const override { return QRectF(0, 0, 50, 50); }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{}
};

class ChessBoard
{

};

class Board
{
public:
    Board();
};

#endif // BOARD_H
