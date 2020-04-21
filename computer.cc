#include "computer.h"
using namespace std;


Computer::Computer(int level, Colour c, int score) :
    Player(c, score), level{level} {}

Computer::~Computer() {}

void Computer::move(Move m) {
    State s;
    if (level == 1) {
        s = State{MoveType::L1, m, c};
    } else if (level == 2) {
        s = State{MoveType::L2, m, c};
    } else if (level == 3) {
        s = State{MoveType::L3, m, c};
    }
    setState(s);
    notify();
}