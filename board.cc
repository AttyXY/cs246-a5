#include "board.h"
using namespace std;

Board::Board() {
    // vector<char> row(8, '-');
	// charTiles = vector<vector<char>>(8, row);
}

void Board::init(vector<vector<char>> &setupTiles) {
    // Copy setupTiles into charTiles
    charTiles = setupTiles;

    // TODO: Convert setupTiles into board
    for (int row = 0; row < 8; ++row) {
        tiles.emplace_back(std::vector<std::shared_ptr<Piece>>());
        for (int col = 0; col < 8; ++col) {
            tiles[col].emplace_back(nullptr);
        }
    }


    /*
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8, ++col) {
            switch(setupTiles[col][row]) {
                case 'k': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::Black, PieceType::K);
                }
                case 'K': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::White, PieceType::K);
                }
                case 'q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::Black, PieceType::Q);
                }
                case 'Q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::White, PieceType::Q);
                }
                case 'r': {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::Black, PieceType::R);
                }
                case 'R' {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::White, PieceType::R);
                }
                case 'n': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::Black, PieceType::N);
                }
                case 'N': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::White, PieceType::N);
                }
                case 'b': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::Black, PieceType::B);
                }
                case 'B': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::White, PieceType::B);
                }
                case 'p': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::Black, PieceType::P);
                }
                case 'P': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::White, PieceType::P);
                }
            }
        }
    }
    td = std::make_shared<TextDisplay();

    this->attach(td.get());
    this->attach(gd.get());
    this->setState(State{StateType::NewGrid, Move{MoveType::NoType, Coordinate{},
                                                    Coordinate{}, '-', tempGrid}});
    this->notify();

    */
    //gd = std::make_shared<GraphicsDisplay>();
}

Board::~Board() {}

bool Board::move(Move m) {
    /* LEGAL MOVE CHECKS
    // TODO: check
    if (isCheck(m)) {
        whiteInCheck = true;
        blackInCheck = true;
        // TODO: checkmate
    }
    // TODO: stalemate
    bool isStalemate(Move m) {
        // Insufficient pieces
        if (King and Bishop || King and Knight) {

        }
        // No legal moves
        for (auto &p: pieces) {if (p.legalMove(m))}
    }
    if (isStalemate(m)) {

    }
    // TODO: threefold repetition
    // TODO: fifty-move-rule
    */

    /* VALID MOVE CHECKS
    shared_ptr<Piece> p = grid[m.start.col][m.start.row];

    // TODO: castling
    if (isCastling(m)) {
        castle(m);
    }
    // TODO: pawn promotion
    else if (isPawnPromotion(m)) {

    }
    // TODO: en passant
    else if (isEnPassant(m)) {
        enPassant(m);
    }

    // regular move
    else if (p.IsLegal(m)) {
        b.move(p, m)
        p.hasMoved = true;
    }
    else {
        lastMoveValid = false;
    }
    */

    return false;
}

/*
void Board::add(Piece p) {}
void Board::remove(Coord c) {}
void Board::update(void) {}
//void undo(void)
// void redo(void);
//TextDisplay td;
//GraphDisplay gd;
*/
