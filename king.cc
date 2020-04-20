#include "king.h"
using namespace std;

King::King(Colour colour, PieceType pt): Piece{colour, pt} {}

bool King::isLegalMove(const Coord start, const Coord end,
                        vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    //King cannot move more than 1 tiles
    if ((abs(start.getRow() - end.getRow()) <= 1) &&
        (abs(start.getCol() - end.getCol()) <= 1)) {
        return true;
    }

    return false;
}
