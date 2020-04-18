#include "bishop.h"
using namespace std;

Bishop::Bishop(Colour colour, PieceType pt): Piece{colour, pt} {}

bool Bishop::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    //Constant
    int ver = abs(m.start.getRow() - m.end.getRow());
    int hor = abs(m.start.getCol() - m.end.getCol());

    //Bishop can move diagonally
    if (hor == ver) {
        if(m.start.getCol() > m.end.getCol()) {
            if(m.start.getRow() > m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getRow() - n][m.start.getCol() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(m.start.getRow() < m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getRow() + n][m.start.getCol() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
        if(m.start.getCol() < m.end.getCol()) {
            if(m.start.getRow() > m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getRow() - n][m.start.getCol() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(m.start.getRow() < m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getRow() + n][m.start.getCol() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
