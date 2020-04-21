#include "computer.h"
using namespace std;


Computer::Computer(Colour c, int score, int level) :
    Player(c, score), level{level} {}

Computer::~Computer() {}

void Computer::move(Move m) {
    State s{MoveType::L1, m, c};
    setState(s);
    notify();
}