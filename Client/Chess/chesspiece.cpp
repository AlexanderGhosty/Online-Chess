
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

void ChessPiece::setTeam(GameState::StateTeam team)
{
    this->team = team;
}

void ChessPiece::setNewPos(int posX, int posY)
{
    getGameState()->changeGameStatePosition(getTeam(), getID(), posX / 50, posY / 50);
    if(posX < 0 || posY < 0){
        qDebug() << "killed piece" << getID();
        this->setVisible(false);
        this->setEnabled(false);
        // getGameState()->
        return;
    }
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

GameState::StateTeam ChessPiece::getTeam() const
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


int ChessPiece::getMovesAmount(){
    return this->movesAmount;
}

void ChessPiece::setZeroMovesAMount(){
    this->movesAmount = 0;
}

void ChessPiece::addAMove(){
    ++this->movesAmount;
}

int ChessPiece::getID(){
    return m_id;
}

void ChessPiece::setGameState(GameState* gameState){
    this->gameState = gameState;
}

GameState* ChessPiece::getGameState(){
    return gameState;
}

void ChessPiece::setId(int m_id){
    this->m_id = m_id;
}


void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(getTeam() != getGameState()->getTeamToMove())
        return;
    qDebug() << "mousePressEvent";
    getGameState()->getTeamToMove();
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
        // qDebug() << "mouseMoveEvent";
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
    if(!m_isDragging)
        return;
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
        qDebug() << "center " << center << center.x() << center.y();
        if (square->mapToParent(center) != m_startPos) {
            setNewPos((int) (square->mapToParent(center)).x(), (int) (square->mapToParent(center)).y());

            // killing enemy
            QList<QGraphicsItem *> items = this->scene()->items(QPointF(square->mapToParent(center).x() + 25, square->mapToParent(center).y() + 25));

            ChessPiece *chessPiece = nullptr;

            for (QGraphicsItem *item : items) {
                chessPiece = dynamic_cast<ChessPiece *>(item);
                if (chessPiece && chessPiece->getTeam() != getGameState()->getTeamToMove()) {
                    qDebug() << "нашел";
                    break;
                }
            }

            if(chessPiece!= nullptr){ // if can kill a piece
                //chessPiece->setActive(false); // might be in SetNewPos method (-1 pos check)
                chessPiece->setNewPos(-1, 0);
            }
            else{
                delete chessPiece;
            }

            addAMove();
            getGameState()->changeTeamToMove();


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

    for (auto i = 0; i < moveSquares.size(); ++i){
        delete moveSquares[i];
    }
    this->moveSquares.clear();
}
