#include "human.h"
using namespace std;


Human::Human(Colour c, int score): Player(c, score) {}
Human::~Human() {}

void Human::move(Coord start, Coord end) {
    State s{start, end, c};
    setState(s);
    notify();
}

//void Human::undo(void);
//void Human::redo(void);