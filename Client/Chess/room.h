#ifndef ROOM_H
#define ROOM_H

#include "chessview.h"
#include <QWidget>

// #include "chesspiece.h"
#include "piecepawn.h"
#include "pieceknight.h"
#include "piecebishop.h"
#include "piecerook.h"
#include "piecequeen.h"
#include "pieceking.h"
#include <QThread>

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
    bool isObjectCreated() const;
    std::vector<std::vector<ChessPiece*>> boardPieces;
    GameState* state;


private:
    ChessPiece::Type teamToMove;
    Ui::Room *ui;
    bool m_objectCreated;


public slots:
    void startReceiving();
};

#endif // ROOM_H
