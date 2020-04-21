#include "knight.h"
using namespace std;

Knight::Knight(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool Knight::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    if ((abs(start.getRow() - end.getRow()) == 2) &&
        (abs(start.getCol() - end.getCol()) == 1)) {
        return true;
    } else if ((abs(start.getRow() - end.getRow()) == 1) &&
               (abs(start.getCol() - end.getCol()) == 2)) {
        return true;
    }
    return false;
}

void Knight::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    return; // knight has no line of check
}

bool Knight::isStuck(vector<vector<shared_ptr<Piece>>> &tiles) {
    Coord topRight1{pos.getRow() + 2, pos.getCol() + 1};
    Coord topRight2{pos.getRow() + 1, pos.getCol() + 2};
    Coord topLeft1{pos.getRow() + 2, pos.getCol() - 1};
    Coord topLeft2{pos.getRow() + 1, pos.getCol() - 2};
    Coord bottomRight1{pos.getRow() - 2, pos.getCol() + 1};
    Coord bottomRight2{pos.getRow() - 1, pos.getCol() + 2};
    Coord bottomLeft1{pos.getRow() - 2, pos.getCol() - 1};
    Coord bottomLeft2{pos.getRow() - 1, pos.getCol() - 2};

    if (isLegalMove(pos, topRight1, tiles)) {
        return false;
    } else if (isLegalMove(pos, topRight2, tiles)) {
        return false;
    } else if (isLegalMove(pos, topLeft1, tiles)) {
        return false;
    } else if (isLegalMove(pos, topLeft2, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomRight1, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomRight2, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomLeft1, tiles)) {
        return false;
    } else if (isLegalMove(pos, bottomLeft2, tiles)) {
        return false;
    }
    return true;
}