#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"


class Computer : public Player {
    public:
        int level = 1;

        Computer(int level, Colour c, int score = 0);
        ~Computer();
        void move(Move m);
};

#endif