#ifndef EMPTY_H
#define EMPTY_H
#include <vector>
#include <memory>
#include "piece.h"

class Empty: public Piece {
     public:
        Empty(Colour colour,
              PieceType pt,
              Coord pos);
        bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif