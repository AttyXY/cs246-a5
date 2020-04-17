#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <memory>
#include <vector>
#include "enums.h"
#include "move.h"

class Piece {
    public:
        Colour colour;
        PieceType pt;
        bool hasMoved = false;
        bool isEnPassanable = false;

        Piece(Colour colour, PieceType pt);
        ~Piece();

        virtual bool isLegalMove(Move m, std::vector<std::vector<std::shared_ptr<Piece>>> &tiles) = 0;
};

//std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif