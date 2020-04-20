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
        PieceType pt;
        Coord pos;
        bool hasMoved = false;
        bool isEnPassanable = false;

        Piece(Colour colour, PieceType pt);
        ~Piece();

        virtual bool isLegalMove(const Coord start, const Coord end,
                                 std::vector<std::vector<std::shared_ptr<Piece>>> &tiles) = 0;
        bool isBasicInvalidMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        );
};

//std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif