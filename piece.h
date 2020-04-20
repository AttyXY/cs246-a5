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

        Piece(Colour colour, PieceType pt, Coord pos);
        ~Piece();

        virtual bool isLegalMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) = 0;
        bool isBasicInvalidMove(
            const Coord start, const Coord end,
            const std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        );
        virtual void getLineOfCheck(
            const Coord king, std::vector<Coord> &lineOfCheck
        ) = 0;
        virtual bool isStuck(
            std::vector<std::vector<std::shared_ptr<Piece>>> &tiles
        ) = 0;
};

//std::ostream &operator<<(std::ostream &out, const Piece &p);

#endif