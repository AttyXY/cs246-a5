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
