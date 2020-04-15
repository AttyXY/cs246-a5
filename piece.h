#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "enums.h"
#include "coord.h"

class Piece {
    public:
        Coord loc;
        Colour colour;
        bool hasMoved = false;
        bool enPassable = false;
        //PieceType type;
        
        /*Piece(PieceType type = P,
              Colour c = White,
              Coord loc = Coord{'a', '1'} );*/
        //~Piece();
        virtual bool isLegal(Coord, Coord, std::vector<std::vector<std::shared_ptr<Piece>>> &grid) = 0;
};

std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif
