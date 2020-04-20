#include "empty.h"
using namespace std;

Empty::Empty(Colour colour, PieceType pt, Coord pos): Piece{colour, pt, pos} {}

bool Empty::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    return false;
}
