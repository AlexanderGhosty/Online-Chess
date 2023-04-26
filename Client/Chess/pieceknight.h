
#ifndef PIECEKNIGHT_H
#define PIECEKNIGHT_H

#include "chesspiece.h"


class PieceKnight:public ChessPiece
{
public:
    PieceKnight(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEKNIGHT_H
