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
        Coord loc;
        PieceType pt;
        bool hasMoved = false;
        bool is_en_passanable = false;

        Piece(Colour colour, PieceType pt);
        ~Piece();

        virtual bool isLegal(Move m, std::vector<std::vector<std::shared_ptr<Piece>>> &tiles) = 0;
};

//std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif