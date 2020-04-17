#include "human.h"

Human::Human(Colour c, int score) : Player(c, score)
{
    playerType = PlayerType::Human;
}

Human::~Human() {}

void Human::move(Move m, char promotion)
{
    State s;
    s.m = m;
    s.c = c;
    s.playerType = PlayerType::Human;
    if(PawnPromotion){
        s.moveType = MoveType::PawnPromotion;
        s.promotion = promotion;
    } else{
        s.moveType = MoveType::Normal;
    }
    
    this->setState(s);
    this->notify();
}

//void Human::undo(void);
//void Human::redo(void);