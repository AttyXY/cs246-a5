#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "enums.h"
#include "coord.h"

class Piece {
    public:
        Coord loc;
        Colour colour;
        bool hasMoved;
        bool enPassable;
        //PieceType type;
        
        Piece(PieceType type = P,
              Colour c = White,
              Coord loc = Coord{'a', '1'} );
        ~Piece();
        virtual bool isLegal(void) = 0;
};

std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif