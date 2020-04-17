#include "king.h"
using namespace std;

King::King(Colour colour, PieceType pt): Piece{colour, pt} {}

bool King::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    //King cannot move more than 1 tiles
    if ((abs(m.start.getRow() - m.end.getRow()) <= 1) &&
        (abs(m.start.getCol() - m.end.getCol()) <= 1)) {
        return true;
    }

    return false;
}
