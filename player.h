#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "enums.h"
#include "move.h"
#include "subject.h"
#include "state.h"


class Player {
    public:
        Colour c;
        int score = 0;

        Player(Colour c, int score);
        ~Player();
        virtual void move(Move m) = 0;
        //virtual void undo(void) = 0;
        //virtual void redo(void) = 0;
};

#endif