#include <iostream>
#include "game.h"
using namespace std;


Game::Game(Player p1, Player p2, Board board) {}
Game::~Game() {}

ostream &operator<<(ostream &out, const Game &g) {
    return out;
}
istream &operator>>(istream &in, Game &g) {
    return in;
}
