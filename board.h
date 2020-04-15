#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <memory>
#include "piece.h"
#include "coord.h"
//#include "move.h"

class Board {
    public:
        std::vector<std::vector<Piece>> pieces;
        //std::vector<Moves> moves;
        bool whiteCastled;
        bool blackCastled;
        bool whiteInCheck;
        bool blackInCheck;

        Board(std::vector<std::vector<char>> &setupGrid);
        Board();
        ~Board();
        /*
        //void notify();
        void add(Piece p);
        void remove(Coord c);
        void update(void);
        bool move(Move m);
        void undo(void);
        // void redo(void);
        //TextDisplay td;
        //GraphDisplay gd;
        */

};

#endif