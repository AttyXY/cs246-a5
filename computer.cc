#include "computer.h"
using namespace std;


Computer::Computer(Colour c, int score, int level) :
    Player(c, score), level{level} {}

Computer::~Computer() {}

void Computer::move(Move m) {
    State s{m, c};
    setState(s);
    notify();
}