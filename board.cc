#include "board.h"
using namespace std;


// Initializes tiles and charTiles with clear boards.
void Board::reset() {
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

// Initializes tiles and charTiles with pieces, from td->tiles.
// Returns false if setup results in check, and true otherwise.
bool Board::init(const vector<vector<char>> &setupTiles) {
    reset();

    // Copy setupTiles into charTiles
    charTiles = setupTiles;

    // Convert setupTiles into board
    for (int col = 0; col < (int)tiles.size(); ++col) {
        for (int row = 0; row < (int)tiles[col].size(); ++row) {
            switch(setupTiles[row][col]) {
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
    }
    if (isCheck()) {
        return false;
    }
    return true;
}




/* Move helpers */
void Board::addPiece(const Coord start, const Coord end) {
    charTiles[end.row][end.col] = charTiles[start.row][start.col];
    tiles[end.row][end.col] = tiles[start.row][start.col];
    tiles[end.row][end.col]->pos = {end.row, end.col};
    if (tiles[end.row][end.col]->pt == PieceType::K) {
        if (tiles[end.row][end.col]->colour == Colour::White) {
            wk = tiles[end.row][end.col];
        } else if (tiles[end.row][end.col]->colour == Colour::Black) {
            bk = tiles[end.row][end.col];
        }
    }
}

void Board::removePiece(const Coord c) {
    charTiles[c.row][c.col] = '-';
    tiles[c.row][c.col] = make_shared<Empty>(
        Colour::NoColour, PieceType::X, Coord(c.row, c.col)
    );
}

void Board::movePiece(const Coord start, const Coord end) {
    addPiece(start, end);
    removePiece(start);
}

// makes and undos Move m, getting and returning result of callback in-between
bool Board::tempMove(Coord start, Coord end, bool (Board::*callback)(bool)) {
    // tempMove
    shared_ptr<Piece> tempPiece = tiles[end.row][end.col];
    char tempChar = charTiles[end.row][end.col];
    movePiece(start, end);

    // get result
    bool result = (this->*callback)(false);

    // undo tempMove
    movePiece(end, start);
    tiles[end.row][end.col] = tempPiece;
    charTiles[end.row][end.col] = tempChar;

    return result;
}

/* Check helpers */
bool Board::isWhiteInCheck(bool setChecker) {
    for (const auto &p: blackPieces) {
        if (p->isLegalMove(p->pos, wk->pos, tiles)) {
            if (setChecker) { checker = p; }
            return true;
        }
    }
    return false;
}

bool Board::isBlackInCheck(bool setChecker) {
    for (const auto &p: whitePieces) {
        if (p->isLegalMove(p->pos, bk->pos, tiles)) {
            if (setChecker) { checker = p; }
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
    bool result = false;

    // check condition
    if (turn == Colour::White) {
        result = tempMove(start, end, &Board::isWhiteInCheck);
    } else if (turn == Colour::Black) {
        result = tempMove(start, end, &Board::isBlackInCheck);
    }

    return result;
}


/* Endgame detection helpers: Run after move has already been made */
bool Board::isWhiteKingStuck() {
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i == 0 && j == 0) { continue; } // same position as before

            Coord start = wk->pos;
            Coord end{wk->pos.getRow() + i, wk->pos.getCol() + j};
            if (tiles[start.row][start.col]->isLegalMove(start, end, tiles)) {
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
            if (tiles[start.row][start.col]->isLegalMove(start, end, tiles)) {
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
        // if (p->pt == PieceType::K) { continue; }
        // for (const auto &coord: lineOfCheck) {
        //     if (p->isLegalMove(p->pos, coord, tiles)) {
        //     return true;
        //     }
        // }
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
        // if (p->pt == PieceType::K) { continue; }
        // for (const auto &coord: lineOfCheck) {
        //     if (p->isLegalMove(p->pos, coord, tiles)) {
        //     return true;
        //     }
        // }
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

// check board state once legal move has been made
void Board::checkEndGame(const Colour turn) {
    blackInCheck = isBlackInCheck(true);
    whiteInCheck = isWhiteInCheck(true);
    if (blackInCheck || whiteInCheck) {
        checkmated = isCheckmate(turn);
    }
    // TODO: stalemate
    // if (isStalemate(whoFrom)) {
    //     stalemated = true;
    // }
    // TODO: threefold repetition
    // TODO: fifty-move-rule
}




/* Move logic */
void Board::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    legalLastMove = isLegalMove(s.colour, s.m.start, s.m.end);

    // update displays
    State newS{s.m, s.colour, charTiles};
    setState(newS);
    notify();
}

bool Board::isLegalMove(const Colour turn, const Coord start, const Coord end) {
    // STANDARD CHECKS
    // Off board
    if (end.row < 0 || end.row > 7 || end.col < 0 || end.col > 7 ||
        start.row < 0 || start.row > 7 || start.col < 0 || start.col > 7) {
        return false;
    }
    // Empty tile || Move other player's piece
    if (tiles[start.row][start.col]->pt == PieceType::X ||
        (turn != tiles[start.row][start.col]->colour)) {
        return false;
    }
    // Move onto own piece
    if (tiles[end.row][end.col]->pt != PieceType::X &&
        turn == tiles[end.row][end.col]->colour) {
        return false;
    }

    // Still in check
    if (isMoveIntoCheck(turn, start, end)) {
    //     if (isStalemate(whoFrom)) {
            // Only possible right after setup, because stalemate is checked
            // for at the end of every move, and ends game
            // stalemated = true;
            // return false;
        // } else {
            // Cannot be checkmate because checkmate immediately ends game, and
            // and setups that begin with check are invalid.
            return false;
    //     }
    }

    // TODO: SPECIAL MOVE CHECKS
    // castling
    // if (isCastling(m)) {
        // cannot be checkmate or stalemate
    //     castle(m);

    // }
    // pawn promotion
    // else if (isPawnPromotion(m)) {
        // promotePawn(whoFrom);
        // checkEndGame(whoFrom);
    // }
    // en passant
    // else if (isEnPassant(m)) {
    //     enPassant(m);
        // checkEndGame(whoFrom);
    // }


    // BASIC MOVE CHECKS
    if (tiles[start.row][start.col]->isLegalMove(start, end, tiles)) {
        movePiece(start, end);
        tiles[end.row][end.col]->hasMoved = true;
        checkEndGame(turn);
    } else {
        return false;
    }
    return true;
}













// bool Board::insufficientMaterial(vector<shared_ptr<Piece>> &opponentPieces) {
//     if (opponentPieces.size() == 1) { // Only king
//         return true;
//     } else if (opponentPieces.size() == 2) { // King and Bishop/Knight
//         for (const auto &p: opponentPieces) {
//             if (p->pt == PieceType::B || PieceType::N) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool Board::isStalemate() {
//     if (insufficientMaterial()) {
//         return true;
//     }
//     for (const auto &p: whitePieces) {
//         if (p->noLegalMove()) {
//             return true;
//         }
//     }
//     return false;
// }
