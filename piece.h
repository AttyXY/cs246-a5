#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <memory>
#include <vector>
#include "enums.h"
#include "coord.h"

class Piece {
    public:
        PieceType type;
        Colour c;
        Coord loc;
        bool hasMoved;
        bool enPassable;

        Piece(PieceType type = P,
              Colour c = White,
              Coord loc = Coord{'a', '1'} );
        ~Piece();
        virtual bool isLegal(Coord, Coord, std::vector<std::vector<std::shared_ptr<Piece>>> &tile) = 0;
};

std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif