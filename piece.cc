#include "piece.h"
using namespace std;

Piece::Piece(Colour colour, PieceType pt): colour{colour}, pt{pt} {}
Piece::~Piece() {}


bool Piece::isBasicInvalidMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    // Off board
    if (end.row < 0 || end.row > 7 || end.col < 0 || end.col > 7 ||
        start.row < 0 || start.row > 7 || start.col < 0 || start.col > 7) {
        return true;
    }
    // Empty tile || Move other player's piece
    if (tiles[start.row][start.col] == nullptr ||
        colour != tiles[start.row][start.col]->colour) {
        return true;
    }
    // Move onto own piece
    if (tiles[end.row][end.col] != nullptr &&
        colour == tiles[end.row][end.col]->colour) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, const Piece &p) {
    cout << p.colour << "::" << p.pt << endl;
    return out;
}