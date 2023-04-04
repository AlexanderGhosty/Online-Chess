
#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QGraphicsRectItem>
#include <QBrush>

class ChessSquare : public QGraphicsRectItem
{
public:
    ChessSquare(QColor color, int x, int y, int size);

private:
    QBrush brush;
};

#endif // CHESSSQUARE_H
