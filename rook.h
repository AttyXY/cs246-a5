#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include <memory>
#include "piece.h"

class Rook: public Piece {
     public:
        Rook(Colour colour, PieceType pt, Coord pos);
        bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
        void getLineOfCheck(
            const Coord king, std::vector<Coord> &lineOfCheck
        ) override;
        bool isStuck(
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif
