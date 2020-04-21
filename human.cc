#include "human.h"
using namespace std;


Human::Human(Colour c, int score): Player(c, score) {}
Human::~Human() {}

void Human::move(Move m) {
    State s{MoveType::H, m, c};
    setState(s);
    notify();
}

//void Human::undo(void);
//void Human::redo(void);