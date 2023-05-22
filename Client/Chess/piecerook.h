
#ifndef PIECEROOK_H
#define PIECEROOK_H

#include "chesspiece.h"


class PieceRook : public ChessPiece
{
public:
    PieceRook(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEROOK_H
