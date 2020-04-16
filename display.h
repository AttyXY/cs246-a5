#ifndef DISPLAY_H
#define DISPLAY_H
// #include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "state.h"

class Display: public Observer<State> {
    protected:
        std::vector<std::vector<char>> tiles;
    // public:
    //     void update(void);
    //     void update(Subject<State> &whoFrom);
    //     Display();
    //     ~Display();
};

#endif