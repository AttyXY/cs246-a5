#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "enums.h"
#include "move.h"


class Human {
    public:
        Human(Colour c, int score);
        ~Human();
        bool move(Move m);
        //void undo(void);
        //void redo(void);
};

#endif