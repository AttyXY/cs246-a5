#include "pawn.h"
using namespace std;

Pawn::Pawn(Colour colour) : Piece{colour} {}
bool Pawn::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tile) {
    // First move
    if (!hasMoved) {

    }
    if (m.end.getCol() - m.start.getCol() != 1) {
        return false;
    } else if (m.end.getRow() - m.start.getRow() <= 1) {

    }
    // En passant
    return true;
}