#include "piece.h"
using namespace std;

Piece::Piece(Colour c): c{c} {}
Piece::~Piece() {}

std::ostream &operator<<(std::ostream &out, const Piece &p) {
    cout << p.type << endl;
    return out;
}
