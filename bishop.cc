#include "bishop.h"
using namespace std;

Bishop::Bishop(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool Bishop::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //Constant
    int ver = abs(start.getRow() - end.getRow());
    int hor = abs(start.getCol() - end.getCol());

    //Bishop can move diagonally
    if (hor == ver) {
        if(start.getCol() > end.getCol()) {
            if(start.getRow() > end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() - n][start.getCol() - n]->pt != PieceType::X) {
                        return false;
                    }
                }
                return true;
            }
            if(start.getRow() < end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() + n][start.getCol() - n]->pt != PieceType::X) {
                        return false;
                    }
                }
                return true;
            }
        }
        if(start.getCol() < end.getCol()) {
            if(start.getRow() > end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() - n][start.getCol() + n]->pt != PieceType::X) {
                        return false;
                    }
                }
                return true;
            }
            if(start.getRow() < end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() + n][start.getCol() + n]->pt != PieceType::X) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void Bishop::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    int spacesMoved = abs(pos.getRow() - king.getRow()); // assume ver == her
    if (pos.getCol() > king.getCol()) {
        if (pos.getRow() > king.getRow()) {
            for (int n = 1; n < spacesMoved; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow()- n, pos.getCol() - n));
            }
        }
        if (pos.getRow() < king.getRow()) {
            for (int n = 1; n < spacesMoved; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow()+ n, pos.getCol() - n));
            }
        }
    }
    if (pos.getCol() < king.getCol()) {
        if (pos.getRow() > king.getRow()) {
            for (int n = 1; n < spacesMoved; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow()- n, pos.getCol() + n));
            }
        }
        if (pos.getRow() < king.getRow()) {
            for(int n = 1; n < spacesMoved; n++) {
                lineOfCheck.emplace_back(Coord(pos.getRow()+ n, pos.getCol() + n));
            }
        }
    }
}

bool Bishop::isStuck(vector<vector<shared_ptr<Piece>>> &tiles) {
    Coord topRight{pos.getRow() + 1, pos.getCol() + 1};
    Coord topLeft{pos.getRow() + 1, pos.getCol() - 1};
    Coord bottomRight{pos.getRow() - 1, pos.getCol() + 1};
    Coord bottomLeft{pos.getRow() - 1, pos.getCol() - 1};

    if (isLegalMove(pos, topRight, tiles)) {
        return false;
    } else if (isLegalMove(pos, topLeft, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomRight, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomLeft, tiles)) {
        return false;
    }
    return true;
}
