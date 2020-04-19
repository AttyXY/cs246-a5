#ifndef KNIGHT_H
#define KNIGHT_H
#include <vector>
#include <memory>
#include "piece.h"

class Knight: public Piece {
     public:
        Knight(Colour colour, PieceType pt);
        bool isLegalMove(
            const Coord start, const Coord end,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif