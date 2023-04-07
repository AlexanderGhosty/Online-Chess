
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QGraphicsPixmapItem>
#include <qgraphicsscene.h>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <qobject.h>
#include "chesssquare.h"
#include <QDebug>



class ChessPiece : public QGraphicsPixmapItem, public QObject
{
public:
    enum class Type{ Pawn };

    enum class Team { White, Black };

    ChessPiece(Type type, Team team);

    void setNewPos(int posX, int posY);
    void setSelectMode(bool selectMode);
    bool isSelected() const;

    Type getType() const;
    Team getTeam() const;
    std::pair<int, int> getPos();

    void calculateMoves();


private:
    int posX;
    int posY;
    Type type;
    Team team;
    bool selected;
    QPointF m_startPos; // for drag and drop
    bool m_isDragging = false;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // CHESSPIECE_H
