#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "enums.h"
#include "move.h"
#include "observer.h"
#include "subject.h"
#include "state.h"


class Player : public Subject<State> {
    public:
        Colour c;
        double score = 0;

        Player(Colour c, double score);
        ~Player();
        virtual bool hasDefaultMove() { return false; }
        virtual void move(Move m) = 0;
        //virtual void undo(void) = 0;
        //virtual void redo(void) = 0;
};

#endif