#ifndef ROOM_H
#define ROOM_H

#include "chessview.h"
#include <QWidget>


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
    Ui::Room *ui;
};

#endif // ROOM_H
