#include "king.h"
using namespace std;

King::King(Colour colour, PieceType pt): Piece{colour, pt} {}

bool King::isLegalMove(const Coord start, const Coord end,
                        vector<vector<shared_ptr<Piece>>> &tiles) {
    // Is used in endGame detection, when Board::isLegalMove() isn't called
    if (end.row < 0 || end.row > 7 || end.col < 0 || end.col > 7 ||
        start.row < 0 || start.row > 7 || start.col < 0 || start.col > 7) {
        return false;
    }

    //King cannot move more than 1 tiles
    if ((abs(start.getRow() - end.getRow()) <= 1) &&
        (abs(start.getCol() - end.getCol()) <= 1)) {
        return true;
    }

    return false;
}
