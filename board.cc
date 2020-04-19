#include "board.h"
using namespace std;


// Initializes tiles and charTiles with clear boards.
void Board::reset() {
    vector<char> row(8, '-');
	charTiles = vector<vector<char>>(8, row);

    vector<vector<shared_ptr<Piece>>> newTiles;
    for (size_t row = 0; row < charTiles.size(); ++row) {
        newTiles.emplace_back(std::vector<std::shared_ptr<Piece>>());
        for (size_t col = 0; col < charTiles[row].size(); ++col) {
            newTiles[row].emplace_back(nullptr);
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
                    tiles[row][col] =
                        std::make_shared<King>(Colour::Black, PieceType::K);
                    blackPieces.emplace_back(tiles[row][col]);
                    bk = tiles[row][col];
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'K': {
                    tiles[row][col] =
                        std::make_shared<King>(Colour::White, PieceType::K);
                    whitePieces.emplace_back(tiles[row][col]);
                    wk = tiles[row][col];
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'q': {
                    tiles[row][col] =
                        std::make_shared<Queen>(Colour::Black, PieceType::Q);
                    blackPieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'Q': {
                    tiles[row][col] =
                        std::make_shared<Queen>(Colour::White, PieceType::Q);
                    whitePieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'r': {
                    tiles[row][col] =
                        std::make_shared<Rook>(Colour::Black, PieceType::R);
                    blackPieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'R': {
                    tiles[row][col] =
                        std::make_shared<Rook>(Colour::White, PieceType::R);
                    whitePieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'n': {
                    tiles[row][col] =
                        std::make_shared<Knight>(Colour::Black, PieceType::N);
                    blackPieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'N': {
                    tiles[row][col] =
                        std::make_shared<Knight>(Colour::White, PieceType::N);
                    whitePieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'b': {
                    tiles[row][col] =
                        std::make_shared<Bishop>(Colour::Black, PieceType::B);
                    blackPieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'B': {
                    tiles[row][col] =
                        std::make_shared<Bishop>(Colour::White, PieceType::B);
                    whitePieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'p': {
                    tiles[row][col] =
                        std::make_shared<Pawn>(Colour::Black, PieceType::P);
                    blackPieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
                    break;
                }
                case 'P': {
                    tiles[row][col] =
                        std::make_shared<Pawn>(Colour::White, PieceType::P);
                    whitePieces.emplace_back(tiles[row][col]);
                    tiles[row][col]->pos = {row, col};
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
void Board::movePiece(const Move &m) {
    addPiece(m.start, m.end);
    removePiece(m.start);
}

void Board::removePiece(const Coord &c) {
    charTiles[c.row][c.col] = '-';
    tiles[c.row][c.col] = nullptr;
}

void Board::addPiece(const Coord &start, const Coord &end) {
    charTiles[end.row][end.col] = charTiles[start.row][start.col];
    tiles[end.row][end.col] = tiles[start.row][start.col];
    if (tiles[end.row][end.col]->pt == PieceType::K) {
        if (tiles[end.row][end.col]->colour == Colour::White) {
            wk = tiles[end.row][end.col];
        } else if (tiles[end.row][end.col]->colour == Colour::Black) {
            bk = tiles[end.row][end.col];
        }
    }
}

bool Board::isWhiteInCheck() {
    for (const auto &p: blackPieces) {
        Move moveToKing{p->pos, wk->pos};
        if (p->isLegalMove(moveToKing, tiles)) {
            return true;
        }
    }
    return false;
}

bool Board::isBlackInCheck() {
    for (const auto &p: whitePieces) {
        Move newMove{p->pos, bk->pos};
        if (p->isLegalMove(newMove, tiles)) {
            return true;
        }
    }
    return false;
}

bool Board::isCheck() {
    return isWhiteInCheck() || isBlackInCheck();
}


// makes Move m, runs and returns result of func, then immediately undos Move m
template <typename Function> bool Board::tempMove(Move m, Function func) {
    Coord end = m.end;
    Coord start = m.start;
    // move
    shared_ptr<Piece> temp = tiles[end.row][end.col];
    tiles[end.row][end.col] = tiles[start.row][start.col];
    tiles[start.row][start.col] = nullptr;
    bool result = func();

    // undo move
    tiles[start.row][start.col] = tiles[end.row][end.col];
    tiles[end.row][end.col] = temp;

    return result;
}

// Returns true if King will still be in check after move
bool Board::isMoveIntoCheck(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    auto f = [s]() {
        if (s.colour == Colour::White) {
            return isWhiteInCheck();
        } else if (s.colour == Colour::Black) {
            return isBlackInCheck();
        }
        return false;
    }
    return tempMove(f);
}


/* Move logic */
void Board::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    legalLastMove = isLegalMove(whoFrom);

    State newS{s.m, s.colour, charTiles};
    setState(newS);
    notify();
}

bool Board::isLegalMove(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    Move m = s.m;
    Coord start = m.start;
    Coord end = m.end;

    // STANDARD CHECKS
    if (tiles[start.row][start.col] == nullptr ||  // Empty start tile
        (s.colour != tiles[start.row][start.col]->colour)) { // Move other player's piece) {
        return false;
    }
    if (tiles[end.row][end.col] != nullptr &&
        s.colour == tiles[end.row][end.col]->colour) { // Move onto own piece
        return false;
    }

    // LEGAL MOVE CHECKS
    // shared_ptr<Piece> temp = tiles[end.row][end.col];
    // tiles[end.row][end.col] = tiles[start.row][start.col];
    // tiles[start.row][start.col] = nullptr;
    // if (isCheck()) {
    //         if(s.colour == Colour::White) {
    //             if (whiteInCheck) {
    //                 //undo since it's a suicide move
    //                 tiles[start.row][start.col] = tiles[end.row][end.col];
    //                 tiles[end.row][end.col] = temp;
    //                 return false;
    //             } else if (blackInCheck) {
    //                 //TODO: CHECK
    //                 return true;
    //             }
    //         } else if (s.colour == Colour::Black) {
    //             if (whiteInCheck) {
    //                 //TODO: CHECK
    //                 return true;
    //             } else if (blackInCheck){
    //                 tiles[start.row][start.col] = tiles[end.row][end.col];
    //                 tiles[end.row][end.col] = temp;
    //                 return false;
    //             }
    //         }
    // }
    // tiles[start.row][start.col] = tiles[end.row][end.col];
    // tiles[end.row][end.col] = temp;

    // Still in check
    if (isMoveIntoCheck(whoFrom)) {
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
    if (tiles[start.row][start.col]->isLegalMove(m, tiles)) {
        movePiece(m);
        tiles[end.row][end.col]->hasMoved = true;
        // checkEndGame(whoFrom);
    } else {
        return false;
    }
    return true;
}


// check board state once legal move has been made
// void Board::checkEndGame(Subject<State> &whoFrom) {
//     State s = whoFrom.getState();
//     if (s.colour == Colour::White) {
//         if (isCheck()) {
//             whiteInCheck = true;
//             // if (isCheckmate(whoFrom)) {
//             //     checkmated = true;
//             // }
//         }
//     } else if (s.colour == Colour::Black) {
//         if (isCheck()) {
//             blackInCheck = true;
//             // if (isCheckmate(whoFrom)) {
//             //     checkmated = true;
//             // }
//         }
//     }
    // TODO:
    // if (isStalemate(whoFrom)) {
    //     stalemated = true;
    // }
    // TODO: threefold repetition
    // TODO: fifty-move-rule
// }









// bool Board::KingStuck(shared_ptr<King> &k,
//                       vector<shared_ptr<Piece>> opponentPieces) {
//     for (int i = -1; i < 2; ++i) {
//         for (int j = -1; j < 2; ++ j) {
//             if (i == 0 && j == 0) {
//                 continue;
//             }
//             Coord end{i, j};
//             Move m{k->pos, end};
//             auto f = []() { return !isCheck(); }
//             tempMove(m, f);
//         }
//     }
//     return true;
// }

// bool Board::canBlockCheck(const Coord &kingPos, vector<shared_ptr<Piece>> &opponentPieces) {
//     // can capture piece
//     for (const auto &p: opponentPieces) {
//         if (p->isLegalMove(kingPos)) {
//             return true;
//         }
//     }
//     // can block line of check
//     // for (coord in line of check) {
//         for (const auto &p: opponentPieces) {
//             if (p->isLegalMove(coord)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool Board::isCheckmate(Colour turn) {
//     if (turn == Colour::White && KingStuck(wk, blackPieces) &&
//         !canBlockCheck(wk, blackPieces)) {
//         return true;
//     } else if (turn == Colour::Black && blackKingStuck(bk, whitePieces) &&
//         !canBlockCheck(bk, whitePieces)) {
//         return true;
//     }
//     return false;
// }


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
