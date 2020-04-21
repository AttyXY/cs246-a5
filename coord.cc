#include "coord.h"
using namespace std;

Coord::Coord(int row, int col): row{row}, col{col} {}

int Coord::getRow(void) const {
    return row;
}
int Coord::getCol(void) const {
    return col;
}

ostream &operator<<(ostream &out, const Coord &c) {
    out << c.idxToCol.at(c.getCol()) << c.getRow() + 1;
    return out;
}

istream &operator>>(istream &in, Coord &c) {
    char col;
    int row;
    in >> col;
    in >> row;

    c.row = row - 1;
    if (c.row < 0 || c.row > 7) {
        throw invalid_argument("Invalid coordinate.");
    }
    try {
        c.col = c.colToIdx.at(tolower(col));
    } catch (const out_of_range &e) {
        throw invalid_argument("Invalid coordinate.");
    }

    return in;
}

bool operator==(const Coord &left, const Coord &right) {
    return (left.getCol() == right.getCol() &&
           left.getRow() == right.getRow());
}
bool operator!=(const Coord &left, const Coord &right) {
    return !(left == right);
}
