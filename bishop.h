#ifndef BISHOP_H
#define BISHOP_H
#include <vector>
#include <memory>
#include "piece.h"

class Bishop: public Piece {
     public:
        Bishop(Colour colour, PieceType pt, Coord pos);
        bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif