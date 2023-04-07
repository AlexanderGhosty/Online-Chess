#ifndef ROOM_H
#define ROOM_H

#include "chessview.h"
#include <QWidget>
#include "chesspiece.h"

namespace Ui {
class Room;
}

class Room : public QWidget
{
    Q_OBJECT

public:
    explicit Room(QWidget *parent = nullptr);
    ~Room();
    ChessView *view;
    QScrollArea *scrollArea;


private:
    ChessPiece::Type teamToMove;
    Ui::Room *ui;
};

#endif // ROOM_H
