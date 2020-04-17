#include "coord.h"
using namespace std;

Coord::Coord(int row, int col): row{row}, col{col} {}
Coord::~Coord() {}
int Coord::getRow(void) {
    return row;
}
int Coord::getCol(void) {
    return col;
}

ostream &operator<<(ostream &out, const Coord &c) {
    cout << c.idxToCol.at(c.col) << c.row + 1;
    return out;
}

istream &operator>>(istream &in, Coord &c) {
    char col;
    int row;
    cin >> col;
    cin >> row;

    c.row = row - 1;
    if (c.row < 0 || c.row > 7) {
        throw invalid_argument("Invalid coordinate.");
    }
    try {
        c.col = c.colToIdx.at(col);
    } catch (const out_of_range &e) {
        throw invalid_argument("Invalid coordinate.");
    }

    return in;
}
