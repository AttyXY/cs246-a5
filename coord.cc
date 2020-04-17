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
    cout << toupper(c.row) << c.col;
    return out;
}

istream &operator>>(istream &in, Coord &c) {
    char col;
    int row;
    cin >> col;
    cin >> row;

    c.col = c.colIdx[col];
    c.row = row - 1;

    // validate input
    if (c.col < 0 || c.col > 7 || c.row < 0 || c.row > 7) {
        throw invalid_argument("Invalid coordinate.");
    }
    return in;
}
