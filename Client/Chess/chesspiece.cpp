
#include "chesspiece.h"

/*
ChessPiece::ChessPiece(Team team):
    team(team),
    selected(false)
{
    // ???? ???????

    QPixmap pixmap(50, 50);
    pixmap.fill(Qt::red);
    setPixmap(pixmap);

}*/



// bool canMoveTo(int posX, int posY);

ChessPiece::ChessPiece(){

}

void ChessPiece::setType(Type type)
{
    this->type = type;
}

void ChessPiece::setTeam(Team team)
{
    this->team = team;
}

void ChessPiece::setNewPos(int posX, int posY)
{
    this->posX = posX / 50;
    this->posY = posY / 50;
    setPos(posX, posY);
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

std::pair<int, int> ChessPiece::getPosPiece()
{
    return std::make_pair(this->posX, this->posY);
}

ChessPiece::Team ChessPiece::getTeam() const
{
    return this->team;
}

std::pair<int, int> ChessPiece::getPos()
{
    return std::make_pair(this->posX, this->posY);
}


void ChessPiece::addMoveSquare(ChessSquare* moveSquare)
{
    this->moveSquares.push_back(moveSquare);
}


std::vector<ChessSquare*> ChessPiece::getMoveSquares()
{
    return this->moveSquares;
}

<<<<<<< Updated upstream

int ChessPiece::getMovesMade()
{
    return this->movesMade;
}

void ChessPiece::addMoveAmount()
{
    ++this->movesMade;
}

void ChessPiece::setZeroMoves()
{
    this->movesMade = 0;
}



=======
void ChessPiece::addAMove(){
    ++this->moveAmount;
}

int ChessPiece::getMoveAmount(){
    return this->moveAmount;
}

void ChessPiece::setZeroMoveAmount(){
    this->moveAmount = 0;
}

>>>>>>> Stashed changes
void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent* event){
    m_startPos = pos();
    m_isDragging = true;
    // QGraphicsItem::mousePressEvent(event);
    qDebug() << "mousePressEvent";
    setSelectMode(true);
    calculateMoves();
}

void ChessPiece::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (m_isDragging) {
        // setPos(mapToParent(event->pos()).x() -25, mapToParent(event->pos()).y() -25);

        QPointF newPos = event->scenePos();

        // ?????????? ??????? ????? ? ??????? ???????
        QRectF sceneRect = scene()->sceneRect();
        QRectF boundingRect = this->boundingRect();

        // ?????????? ????? ??????????
        qreal newX = newPos.x();
        qreal newY = newPos.y();

        // ???????????? ?????????? ???????, ????? ?? ?? ??????? ?? ??????? ?????
        if (newX < sceneRect.left() + boundingRect.width() / 2)
            newX = sceneRect.left() + boundingRect.width() / 2;
        else if (newX > sceneRect.right() - boundingRect.width() / 2)
            newX = sceneRect.right() - boundingRect.width() / 2;

        if (newY < sceneRect.top() + boundingRect.height() / 2)
            newY = sceneRect.top() + boundingRect.height() / 2;
        else if (newY > sceneRect.bottom() - boundingRect.height() / 2)
            newY = sceneRect.bottom() - boundingRect.height() / 2;

        // ?????????? ?????? ?? ????? ?????
        setPos(newX - 25, newY- 25);

        // ???????? ??????? ?????????? ??? ????????? ?????? ??????? ???????????
        QGraphicsItem::mouseMoveEvent(event);
    }
    // QGraphicsItem::mouseMoveEvent(event);
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

    if (square && square->getBrush() == Qt::green) { // If the chess piece is over a valid square
        // Snap the chess piece to the center of the square
        QPointF center = square->rect().topLeft();
        qDebug() << "center " << center << (int) center.x();
        if (square->mapToParent(center) != m_startPos) {
            setNewPos((int) (square->mapToParent(center)).x(), (int) (square->mapToParent(center)).y());
<<<<<<< Updated upstream
            addMoveAmount();

=======
            addAMove();
>>>>>>> Stashed changes
            qDebug() << "new position of an obj" << posX << posY;
            qDebug()
                << "(int)(square->mapToParent(center)).x(), (int)(square->mapToParent(center)).y()"
                << (int) (square->mapToParent(center)).x()
                << (int) (square->mapToParent(center)).y();
        }
        else{
            setPos(m_startPos);
        }
    }
    else { // If the chess piece is not over a square or the square is not valid
        // Return the chess piece to its original position
        setPos(m_startPos);
    }
    setSelectMode(false);
    for (auto it = this->moveSquares.begin(); it != this->moveSquares.end();) {
        delete *it;
        it = this->moveSquares.erase(it);
        if (it != this->moveSquares.end()) {
            ++it; // переходим к следующему элементу, если он существует
        }
    }
    this->moveSquares.clear();
}
