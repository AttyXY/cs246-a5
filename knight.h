#ifndef KNIGHT_H
#define KNIGHT_H
#include <vector>
#include <memory>
#include "piece.h"

class Knight: public Piece {
     public:
        Knight(Colour colour, PieceType pt, Coord pos);
        bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
        void getLineOfCheck(
            const Coord king, std::vector<Coord> &lineOfCheck
        ) override;
 };

 #endif