#include "board.h"
using namespace std;

Board::Board() {
    reset();
}

// Initializes tiles and charTiles with clear boards.
void Board::reset() {
    // Default state values
    whitePieces = vector<shared_ptr<Piece>>();
    blackPieces = vector<shared_ptr<Piece>>();
    wk = shared_ptr<King>();
    bk = shared_ptr<King>();
    checker = shared_ptr<Empty>();
    lineOfCheck = vector<Coord>();
    whiteCastled = false;
    blackCastled = false;
    whiteInCheck = false;
    blackInCheck = false;
    stalemated = false;
    checkmated = false;
    legalLastMove = true;

    // Default tile values
    vector<char> row(8, '-');
	charTiles = vector<vector<char>>(8, row);

    vector<vector<shared_ptr<Piece>>> newTiles;
    for (int row = 0; row < (int)charTiles.size(); ++row) {
        newTiles.emplace_back(vector<shared_ptr<Piece>>());
        for (int col = 0; col < (int)charTiles[row].size(); ++col) {
            // Fill all tiles with empty pieces
            newTiles[row].emplace_back(make_shared<Empty>(
                Colour::NoColour, PieceType::X, Coord(col, row)
            ));
        }
    }
    tiles = newTiles;
}

void Board::addCharPiece(const char piece, const int row, const int col) {
    charTiles[row][col] = piece;
    switch (piece) {
        case 'k': {
            tiles[row][col] = make_shared<King>(
                    Colour::Black, PieceType::K, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            bk = tiles[row][col];
            break;
        }
        case 'K': {
            tiles[row][col] =
                make_shared<King>(
                    Colour::White, PieceType::K, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            wk = tiles[row][col];
            break;
        }
        case 'q': {
            tiles[row][col] =
                make_shared<Queen>(
                    Colour::Black, PieceType::Q, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'Q': {
            tiles[row][col] =
                make_shared<Queen>(
                    Colour::White, PieceType::Q, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'r': {
            tiles[row][col] =
                make_shared<Rook>(
                    Colour::Black, PieceType::R, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'R': {
            tiles[row][col] =
                make_shared<Rook>(
                    Colour::White, PieceType::R, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'n': {
            tiles[row][col] =
                make_shared<Knight>(
                    Colour::Black, PieceType::N, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'N': {
            tiles[row][col] =
                make_shared<Knight>(
                    Colour::White, PieceType::N, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'b': {
            tiles[row][col] =
                make_shared<Bishop>(
                    Colour::Black, PieceType::B, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'B': {
            tiles[row][col] =
                make_shared<Bishop>(
                    Colour::White, PieceType::B, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'p': {
            tiles[row][col] =
                make_shared<Pawn>(
                    Colour::Black, PieceType::P, Coord(row, col)
            );
            blackPieces.emplace_back(tiles[row][col]);
            break;
        }
        case 'P': {
            tiles[row][col] =
                make_shared<Pawn>(
                    Colour::White, PieceType::P, Coord(row, col)
            );
            whitePieces.emplace_back(tiles[row][col]);
            break;
        }
    }
}

// Initializes tiles and charTiles with pieces, from td->tiles.
// Returns false if setup results in check, and true otherwise.
bool Board::init(const vector<vector<char>> &setupTiles) {
    reset();

    // Copy setupTiles into charTiles
    charTiles = setupTiles;

    // Convert setupTiles into board
    for (int col = 0; col < (int)tiles.size(); ++col) {
        for (int row = 0; row < (int)tiles[col].size(); ++row) {
            addCharPiece(setupTiles[row][col], row, col);
        }
    }
    if (isCheck()) {
        return false;
    }
    return true;
}




/* Move helpers */
void Board::addPiece(const Coord start, const Coord end) {
    charTiles[end.getRow()][end.getCol()] = charTiles[start.getRow()][start.getCol()];
    tiles[end.getRow()][end.getCol()] = tiles[start.getRow()][start.getCol()];
    tiles[end.getRow()][end.getCol()]->pos = {end.getRow(), end.getCol()};
    if (tiles[end.getRow()][end.getCol()]->pt == PieceType::K) {
        if (tiles[end.getRow()][end.getCol()]->colour == Colour::White) {
            wk->pos = end;
        } else if (tiles[end.getRow()][end.getCol()]->colour == Colour::Black) {
            bk->pos = end;
        }
    }
}

void Board::removePiece(const Coord c) {
    charTiles[c.getRow()][c.getCol()] = '-';
    tiles[c.getRow()][c.getCol()] = make_shared<Empty>(
        Colour::NoColour, PieceType::X, Coord(c.getRow(), c.getCol())
    );
}

void Board::movePiece(const Coord start, const Coord end, bool tempMove) {
    addPiece(start, end);
    removePiece(start);
    if (!tempMove) {
        tiles[end.getRow()][end.getCol()]->hasMoved = true;
    }
}

// makes and undos Move m, getting and returning result of callback in-between
bool Board::tempMove(Coord start, Coord end, bool (Board::*callback)(bool)) {
    // tempMove
    shared_ptr<Piece> tempPiece = tiles[end.getRow()][end.getCol()];
    char tempChar = charTiles[end.getRow()][end.getCol()];
    movePiece(start, end, true);

    // get result
    bool result = (this->*callback)(false);

    // undo tempMove
    movePiece(end, start, true);
    tiles[end.getRow()][end.getCol()] = tempPiece;
    charTiles[end.getRow()][end.getCol()] = tempChar;

    return result;
}

/* Check helpers */
bool Board::isWhiteInCheck(bool setChecker) {
    for (const auto &p: blackPieces) {
        if (p->isLegalMove(p->pos, wk->pos, tiles)) {
            if (setChecker) {
                checker = p;
                lineOfCheck = vector<Coord>(); // clear line of check
                p->getLineOfCheck(wk->pos, lineOfCheck);
            }
            return true;
        }
    }
    return false;
}

bool Board::isBlackInCheck(bool setChecker) {
    for (const auto &p: whitePieces) {
        if (p->isLegalMove(p->pos, bk->pos, tiles)) {
            if (setChecker) {
                checker = p;
                lineOfCheck = vector<Coord>(); // clear line of check
                p->getLineOfCheck(bk->pos, lineOfCheck);
            }
            return true;
        }
    }
    return false;
}

bool Board::isCheck() {
    return isWhiteInCheck() || isBlackInCheck();
}

// Returns true if King will still be in check after move
bool Board::isMoveIntoCheck(const Colour turn, const Coord start, const Coord end) {
    if (turn == Colour::White) {
        return tempMove(start, end, &Board::isWhiteInCheck);
    } else if (turn == Colour::Black) {
        return tempMove(start, end, &Board::isBlackInCheck);
    } else {
        return false; // WTF
    }
}

/* Endgame detection helpers: Run after move has already been made */
bool Board::isWhiteKingStuck() {
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i == 0 && j == 0) { continue; } // same position as before

            Coord start = wk->pos;
            Coord end{wk->pos.getRow() + i, wk->pos.getCol() + j};
            if (tiles[start.getRow()][start.getCol()]->isLegalMove(start, end, tiles)) {
                if (!tempMove(start, end, &Board::isWhiteInCheck)) {
                    return false; // escape exists
                }
            }
        }
    }
    return true;
}

bool Board::isBlackKingStuck() {
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i == 0 && j == 0) { continue; } // same position as before

            Coord start = bk->pos;
            Coord end{bk->pos.getRow() + i, bk->pos.getCol() + j};
            if (tiles[start.getRow()][start.getCol()]->isLegalMove(start, end, tiles)) {
                if (!tempMove(start, end, &Board::isBlackInCheck)) {
                    return false; // escape exists
                }
            }
        }
    }
    return true;
}

// Piece and checker MUST BE INSTANTIATED PIECES
bool Board::canWhiteBlockCheck() {
    for (const auto &p: whitePieces) {
        // can capture piece
        if (p->isLegalMove(p->pos, checker->pos, tiles)) {
            Coord start = p->pos;
            Coord end = checker->pos;
            return !tempMove(start, end, &Board::isWhiteInCheck);
        }

        // can block line of check
        if (p->pt == PieceType::K) { continue; }
        for (const auto &coord: lineOfCheck) {
            if (p->isLegalMove(p->pos, coord, tiles)) {
            return true;
            }
        }
    }
    return false;
}

// Piece and checker MUST BE INSTANTIATED PIECES
bool Board::canBlackBlockCheck() {
    for (const auto &p: blackPieces) {
        // can capture piece
        if (p->isLegalMove(p->pos, checker->pos, tiles)) {
            Coord start = p->pos;
            Coord end = checker->pos;
            return !tempMove(start, end, &Board::isBlackInCheck);
        }

        // can block line of check
        if (p->pt == PieceType::K) { continue; }
        for (const auto &coord: lineOfCheck) {
            if (p->isLegalMove(p->pos, coord, tiles)) {
            return true;
            }
        }
    }
    return false;
}


/* Endgame detection: Run after move has already been made */
bool Board::isCheckmate(const Colour turn) {
    if (turn == Colour::White) {
        return isBlackKingStuck() && !canBlackBlockCheck();
    } else {
        return isWhiteKingStuck() && !canWhiteBlockCheck();
    }
}


bool Board::whiteInsufficientMaterial() {
    if ((int)whitePieces.size() == 1) { // Only king
        return true;
    } else if ((int)whitePieces.size() == 2) { // King and Bishop/Knight
        for (const auto &p: whitePieces) {
            if (p->pt == PieceType::B || p->pt == PieceType::N) {
                return true;
            }
        }
    }
    return false;
}

bool Board::blackInsufficientMaterial() {
    if ((int)blackPieces.size() == 1) { // Only king
        return true;
    } else if ((int)blackPieces.size() == 2) { // King and Bishop/Knight
        for (const auto &p: blackPieces) {
            if (p->pt == PieceType::B || p->pt == PieceType::N) {
                return true;
            }
        }
    }
    return false;
}

bool Board::insufficientMaterial() {
    return whiteInsufficientMaterial() && blackInsufficientMaterial();
}

bool Board::isStalemate(const Colour turn) {
    if (!insufficientMaterial()) {
        if (turn == Colour::White) {
            for (const auto &p: blackPieces) {
                if (p->pt == PieceType::K) {
                    if (!isBlackKingStuck()) {
                        return false;
                    }
                } else {
                    if (!p->isStuck(tiles)) {
                        return false;
                    }
                }
            }
        } else if (turn == Colour::Black) {
            for (const auto &p: whitePieces) {
                if (p->pt == PieceType::K) {
                    if (!isWhiteKingStuck()) {
                        return false;
                    }
                } else {
                    if (!p->isStuck(tiles)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// check board state once legal move has been made
void Board::checkEndGame(const Colour turn) {
    blackInCheck = isBlackInCheck(true);
    whiteInCheck = isWhiteInCheck(true);

    if (blackInCheck || whiteInCheck) {
        checkmated = isCheckmate(turn);
    } else {
        stalemated = isStalemate(turn);
    }
    // TODO: threefold repetition
    // TODO: fifty-move-rule
}




/* Move logic */
void Board::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    if (s.mt == MoveType::H) {
        legalLastMove = isLegalMove(s.colour, s.m.start, s.m.end, s.m.promoteTo);
    }
    else if (s.mt == MoveType::L1) {
        legalLastMove = computerL1Move(s.colour);
    }
    else if (s.mt == MoveType::L2) {
        legalLastMove = computerL2Move(s.colour);
    }
    // } else if (s.mt == MoveType::L3) {
    //     legalLastMove = computerL3Move(turn);
    // }

    // update displays
    State newS{s.mt, s.m, s.colour, charTiles};
    setState(newS);
    notify();
}

bool Board::isLegalMove(const Colour turn, const Coord start, const Coord end,
                        const char promoteTo) {
    // Move other player's piece
    if (turn != tiles[start.getRow()][start.getCol()]->colour) {
        return false;
    }

    // IN CHECK AFTER MOVE?
    else if (isMoveIntoCheck(turn, start, end)) {
        // Only possible right after setup, because stalemate is checked
        // for at the end of every move, and ends game
        // stalemated = true;
        // Cannot be checkmate because checkmate immediately ends game, and
        // and setups that begin with check are invalid.
        stalemated = isStalemate(turn);
        return false;
    }

    // TODO: SPECIAL MOVE CHECKS
    else if (isCastling(start, end)) {
        bool isLegal = castle(turn, start, end);
        checkEndGame(turn);
        if (isLegal) { resetEnPassant(end); }
        return isLegal;
    }

    else if (isPawnPromotion(turn, start, end)) {
        if (promoteTo == 'X') { return false; }
        promotePawn(start, end, promoteTo);
        resetEnPassant(end);
        checkEndGame(turn);
        return true;
    }

    else if (isEnPassant(turn, start, end)) {
         bool isLegal = enPassant(turn, start, end);
    //make sure to check if isEnPassanable change everytime it moves forward 2 steps
        checkEndGame(turn);
        if (isLegal) { resetEnPassant(end); }
        return isLegal;
    }


    // BASIC MOVE CHECKS
    else if (tiles[start.getRow()][start.getCol()]->isLegalMove(start, end, tiles)) {
        movePiece(start, end);
        checkEndGame(turn);
        resetEnPassant(end);
        return true;
    } else {
        return false;
    }
}


/* Special moves */
bool Board::isEnPassant(Colour turn, Coord start, Coord end) {
    // is it a pawn?
    if(tiles[start.getRow()][start.getCol()]->pt == PieceType::P) {
        // are they moving diagonally forward by one space?
        if ((abs(start.getRow() - end.getRow()) == 1) &&
            (abs(start.getCol() - end.getCol()) == 1)) {
                if (turn == Colour::White) {
                    if ((tiles[end.getRow()][end.getCol()]->pt == X) &&
                        (tiles[end.getRow() - 1][end.getCol()]->pt == P) &&
                        (tiles[end.getRow() - 1][end.getCol()]->colour == Colour::Black) &&
                        (tiles[end.getRow() - 1][end.getCol()]->isEnPassanable)) {
                            return true;
                        }
                } else if (turn == Colour::Black) {
                    if ((tiles[end.getRow()][end.getCol()]->pt == X) &&
                        (tiles[end.getRow() + 1][end.getCol()]->pt == P) &&
                        (tiles[end.getRow() + 1][end.getCol()]->colour == Colour::White) &&
                        (tiles[end.getRow() + 1][end.getCol()]->isEnPassanable)) {
                            return true;
                        }
                }
            }
    }
    return false;
}

bool Board::enPassant(Colour turn, Coord start, Coord end) {
    movePiece(start, end);
    if (turn == Colour::Black) {
        charTiles[end.getRow() + 1][end.getCol()] = '-';
        tiles[end.getRow() + 1][end.getCol()] = make_shared<Empty>(
            Colour::NoColour, PieceType::X, Coord(end.getRow() + 1, end.getCol())
        );
        return true;
    } else if (turn == Colour::White) {
        charTiles[end.getRow() - 1][end.getCol()] = '-';
        tiles[end.getRow() - 1][end.getCol()] = make_shared<Empty>(
            Colour::NoColour, PieceType::X, Coord(end.getRow() - 1, end.getCol())
        );
        return true;
    }
    return false;
}

void Board::resetEnPassant(Coord end) {
    for (auto &p: whitePieces) {
        if (p->pt == PieceType::P && p->pos != end)  {
            p->isEnPassanable = false;
        }
    }
    for (auto &p: blackPieces) {
        if (p->pt == PieceType::P && p->pos != end)  {
            p->isEnPassanable = false;
        }
    }
}

bool Board::isCastling(Coord start, Coord end) {
    if (((wk->pos.getCol() == start.getCol()) && (wk->pos.getRow() == start.getRow())) ||
        ((bk->pos.getCol() == start.getCol()) && (bk->pos.getRow() == start.getRow()))) {
            if (abs(start.getCol() - end.getCol()) == 2) {
                return true;
            }
        }
    return false;
}

bool Board::castle(Colour turn, Coord start, Coord end) {
   if(turn == Colour::White) {
       //right hand castling
       if(end.getCol() > start.getCol()) {
           //right bottom corner piece is Rook and not moved
           if ((tiles[0][7]->pt == PieceType::R) && !(tiles[0][7]->hasMoved)) {
               //has white king moved?
               if (!(wk->hasMoved)) {
                   //is there any tiles in between?
                   if ((tiles[0][6]->pt == PieceType::X) &&
                        (tiles[0][5]->pt == PieceType::X)) {
                        // is it safe for white king to move there?
                       if (!tempMove(start, tiles[0][6]->pos, &Board::isWhiteInCheck) &&
                            !tempMove(start, tiles[0][5]->pos, &Board::isWhiteInCheck) &&
                            !isWhiteInCheck()) {
                                movePiece(start, end);
                                wk = tiles[end.getRow()][end.getCol()];
                                charTiles[0][5] = charTiles[0][7];
                                tiles[0][5] = tiles[0][7];
                                tiles[0][5]->pos = {0,5};
                                tiles[0][5]->hasMoved = true;
                                charTiles[0][7] = '-';
                                tiles[0][7] = make_shared<Empty>(
                                    Colour::NoColour, PieceType::X, Coord(0,7)
                                );
                                return true;
                       }
                   }
               }
           }
       } else {
           if ((tiles[0][0]->pt == PieceType::R) && !(tiles[0][0]->hasMoved)) {
               if (!(wk->hasMoved)) {
                   if ((tiles[0][2]->pt == PieceType::X) &&
                        (tiles[0][3]->pt == PieceType::X) &&
                        (tiles[0][1]->pt == PieceType::X)) {
                       if (!tempMove(start, tiles[0][2]->pos, &Board::isWhiteInCheck) &&
                            !tempMove(start, tiles[0][3]->pos, &Board::isWhiteInCheck) &&
                            !isWhiteInCheck()) {
                                movePiece(start, end);
                                wk = tiles[end.getRow()][end.getCol()];
                                charTiles[0][3] = charTiles[0][0];
                                charTiles[0][0] = '-';
                                tiles[0][3] = tiles[0][0];
                                tiles[0][3]->pos = {0,3};
                                tiles[0][3]->hasMoved = true;
                                tiles[0][0] = make_shared<Empty>(
                                    Colour::NoColour, PieceType::X, Coord(0,0)
                                );
                                return true;
                       }
                   }
               }
           }
       }
   } else {
        if(end.getCol() > start.getCol()) {
           if ((tiles[7][7]->pt == PieceType::R) && !(tiles[7][7]->hasMoved)) {
               if (!(bk->hasMoved)) {
                   if ((tiles[7][6]->pt == PieceType::X) &&
                        (tiles[7][5]->pt == PieceType::X)) {
                       if (!tempMove(start, tiles[7][6]->pos, &Board::isBlackInCheck) &&
                            !tempMove(start, tiles[7][5]->pos, &Board::isBlackInCheck) &&
                            !isBlackInCheck()) {
                                movePiece(start, end);
                                tiles[end.getRow()][end.getCol()]->hasMoved = true;
                                bk = tiles[end.getRow()][end.getCol()];
                                charTiles[7][5] = charTiles[7][7];
                                charTiles[7][7] = '-';
                                tiles[7][5] = tiles[7][7];
                                tiles[7][5]->pos = {7,5};
                                tiles[7][5]->hasMoved = true;
                                tiles[7][7] = make_shared<Empty>(
                                    Colour::NoColour, PieceType::X, Coord(7,7)
                                );
                                return true;
                       }
                   }
               }
           }
       } else {
           if ((tiles[7][0]->pt == PieceType::R) && !(tiles[7][0]->hasMoved)) {
               if (!(bk->hasMoved)) {
                   if ((tiles[7][2]->pt == PieceType::X) &&
                        (tiles[7][3]->pt == PieceType::X) &&
                        (tiles[7][1]->pt == PieceType::X)) {
                       if (!tempMove(start, tiles[7][2]->pos, &Board::isBlackInCheck) &&
                            !tempMove(start, tiles[7][3]->pos, &Board::isBlackInCheck) &&
                            !isBlackInCheck()) {
                                movePiece(start, end);
                                tiles[end.getRow()][end.getCol()]->hasMoved = true;
                                bk = tiles[end.getRow()][end.getCol()];
                                charTiles[7][3] = charTiles[7][0];
                                charTiles[7][0] = '-';
                                tiles[7][3] = tiles[7][0];
                                tiles[7][3]->pos = {7,3};
                                tiles[7][3]->hasMoved = true;
                                tiles[7][0] = make_shared<Empty>(
                                    Colour::NoColour, PieceType::X, Coord(7,0)
                                );
                                return true;
                       }
                   }
               }
           }
       }
   }
   return false;
}

bool Board::isPawnPromotion(const Colour turn, const Coord start, const Coord end) {
    shared_ptr<Piece> startPiece = tiles[start.getRow()][start.getCol()];
    if (startPiece->pt == PieceType::P) {
        if ((turn == Colour::White && end.getRow() == 7) ||
            (turn == Colour::Black && end.getRow() == 0)) {
            return startPiece->isLegalMove(start, end, tiles);
        }
    }
    return false;
}

void Board::promotePawn(const Coord start, const Coord end, const char promoteTo) {
    removePiece(start);
    addCharPiece(promoteTo, end.getRow(), end.getCol());
}


bool Board::computerL1Move(const Colour turn) {
    if (turn == Colour::White) {
        for (auto &wp: whitePieces) {
            for (int col = 0; col < (int)tiles.size(); ++col) {
                for (int row = 0; row < (int)tiles[col].size(); ++row) {
                    Coord end{row, col};
                    // Always want promotion to queen if possible
                    if (isLegalMove(turn, wp->pos, end, 'Q')) {
                        return true;
                    }
                }
            }
        }
    } else {
        for (auto &bp: blackPieces) {
           for (int col = 0; col < (int)tiles.size(); ++col) {
                for (int row = 0; row < (int)tiles[col].size(); ++row) {
                    Coord end{row, col};
                    if (isLegalMove(turn, bp->pos, end, 'q')) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Board::computerL2Move(Colour turn) {
    // Prefer capture
    for (auto &bp: blackPieces) {
        for (auto &wp: whitePieces) {
            if (turn == Colour::White) {
                if (isLegalMove(turn, wp->pos, bp->pos, 'Q')) {
                    return true;
                }
            } else {
                if (isLegalMove(turn, bp->pos, wp->pos, 'q')) {
                    return true;
                }
            }
        }
    }
    // Prefer checking
    if (turn == Colour::White) {
        for (auto &wp: whitePieces) {
            for (int col = 0; col < (int)tiles.size(); ++col) {
                for (int row = 0; row < (int)tiles[col].size(); ++row) {
                    Coord end{row, col};
                    if (tempMove(wp->pos, end, &Board::isBlackInCheck) &&
                        isLegalMove(turn, wp->pos, end, 'Q')) {
                        return true;
                    }
                }
            }
        }
    } else {
        for (auto &bp: blackPieces) {
           for (int col = 0; col < (int)tiles.size(); ++col) {
                for (int row = 0; row < (int)tiles[col].size(); ++row) {
                    Coord end{row, col};
                    if (tempMove(bp->pos, end, &Board::isWhiteInCheck) &&
                        isLegalMove(turn, bp->pos, end, 'Q')) {
                        return true;
                    }
                }
            }
        }
    }

    // Makes random move if no others are possible
    return computerL1Move(turn);
}

// void Board::computerL3Move(Colour turn) {
// }
