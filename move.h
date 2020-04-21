#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include "coord.h"
#include "enums.h"

class Move {
    public:
        Coord start;
        Coord end;
        char promoteTo;

        Move(Coord start = 0, Coord end = 0, char promoteTo = 'X');
        ~Move();
};

#endif