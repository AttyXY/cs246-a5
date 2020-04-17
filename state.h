#ifndef STATE_H
#define STATE_H
#include <vector>
#include "enums.h"
#include "move.h"

struct State {
    Move m;
    Colour c;
    std::vector<std::vector<char>> tiles;

    State(Move m = Move{},
          Colour c = Colour::NoColour,
          std::vector<std::vector<char>> tiles = std::vector<std::vector<char>>()
    ) : m{m}, c{c}, tiles{tiles} {}
};

#endif
