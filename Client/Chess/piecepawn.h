
#ifndef PIECEPAWN_H
#define PIECEPAWN_H

#include "chesspiece.h"


class PiecePawn: public ChessPiece
{
public:
    PiecePawn(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEPAWN_H
