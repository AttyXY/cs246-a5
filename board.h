#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <memory>
#include "piece.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
// #include "move.h"

class Board: public Subject<State>, public Observer<State> {
    public:
        std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
        std::vector<std::vector<char>> charTiles;
        void init(std::vector<std::vector<char>> &setupTiles);
<<<<<<< HEAD
        bool canMove(Subject<State> &whoFrom);
        bool lastMoveValid = true;
=======
        bool move(Move m);
        Board();
>>>>>>> 7d2dd0b2ef4844f624d286f7788995f68a5addde
        ~Board();
  
        
        // //void update();
        void add(Move m); // remove at old coord
        void remove(Coord c);
        // void update(void);
        // void undo(void);
        // // void redo(void);
        // //TextDisplay td;
        // //GraphDisplay gd;
        


        
        // Checks Special moves
        // bool whiteCastled = false;
        // bool blackCastled = false;
        bool isCastling(Subject<State> &whoFrom);

        // bool isEnPassanable = false;
        bool isEnPassant(Subject<State> &whoFrom);
        bool isPawnPromotion(Subject<State> &whoFrom);

        // bool whiteInCheck = false;
        // bool blackInCheck = false;
        // int movesSinceCaptureOrPawn = 0;
        // bool isCheck(Move m);
        // bool isCheckmate(Move m);
        // bool isStalemate(Move m);

        // //Special moves
        // void castle(Subject <State> &whoFrom);
        // bool promotePawn(Subject <State> &whoFrom);
        // void enPassant(Move m);

        // //std::vector<Moves> moves;
        // bool isThreefoldRepeat(Move m);
        

        /*
        // Endgame detection
        bool isStalemate = false;
        bool isCheckmate = false;
        */

        // To make our life easier
        bool isWhite(Coord pos);
        bool isBlack(Coord pos);
        void update(Subject <State> &whoFrom);
 
};

#endif
