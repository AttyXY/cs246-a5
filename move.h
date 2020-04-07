#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include "coord.h"

class Move {
    public:
        Coord start;
        Coord end;

        Move(Coord start, Coord end);
        ~Move();
};

std::ostream &operator<<(std::ostream &out, const Move &m);
std::istream &operator>>(std::istream &in, Move &m);

#endif