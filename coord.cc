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
    char row;
    int col;
    cin >> row;
    cin >> col;

    c.row = c.rowIdx[row];
    c.col = col - 1;
    return in;
}
