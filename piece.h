#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "enums.h"
#include "coord.h"

class Piece {
    public:
        PieceType type;
        Colour c;
        Coord loc;
        bool hasMoved;
        bool enPassable;

        Piece(Colour c = White);
        ~Piece();
        virtual bool isLegal(void) = 0;
};

std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif