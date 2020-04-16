#include "knight.h"
using namespace std;

Knight::Knight(Colour colour, PieceType pt): Piece{colour, pt} {}
bool Knight::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    return false;
}
