#include "knight.h"
using namespace std;

Knight::Knight(Colour colour, PieceType pt): Piece{colour, pt} {}
bool Knight::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    // check if the end is out of the grid
    if (m.end.getRow() < 0 || m.end.getRow() > 7 || m.end.getCol() < 0 || m.end.getCol() > 7) {
        return false;
    }

    // check if the end if occupied by own colour
    if ((tiles[m.start.getCol()][m.start.getRow()]->colour == tiles[m.end.getCol()][m.end.getRow()]->colour)
        && tiles[m.end.getCol()][m.end.getRow()] != nullptr) {
        return false;
    }

    // check if move is valid
    if ((abs(m.start.getRow() - m.end.getRow()) == 2) &&
        (abs(m.start.getCol() - m.end.getCol()) == 1)) {
        return true;
    } else if ((abs(m.start.getRow() - m.end.getRow()) == 1) &&
               (abs(m.start.getCol() - m.end.getCol()) == 2)) {
        return true;
    }
    return false;
}
