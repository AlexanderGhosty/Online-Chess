#include "chessview.h"

ChessView::ChessView(QWidget *parent)
    : QGraphicsView(parent)
{
    board = new ChessBoard();
    setScene(board);
    setRenderHint(QPainter::Antialiasing);
    setMinimumSize(400, 400);
}
