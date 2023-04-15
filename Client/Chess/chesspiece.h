
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


class ChessPiece : public QGraphicsPixmapItem, public QObject
{
public:
    enum class Type{ Pawn };

    enum class Team { White, Black };

    // ChessPiece(Team team);
    ChessPiece();

    void setType(Type type);
    void setTeam(Team team);
    void setNewPos(int posX, int posY);
    std::pair<int, int> getPosPiece();
    void setSelectMode(bool selectMode);
    bool isSelected() const;

    Type getType() const;
    Team getTeam() const;
    std::pair<int, int> getPos();



    virtual void calculateMoves() = 0;

    // places where a chesspiece can move
    void addMoveSquare(ChessSquare* moveSquare);
    std::vector <ChessSquare*> getMoveSquares();

    // moves
    int getMovesAmount();
    void setZeroMovesAMount();
    void addAMove();

    // id features
    //int GetID() const;
    //void setId();

private:
    int posX;
    int posY;
    Type type;
    Team team;
    bool selected;
    QPointF m_startPos; // for drag and drop
    bool m_isDragging = false;
    std::vector <ChessSquare*> moveSquares; // x and y of a place where player could move
    int movesAmount;

    static int idCount;
    int m_id;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // CHESSPIECE_H
