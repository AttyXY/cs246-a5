#include "move.h"
using namespace std;

Move::Move(Coord start, Coord end, char promoteTo):
    start{start}, end{end}, promoteTo{promoteTo} {}
Move::~Move() {}
