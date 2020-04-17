#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <memory>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "textDisplay.h"
#include "move.h"

#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"


class Board : public Observer<State>, public Subject<State> {
    public:
        // Init
        std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
        std::vector<std::vector<char>> charTiles;
        void init(std::vector<std::vector<char>> &setupTiles);
        bool move(Move m);
        // Board();
        ~Board();

        // Subject-observer
        std::shared_ptr<TextDisplay> td;
        void update(Subject<State> &whoFrom);

        /*
        void add(Piece p);
        void remove(Coord c);
        void update(void);
        void undo(void);
        // void redo(void);
        //GraphDisplay gd;
        */


       bool legalLastMove = true;
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

        std::vector<Move> moves;
        bool isThreefoldRepeat(Move m);

        // Endgame detection
        bool stalemated = false;
        bool checkmated = false;

};

#endif
