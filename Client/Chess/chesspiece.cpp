
#include "chesspiece.h"

ChessPiece::ChessPiece(Type type, Team team) :
    type(type),
    team(team),
    selected(false)
{

    // ниже стереть
    
    QPixmap pixmap(50, 50);
    pixmap.fill(Qt::red);
    setPixmap(pixmap);
}

//bool canMoveTo(int posX, int posY);

void ChessPiece::setNewPos(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void ChessPiece::setSelectMode(bool selectMode)
{
    this->selected = selectMode;
}

bool ChessPiece::isSelected() const
{
    return this->selected;
}

ChessPiece::Type ChessPiece::getType() const
{
    return this->type;
}

ChessPiece::Team ChessPiece::getTeam() const
{
    return this->team;
}

std::pair<int, int> ChessPiece::getPos()
{
    return std::make_pair(this->posX, this->posY);
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent* event){
    m_startPos = pos();
    m_isDragging = true;
    // QGraphicsItem::mousePressEvent(event);
    qDebug() << "mousePressEvent";
}

void ChessPiece::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (m_isDragging) {
        setPos(mapToParent(event->pos()).x() -25, mapToParent(event->pos()).y() -25);
    }
    //QGraphicsItem::mouseMoveEvent(event);
}

void ChessPiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) 
{
    m_isDragging = false;
    // Get a list of colliding items
    QList<QGraphicsItem*> items = scene()->items(mapToScene(event->pos()));

    // Find the first ChessSquare in the list of colliding items
    ChessSquare* square = nullptr;
    for (QGraphicsItem* item : items) {
        square = dynamic_cast<ChessSquare*>(item);
        if (square) {
            qDebug() << "square";
            break;
        }
    }

    if (square) { // If the chess piece is over a valid square
        // Snap the chess piece to the center of the square
        QPointF center = square->rect().topLeft();
        qDebug() << "center " << center;
        setPos(square->mapToParent(center));
    }
    else { // If the chess piece is not over a square or the square is not valid
        // Return the chess piece to its original position
        setPos(m_startPos);
    }
}
