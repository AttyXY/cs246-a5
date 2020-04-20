#include "rook.h"
using namespace std;

Rook::Rook(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool Rook::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //Constant
    int ver = abs(start.getRow() - end.getRow());
    int hor = abs(start.getCol() - end.getCol());

    //Rook can move vertically
    if (start.getCol() == end.getCol()) {
        if (start.getRow() > end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[start.getRow() - n][start.getCol()] != nullptr) {
                    return false;
                }
            }
            return true;
        }
        if (start.getRow() < end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[start.getRow() + n][start.getCol()] != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }

    //Rook can move horizontally
    if (start.getRow() == end.getRow()) {
        if(start.getCol() > end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[start.getRow()][start.getCol() - n] != nullptr) {
                    return false;
                }
            }
            return true;
        }

        if (start.getCol() < end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[start.getRow()][start.getCol() + n] != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void Rook::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    int ver = abs(pos.getRow() - king.getRow());
    int hor = abs(pos.getCol() - king.getCol());

    // Vertical
    if (pos.getCol() == king.getCol()) {
        if (pos.getRow() > king.getRow()) {
            for (int n = 1; n < ver; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow() - n, pos.getCol()));
            }
        }
        if (pos.getRow() < king.getRow()) {
            for (int n = 1; n < ver; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow() + n, pos.getCol()));
            }
        }
    }

    // Horizontal
    if (pos.getRow() == king.getRow()) {
        if(pos.getCol() > king.getCol()) {
            for(int n = 1; n < hor; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow(), pos.getCol() - n));
            }
        }

        if (pos.getCol() < king.getCol()) {
            for(int n = 1; n < hor; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow(), pos.getCol() + n));
            }
        }
    }
}