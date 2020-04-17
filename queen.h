#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include <memory>
#include "piece.h"

class Queen: public Piece {
     public:
        Queen(Colour colour, PieceType pt);
        bool isLegalMove(
            Move m,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif