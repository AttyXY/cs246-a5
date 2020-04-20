#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include <memory>
#include "piece.h"

class Queen: public Piece {
     public:
        Queen(Colour colour, PieceType pt, Coord pos);
        bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
        void getLineOfCheck(
            const Coord king, std::vector<Coord> &lineOfCheck
        ) override;
 };

 #endif