#ifndef STATE_H
#define STATE_H
#include "enums.h"
#include "move.h"

struct State {
    Move m;
    Colour c;
    std::vector<std::vector<char>> tiles;

    State(Move m = Move{},
          Colour c = Colour::NoColour,
          std::vector<std::vector<char>> tiles = std::vector<std::vector<char>>()
    ) {
        this->m = m;
        this->c = c;
        this->tiles = tiles;
    }
    //m{m}, c{c}, tiles{tiles} {}
};

#endif
