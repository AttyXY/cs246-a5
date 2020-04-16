#include "human.h"


Human::Human(Colour c, int score): Player(c, score) {}
Human::~Human() {}

/*
void Human::move(Move m) {
    State s{m, c};
    this->setState(s);
    this->notify();
}
*/

//void Human::undo(void);
//void Human::redo(void);