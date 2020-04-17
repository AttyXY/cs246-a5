#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "enums.h"
#include "move.h"
#include "observer.h"
#include "subject.h"
#include "state.h"


class Player : public Subject<State> {
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