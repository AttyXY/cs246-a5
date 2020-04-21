#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"


class Computer : public Player {
    public:
        int level;

        Computer(Colour c, int score, int level);
        ~Computer();
        void move(Move m);
};

#endif