#include "queen.h"
using namespace std;

Queen::Queen(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool Queen::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //Constant
    int ver = abs(start.getRow() - end.getRow());
    int hor = abs(start.getCol() - end.getCol());

    //Queen can move vertically
    if (start.getCol() == end.getCol()) {
        if (start.getRow() > end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[start.getRow() - n][start.getCol()]->pt != PieceType::X) {
                    return false;
                }
            }
            return true;
        }
        if (start.getRow() < end.getRow()) {
            for(int n = 1; n < ver; n++) {
                if(tiles[start.getRow() + n][start.getCol()]->pt != PieceType::X) {
                    return false;
                }
            }
            return true;
        }
    }

    //Queen can move horizontally
    if (start.getRow() == end.getRow()) {
        if(start.getCol() > end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[start.getRow()][start.getCol() - n]->pt != PieceType::X) {
                    return false;
                }
            }
            return true;
        }

        if (start.getCol() < end.getCol()) {
            for(int n = 1; n < hor; n++) {
                if(tiles[start.getRow()][start.getCol() + n]->pt != PieceType::X) {
                    return false;
                }
            }
            return true;
        }
    }

    //Queen can move diagonally
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

void Queen::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    int ver = abs(pos.getRow() - king.getRow());
    int hor = abs(pos.getCol() - king.getCol());

    // Diagonal
    if (hor == ver) {
        int spacesMoved = ver;
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

bool Queen::isStuck(vector<vector<shared_ptr<Piece>>> &tiles) {
    Coord top{pos.getRow() + 1, pos.getCol()};
    Coord bottom{pos.getRow() - 1, pos.getCol()};
    Coord left{pos.getRow(), pos.getCol() - 1};
    Coord right{pos.getRow(), pos.getCol() + 1};
    if (isLegalMove(pos, top, tiles) && tiles[pos.getRow() + 1][pos.getCol()]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, bottom, tiles) && tiles[pos.getRow() - 1][pos.getCol()]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, left, tiles) && tiles[pos.getRow()][pos.getCol() - 1]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, right, tiles) && tiles[pos.getRow()][pos.getCol() + 1]->pt != PieceType::X) {
        return false;
    }

    Coord topRight{pos.getRow() + 1, pos.getCol() + 1};
    Coord topLeft{pos.getRow() + 1, pos.getCol() - 1};
    Coord bottomRight{pos.getRow() - 1, pos.getCol() + 1};
    Coord bottomLeft{pos.getRow() - 1, pos.getCol() - 1};
    if (isLegalMove(pos, topRight, tiles) && tiles[pos.getRow() + 1][pos.getCol() + 1]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, topLeft, tiles) && tiles[pos.getRow() + 1][pos.getCol() - 1]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, bottomRight, tiles) && tiles[pos.getRow() - 1][pos.getCol() + 1]->pt != PieceType::X) {
        return false;
    } else if (isLegalMove(pos, bottomLeft, tiles) && tiles[pos.getRow() - 1][pos.getCol() - 1]->pt != PieceType::X) {
        return false;
    }
    return true;
}