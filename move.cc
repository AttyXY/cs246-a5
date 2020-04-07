#include "move.h"
using namespace std;

Move::Move(Coord start, Coord end): start{start}, end{end} {}
Move::~Move() {}

std::ostream &operator<<(std::ostream &out, const Move &m) {
    return out;
}

std::istream &operator>>(std::istream &in, Move &m) {
    return in;
}