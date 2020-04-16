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
        std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
        std::vector<std::vector<char>> charTiles;
        //std::vector<Moves> moves;
        bool whiteCastled;
        bool blackCastled;
        bool whiteInCheck;
        bool blackInCheck;
        bool is_en_passanable = false;

        Board(std::vector<std::vector<char>> &setupTiles);
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