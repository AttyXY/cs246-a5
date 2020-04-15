#include "board.h"
using namespace std;

Board::Board(std::vector<std::vector<char>> &setupTiles) {
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
                    tiles[col][row] = std::make_shared<King>(Colour::Black);
                }
                case 'K': {
                    tiles[col][row] = std::make_shared<King>(Colour::White);
                }
                case 'q': {
                    tiles[col][row] = std::make_shared<Queen>(Colour::Black);
                }
                case 'Q': {
                    tiles[col][row] = std::make_shared<Queen>(Colour::White);
                }
                case 'r': {
                    tiles[col][row] = std::make_shared<Rook>(Colour::Black);
                }
                case 'R' {
                    tiles[col][row] = std::make_shared<Rook>(Colour::White);
                }
                case 'n': {
                    tiles[col][row] = std::make_shared<Knight>(Colour::Black);
                }
                case 'N': {
                    tiles[col][row] = std::make_shared<Knight>(Colour::White);
                }
                case 'b': {
                    tiles[col][row] = std::make_shared<Bishop>(Colour::Black);
                }
                case 'B': {
                    tiles[col][row] = std::make_shared<Bishop>(Colour::White);
                }
                case 'p': {
                    tiles[col][row] = std::make_shared<Pawn>(Colour::Black);
                }
                case 'P': {
                    tiles[col][row] = std::make_shared<Pawn>(Colour::White);
                }
            }
        }
    }
    */
}

Board::~Board() {}

/*
void Board::add(Piece p) {}
void Board::remove(Coord c) {}
void Board::update(void) {}
bool Board::move(Move m) {}
//void undo(void)
// void redo(void);
//TextDisplay td;
//GraphDisplay gd;
*/
