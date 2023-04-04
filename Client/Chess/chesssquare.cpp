#include "chesssquare.h"

ChessSquare::ChessSquare(QColor color, int x, int y, int size)
    : QGraphicsRectItem(x, y, size, size), brush(color)
{
    setBrush(brush);
}
