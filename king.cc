#include "king.h"
using namespace std;

King::King(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool King::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //King cannot move more than 1 tiles
    if ((abs(start.getRow() - end.getRow()) <= 1) &&
        (abs(start.getCol() - end.getCol()) <= 1)) {
        return true;
    }

    return false;
}

void King::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    return; // King should never be checking another king
}

bool King::isStuck(vector<vector<shared_ptr<Piece>>> &tiles) {
    return false; // implemented in Board, to use Board::isKingInCheck();
}