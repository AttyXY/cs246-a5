#ifndef KING_H
#define KING_H
#include "piece.h"

class King: public Piece {
    public:
        bool isLegal(Coord, Coord, std::vector<std::vector<std::shared_ptr<Piece>>> &tile);
}

#endif