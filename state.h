#ifndef STATE_H
#define STATE_H
#include <vector>
#include "enums.h"
// #include "move.h"
#include "coord.h"

struct State {
    Coord start;
    Coord end;
    Colour colour;
    std::vector<std::vector<char>> tiles;

    State(Coord start,
          Coord end,
          Colour colour = Colour::NoColour,
          const std::vector<std::vector<char>> &tiles =
            std::vector<std::vector<char>>()
    ) : start{start}, end{end}, colour{colour}, tiles{tiles} {}
};

#endif
