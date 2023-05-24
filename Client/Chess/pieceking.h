
#ifndef PIECEKING_H
#define PIECEKING_H

#include "chesspiece.h"


class PieceKing : public ChessPiece
{
public:
    PieceKing(GameState::StateTeam team);
    void calculateMoves() override;
};

#endif // PIECEKING_H
