#include "queen.h"
using namespace std;

Queen::Queen(Colour colour, PieceType pt): Piece{colour, pt} {}

bool Queen::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    //Check if the end is out of the grid
    if (m.end.getRow() < 0 || m.end.getRow() > 7 || m.end.getCol() < 0 || m.end.getCol() > 7) {
        return false;
    }

    //Check if the end if occupied by own colour
    if ((tiles[m.start.getCol()][m.start.getRow()]->colour == tiles[m.end.getCol()][m.end.getRow()]->colour)
            && tiles[m.end.getCol()][m.end.getRow()] != nullptr) {
                return false;
    }

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