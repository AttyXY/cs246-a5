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
#include "empty.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"


class Board : public Observer<State>, public Subject<State> {
    std::vector<std::vector<std::shared_ptr<Piece>>> tiles;
    std::vector<std::vector<char>> charTiles;
    std::vector<std::shared_ptr<Piece>> whitePieces;
    std::vector<std::shared_ptr<Piece>> blackPieces;
    std::shared_ptr<Piece> wk;
    std::shared_ptr<Piece> bk;
    std::shared_ptr<Piece> checker;
    std::vector<Coord> lineOfCheck;

   // Basic move
    void reset();
    void addCharPiece(const char piece, const int row, const int col);

    void addPiece(const Coord start, const Coord end);
    void removePiece(const Coord c);
    void movePiece(const Coord start, const Coord end, bool tempMove = false);
    bool tempMove(Coord start, Coord end, bool (Board::*callback)(bool));

    bool isWhiteInCheck(bool setChecker = false);
    bool isBlackInCheck(bool setChecker = false);
    bool isCheck();
    bool isMoveIntoCheck(const Colour turn, const Coord start, const Coord end);
    bool isLegalMove(const Colour turn, const Coord start, const Coord end,
                        const char promoteTo);
    // bool isCapture(Subject<State> &whoFrom);

    // Special moves
    bool whiteCastled = false;
    bool blackCastled = false;
    bool isCastling(Coord start, Coord end);
    bool castle(Colour turn, Coord start, Coord end);
    bool isEnPassant(Colour turn, Coord start, Coord end);
    bool enPassant(Colour turn, Coord start, Coord end);
    void resetEnPassant(Coord end);
    bool isPawnPromotion(const Colour turn, const Coord start, const Coord end);
    void promotePawn(const Coord start, const Coord end, const char promoteTo);


    // Endgame detection
    void checkEndGame(const Colour turn);

    bool isWhiteKingStuck();
    bool isBlackKingStuck();
    bool canWhiteBlockCheck();
    bool canBlackBlockCheck();
    bool isCheckmate(const Colour turn);

    bool whiteInsufficientMaterial();
    bool blackInsufficientMaterial();
    bool insufficientMaterial();

    // int movesSinceCaptureOrPawn = 0;
    // std::vector<Move> moves;
    // void undo();
    // void redo()
    // bool isThreefoldRepeat(Move m);

    // Computer moves
    void computerL1Move(const Colour turn);
    void computerL2Move(const Colour turn);
    void computerL3Move(const Colour turn);

    public:
        bool whiteInCheck = false; //white is dying
        bool blackInCheck = false; //black is dying
        bool stalemated = false;
        bool checkmated = false;
        bool legalLastMove = true;

        // Init board
        bool init(const std::vector<std::vector<char>> &setupTiles);
        bool isStalemate(const Colour turn);

        // Subject-observer
        void update(Subject<State> &whoFrom);
};

#endif
