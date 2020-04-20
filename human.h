#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"


class Human : public Player {
    public:
        Human(Colour c, int score = 0);
        ~Human();

        void move(Coord start, Coord end) override;
        //void undo(void);
        //void redo(void);
};

#endif