
#include "chessboard.h"

ChessBoard::ChessBoard()
{
    int size = 50;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            QColor color;
            if ((i + j) % 2 == 0) {
                color = Qt::white;
            } else {
                color = Qt::gray;
            }
            ChessSquare *square = new ChessSquare(color, x, y, size);
            square->setZValue(0.0);
            addItem(square);
            squares.append(square);
            x += size;
        }
        x = 0;
        y += size;
    }
}
