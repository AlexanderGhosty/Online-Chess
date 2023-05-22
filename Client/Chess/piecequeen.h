
#ifndef PIECEQUEEN_H
#define PIECEQUEEN_H

#include "chesspiece.h"


class PieceQueen : public ChessPiece
{
public:
    PieceQueen(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEQUEEN_H
