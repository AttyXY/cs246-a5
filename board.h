#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <functional>
#include "observer.h"
#include "subject.h"
#include "state.h"
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
        std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
        std::vector<std::vector<char>> charTiles;
        std::vector<std::shared_ptr<Piece>> whitePieces;
        std::vector<std::shared_ptr<Piece>> blackPieces;
        std::shared_ptr<Piece> wk;
        std::shared_ptr<Piece> bk;
        std::shared_ptr<Piece> checker;
        // std::vector<Coord> lineOfCheck;
        bool legalLastMove = true;


        // Basic move
        void reset();
        bool init(const std::vector<std::vector<char>> &setupTiles);

        void addPiece(const Coord start, const Coord end);
        void removePiece(const Coord c);
        void movePiece(const Coord start, const Coord end);
        bool tempMove(Coord start, Coord end, bool (Board::*callback)(bool));

        bool whiteInCheck = false; //white is dying
        bool blackInCheck = false; //black is dying
        bool isWhiteInCheck(bool setChecker = false);
        bool isBlackInCheck(bool setChecker = false);
        bool isCheck();
        bool isMoveIntoCheck(const Colour turn, const Coord start, const Coord end);
        bool isLegalMove(const Colour turn, const Coord start, const Coord end);
        // bool isCapture(Subject<State> &whoFrom);


        // Special moves
        bool whiteCastled = false;
        bool blackCastled = false;
        bool isCastling(Coord start, Coord end);
        void castle(Colour turn, Coord start, Coord end);

        bool isEnPassanable = false;
        bool isEnPassant(Move m);
        bool isPawnPromotion(Move m);



        // Endgame detection
        bool stalemated = false;
        bool checkmated = false;

        bool isWhiteKingStuck();
        bool isBlackKingStuck();
        bool canWhiteBlockCheck();
        bool canBlackBlockCheck();
        bool isCheckmate(const Colour turn);

        void checkEndGame(const Colour turn);

        int movesSinceCaptureOrPawn = 0;
        bool isStalemate(Move m);

        // std::vector<Move> moves;
        // void undo();
        // void redo()
        // bool isThreefoldRepeat(Move m);






        // Subject-observer
        void update(Subject<State> &whoFrom);
};

#endif
