#include "bishop.h"
using namespace std;

Bishop::Bishop(Colour colour, PieceType pt): Piece{colour, pt} {}

bool Bishop::isLegalMove(const Coord start, const Coord end, vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //Constant
    int ver = abs(start.getRow() - end.getRow());
    int hor = abs(start.getCol() - end.getCol());

    //Bishop can move diagonally
    if (hor == ver) {
        if(start.getCol() > end.getCol()) {
            if(start.getRow() > end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() - n][start.getCol() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(start.getRow() < end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() + n][start.getCol() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
        if(start.getCol() < end.getCol()) {
            if(start.getRow() > end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() - n][start.getCol() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(start.getRow() < end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[start.getRow() + n][start.getCol() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
