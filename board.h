#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
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
        bool legalLastMove = true;


        // Basic move
        void reset();
        bool init(const std::vector<std::vector<char>> &setupTiles);
        void movePiece(const Move &m);
        void removePiece(const Coord &c);
        void addPiece(const Coord &start, const Coord &end);
        bool isLegalMove(Subject<State> &whoFrom);
        // bool isCapture(Subject<State> &whoFrom);


        // Special moves
        bool whiteCastled = false;
        bool blackCastled = false;
        bool isCastling(Move m);

        bool isEnPassanable = false;
        bool isEnPassant(Move m);
        bool isPawnPromotion(Move m);

        bool whiteInCheck = false; //white is dying
        bool blackInCheck = false; //black is dying
        bool isWhiteInCheck();
        bool isBlackInCheck();
        bool isCheck();
        bool isCheckmate(Move m);

        int movesSinceCaptureOrPawn = 0;
        bool isStalemate(Move m);

        // std::vector<Move> moves;
        // void undo();
        // void redo()
        // bool isThreefoldRepeat(Move m);

        // Endgame detection
        bool stalemated = false;
        bool checkmated = false;


        // Subject-observer
        void update(Subject<State> &whoFrom);
};

#endif
