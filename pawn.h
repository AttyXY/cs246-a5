#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include <memory>
#include "piece.h"

class Pawn: public Piece {
     public:
        Pawn(Colour colour, PieceType pt);
        bool isLegalMove(
            const Coord start, const Coord end,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif