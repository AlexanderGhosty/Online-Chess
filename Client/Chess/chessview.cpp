#include "chessview.h"

ChessView::ChessView(QWidget *parent)
    : QGraphicsView(parent)
{
    setScene(new ChessBoard());
    setRenderHint(QPainter::Antialiasing);
    setMinimumSize(400, 400);
}
