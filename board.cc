#include "board.h"
using namespace std;


Board::~Board() {}

void Board::init(const vector<vector<char>> &setupTiles) {
    // Copy setupTiles into charTiles
    charTiles = setupTiles;

    // Convert setupTiles into board
    for (size_t row = 0; row < charTiles.size(); ++row) {
        tiles.emplace_back(std::vector<std::shared_ptr<Piece>>());
        for (size_t col = 0; col < charTiles[row].size(); ++col) {
            tiles[row].emplace_back(nullptr);
        }
    }

    for (size_t row = 0; row < tiles.size(); ++row) {
        for (size_t col = 0; col < tiles[row].size(); ++col) {
            switch(setupTiles[col][row]) {
                case 'k': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::Black, PieceType::K);
                    blackPieces.emplace_back(tiles[col][row]);
                    bk = tiles[col][row];
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'K': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::White, PieceType::K);
                    whitePieces.emplace_back(tiles[col][row]);
                    wk = tiles[col][row];
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::Black, PieceType::Q);
                    blackPieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'Q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::White, PieceType::Q);
                    whitePieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'r': {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::Black, PieceType::R);
                    blackPieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'R': {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::White, PieceType::R);
                    whitePieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'n': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::Black, PieceType::N);
                    blackPieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'N': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::White, PieceType::N);
                    whitePieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'b': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::Black, PieceType::B);
                    blackPieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'B': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::White, PieceType::B);
                    whitePieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'p': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::Black, PieceType::P);
                    blackPieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
                case 'P': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::White, PieceType::P);
                    whitePieces.emplace_back(tiles[col][row]);
                    tiles[col][row]->pos = {(int)row, (int)col};
                    break;
                }
            }
        }
    }
}


void Board::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    // cout << "From board: " << s.m.start << " " << s.m.end << endl;
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
    if (tiles[end.row][end.col] != nullptr) {
        if ((s.colour == tiles[end.row][end.col]->colour) || // Move onto own piece
            (s.colour != tiles[start.row][start.col]->colour)) { // Move other player's piece
            return false;
        }
    }
    if (tiles[start.row][start.col] == nullptr) { // Empty tile
        return false;
    }

    // TODO: LEGAL MOVE CHECKS
    shared_ptr<Piece> temp = tiles[end.row][end.col];
    tiles[end.row][end.col] = tiles[start.row][start.col];
    tiles[start.row][start.col] = nullptr;
    if (isCheck(m)) {
            if(s.colour == Colour::White) {
                if (whiteInCheck) {
                    //undo since it's a suicide move
                    tiles[start.row][start.col] = tiles[end.row][end.col];
                    tiles[end.row][end.col] = temp;
                    return false;
                } else if (blackInCheck) {
                    //TODO: CHECK
                    return true;
                }
            } else if (s.colour == Colour::Black) {
                if (whiteInCheck) {
                    //TODO: CHECK
                    return true;
                } else if (blackInCheck){
                    tiles[start.row][start.col] = tiles[end.row][end.col];
                    tiles[end.row][end.col] = temp;
                    return false;
                }
            }
    }
    tiles[start.row][start.col] = tiles[end.row][end.col];
    tiles[end.row][end.col] = temp;
    // // TODO: stalemate
    // bool isStalemate(Move m) {
    //     // Insufficient pieces
    //     if (King and Bishop || King and Knight) {

    //     }
    //     // No legal moves
    //     for (auto &p: pieces) {if (p.legalMove(m))}
    // }
    // if (isStalemate(m)) {

    // }
    // TODO: threefold repetition
    // TODO: fifty-move-rule

    // TODO: SPECIAL MOVE CHECKS
    // TODO: castling
    // if (isCastling(m)) {
    //     castle(m);
    // }
    // TODO: pawn promotion
    // else if (isPawnPromotion(m)) {

    // }
    // TODO: en passant
    // else if (isEnPassant(m)) {
    //     enPassant(m);
    // }

    // BASIC MOVE CHECKS
    if (tiles[start.row][start.col]->isLegalMove(m, tiles)) {
        movePiece(m);
        tiles[end.row][end.col]->hasMoved = true;
    } else {
        return false;
    }

    return true;
}

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

bool Board::isCheck(Move m) {
    for (int n = 0; n < (int)blackPieces.size(); n++) {
        Move newMove{blackPieces[n]->pos, wk->pos};
        if (blackPieces[n]->isLegalMove(newMove, tiles)) {
            whiteInCheck = true;
            return true;
        }
    }
    for (int n = 0; n < (int)whitePieces.size(); n++) {
        Move newMove{whitePieces[n]->pos, bk->pos};
        if (whitePieces[n]->isLegalMove(newMove, tiles)) {
            blackInCheck = true;
            return true;
        }
    }
    return false;
}
