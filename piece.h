#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <memory>
#include <vector>
#include "enums.h"
#include "coord.h"

class Piece {
    public:
        Colour colour;
        //Coord loc;
        bool hasMoved = false;
        bool enPassable = false;

        Piece(Colour colour);
        ~Piece();

        virtual bool isLegal(Coord, Coord, std::vector<std::vector<std::shared_ptr<Piece>>> &tile) = 0;
};

//std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif