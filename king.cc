#include "king.h"
using namespace std;

King::King(Colour colour, PieceType pt): Piece{colour, pt} {}

bool King::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    //check if the end is out of the grid
    if (m.end.getRow() < 0 || m.end.getRow() > 7 || m.end.getCol() < 0 || m.end.getCol() > 7) {
        return false;
    }

    //check if the end if occupied by own colour
    if ((tiles[m.start.getCol()][m.start.getRow()]->colour == tiles[m.end.getCol()][m.end.getRow()]->colour)
        && tiles[m.end.getCol()][m.end.getRow()] != nullptr) {
        return false;
    }

    //King cannot move more than 1 tiles
    if ((abs(m.start.getRow() - m.end.getRow()) <= 1) &&
        (abs(m.start.getCol() - m.end.getCol()) <= 1)) {
        return true;
    }

    return false;
}
