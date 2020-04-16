#include "piece.h"
using namespace std;

Piece::Piece(Colour colour, PieceType pt): colour{colour}, pt{pt} {}
Piece::~Piece() {}

/*std::ostream &operator<<(std::ostream &out, const Piece &p) {
    cout << p.type << endl;
    return out;
} */
