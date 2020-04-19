#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include <memory>
#include "piece.h"

class Queen: public Piece {
     public:
        Queen(Colour colour, PieceType pt);
        bool isLegalMove(
            const Coord start, const Coord end,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif