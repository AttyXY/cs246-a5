#include "queen.h"
using namespace std;

Queen::Queen(Colour colour, PieceType pt): Piece{colour, pt} {}

bool Queen::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    //Constant
    int ver = abs(m.start.getRow() - m.end.getRow());
    int hor = abs(m.start.getCol() - m.end.getCol());

    //Queen can move vertically
    if (m.start.getCol() == m.end.getCol()) {
        if(m.start.getRow() > m.end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[m.start.getCol()][m.start.getRow() - n] != nullptr) {
                    return false;
                }
            }
            return true;
        }
        if (m.start.getRow() < m.end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[m.start.getCol()][m.start.getRow() + n] != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }

    //Queen can move horizontally
    if (m.start.getRow() == m.end.getRow()) {
        if(m.start.getCol() > m.end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[m.start.getCol() - n][m.start.getRow()] != nullptr) {
                    return false;
                }
            }
            return true;
        }

        if(m.start.getCol() < m.end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[m.start.getCol() + n][m.start.getRow()] != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }

    //Queen can move diagonally
    if(hor == ver) {
        if(m.start.getCol() > m.end.getCol()) {
            if(m.start.getRow() > m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getCol() - n][m.start.getRow() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(m.start.getRow() < m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getCol() - n][m.start.getRow() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
        if(m.start.getCol() < m.end.getCol()) {
            if(m.start.getRow() > m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getCol() + n][m.start.getRow() - n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            if(m.start.getRow() < m.end.getRow()) {
                for(int n = 1; n < hor; n++) {
                    if(tiles[m.start.getCol() + n][m.start.getRow() + n] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}