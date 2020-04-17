#ifndef STATE_H
#define STATE_H
#include <vector>
#include "enums.h"
#include "move.h"

struct State {
    Move m;
    Colour colour;
    std::vector<std::vector<char>> tiles;

    State(Move m = Move{},
          Colour colour = Colour::NoColour,
          const std::vector<std::vector<char>> &tiles =
            std::vector<std::vector<char>>()
    ) : m{m}, colour{colour}, tiles{tiles} {}
};

#endif
