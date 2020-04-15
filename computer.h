#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "enums.h"
#include "move.h"


class Computer {
    public:
        int level;

        Computer(Colour c, int score, int level);
        ~Computer();
        bool move(Move m);
        //void undo(void);
        //void redo(void);
};

#endif