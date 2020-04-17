#include "knight.h"
using namespace std;

Knight::Knight(Colour colour, PieceType pt): Piece{colour, pt} {}
bool Knight::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    if ((abs(m.start.getRow() - m.end.getRow()) == 2) &&
        (abs(m.start.getCol() - m.end.getCol()) == 1)) {
        return true;
    } else if ((abs(m.start.getRow() - m.end.getRow()) == 1) &&
               (abs(m.start.getCol() - m.end.getCol()) == 2)) {
        return true;
    }
    return false;
}
