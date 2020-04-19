#ifndef BISHOP_H
#define BISHOP_H
#include <vector>
#include <memory>
#include "piece.h"

class Bishop: public Piece {
     public:
        Bishop(Colour colour, PieceType pt);
        bool isLegalMove(
            const Coord start, const Coord end,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif