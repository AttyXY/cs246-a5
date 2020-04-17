#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include <memory>
#include "piece.h"

class Rook: public Piece {
     public:
        Rook(Colour colour, PieceType pt);
        bool isLegalMove(
            Move m,
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) override;
 };

 #endif