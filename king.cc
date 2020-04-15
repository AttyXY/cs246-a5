#include "king.h"
using namespace std;

/*
bool King::isLegal(Coord start, Coord end, vector<vector<shared_ptr<Piece>>> &tile) {
    //check if the end is out of the grid
    if (end.getRow() < 0 || end.getRow() > 7 || end.getCol() < 0 || end.getCol() > 7) {
        return false;
    }

    //check if the end if occupied by own colour
    if ((tile[start.getCol()][start.getRow()]->colour == tile[end.getCol()][end.getRow()]->colour)
            && tile[end.getCol()][end.getRow()] != nullptr) {
                return false;
            }

    //King cannot move more than 1 tile
    if ((abs(start.getRow() - end.getRow()) <= 1) &&
        (abs(start.getCol() - end.getCol()) <= 1)){
            return true;
        }

    return false;
}
*/