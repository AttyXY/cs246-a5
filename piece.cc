#include "piece.h"
using namespace std;

Piece::Piece(Colour colour, PieceType pt, Coord pos):
    colour{colour}, pt{pt}, pos{pos} {}
Piece::~Piece() {}


bool Piece::isBasicInvalidMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    // Off board
    if (end.getRow() < 0 || end.getRow() > 7 || end.getCol() < 0 || end.getCol() > 7 ||
        start.getRow() < 0 || start.getRow() > 7 || start.getCol() < 0 || start.getCol() > 7) {
        return true;
    }
    // Empty tile || Move other player's piece
    if (tiles[start.getRow()][start.getCol()]->pt == PieceType::X ||
        colour != tiles[start.getRow()][start.getCol()]->colour) {
        return true;
    }
    // Move onto own piece
    if (tiles[end.getRow()][end.getCol()]->pt != PieceType::X &&
        colour == tiles[end.getRow()][end.getCol()]->colour) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, const Piece &p) {
    cout << p.colour << "::" << p.pt << endl;
    return out;
}