#include "piece.h"
using namespace std;

Piece::Piece(PieceType type, Colour c, Coord loc): type{type}, c{c}, loc{loc} {}
Piece::~Piece() {}

std::ostream &operator<<(std::ostream &out, const Piece &p) {
    cout << p.type << endl;
    return out;
}
