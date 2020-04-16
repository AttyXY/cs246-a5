#ifndef DISPLAY_H
#define DISPLAY_H
// #include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "state.h"

class Display: public Observer<State> {
    protected:
        std::vector<std::vector<char>> tile;
    // public:
    //     void update(void);
    //     void notify(Subject<State> &whoFrom);
    //     Display();
    //     ~Display();
};

#endif