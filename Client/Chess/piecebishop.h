
#ifndef PIECEBISHOP_H
#define PIECEBISHOP_H

#include "chesspiece.h"


class PieceBishop : public ChessPiece
{
public:
    PieceBishop(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEBISHOP_H
