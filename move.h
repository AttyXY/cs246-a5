#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include "coord.h"

class Move {
    public:
        Coord start;
        Coord end;

        Move(Coord start = 0, Coord end = 0);
        ~Move();
};

#endif