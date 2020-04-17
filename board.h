#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <memory>
#include "piece.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
//#include "move.h"

class Board {
    public:
        std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
        std::vector<std::vector<char>> charTiles;
        void init(std::vector<std::vector<char>> &setupTiles);
        bool move(Move m);
        Board();
        ~Board();

        /*
        //void update();
        void add(Piece p);
        void remove(Coord c);
        void update(void);
        void undo(void);
        // void redo(void);
        //TextDisplay td;
        //GraphDisplay gd;
        */


        /*
        // Special moves
        bool whiteCastled = false;
        bool blackCastled = false;
        bool isCastling(Move m);

        bool isEnPassanable = false;
        bool isEnPassant(Move m);
        bool isPawnPromotion(Move m);

        bool whiteInCheck = false;
        bool blackInCheck = false;
        int movesSinceCaptureOrPawn = 0;
        bool isCheck(Move m);
        bool isCheckmate(Move m);
        bool isStalemate(Move m);

        //std::vector<Moves> moves;
        bool isThreefoldRepeat(Move m);
        */

        /*
        // Endgame detection
        bool isStalemate = false;
        bool isCheckmate = false;
        */


};

#endif
