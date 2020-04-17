#ifndef STATE_H
#define STATE_H
#include "enums.h"
#include "move.h"

struct State
{
    Move m;
    Colour c;
    PlayerType playerType;
    MoveType moveType;
    char promotion;
    std::vector<std::vector<char>> tiles;

    State(Move m = Move{},
          Colour c = Colour::NoColour,
          PlayerType playerType = PlayerType::Human, 
          MoveType moveType = MoveType::Normal, 
          char promotion = 0,
          std::vector<std::vector<char>> tiles = std::vector<std::vector<char>>())
    {
        this->m = m;
        this->c = c;
        this->playerType = playerType;
        this->promotion = promotion;
        this->tiles = tiles;
    }
    //m{m}, c{c}, tiles{tiles} {}
};

#endif
