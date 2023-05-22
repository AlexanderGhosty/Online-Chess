
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QGraphicsPixmapItem>
#include <qgraphicsscene.h>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <qobject.h>
#include "chesssquare.h"
#include <QDebug>
#include <vector>
#include "gamestate.h"


class ChessPiece : public QGraphicsPixmapItem, public QObject
{
public:
    enum class Type{ Pawn, Knight, Bishop, Rook, Queen, King };

    ChessPiece();

    void setType(Type type);
    void setTeam(GameState::StateTeam team);
    void setNewPos(int posX, int posY);
    std::pair<int, int> getPosPiece();
    void setSelectMode(bool selectMode);
    bool isSelected() const;

    Type getType() const;
    GameState::StateTeam getTeam() const;
    std::pair<int, int> getPos();



    virtual void calculateMoves() = 0;

    // places where a chesspiece can move
    void addMoveSquare(ChessSquare* moveSquare);
    std::vector <ChessSquare*> getMoveSquares();

    // moves
    int getMovesAmount();
    void setZeroMovesAMount();
    void addAMove();
    bool tryMove(int x, int y); // top left corner of a chess square

    // id features
    int getID();
    void setId(int m_id);

    // game state
    void setGameState(GameState* gameState);
    GameState* getGameState();


private:
    int posX; // cell position (not pixels)
    int posY;
    Type type;
    GameState::StateTeam team;
    bool selected;
    QPointF m_startPos; // for drag and drop
    bool m_isDragging = false;

    std::vector <ChessSquare*> moveSquares; // x and y of a place where player could move to
    int movesAmount;
    int m_id;
    GameState* gameState;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // CHESSPIECE_H
