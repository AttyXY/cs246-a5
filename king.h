#ifndef KING_H
#define KING_H
#include <vector>
#include <memory>
#include "piece.h"

class King: public Piece {
     public:
        King(Colour colour, PieceType pt);
        bool isLegalMove(
            const Coord start, const Coord end,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif