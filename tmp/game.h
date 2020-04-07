#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.h"
#include "board.h"

class Game {
    public:
        Player p1;
        Player p2;
        Board board;

        Game(Player p1, Player p2, Board board);
        ~Game();
};

std::ostream &operator<<(std::ostream &out, const Game &g);
std::istream &operator>>(std::istream &in, Game &g);

#endif