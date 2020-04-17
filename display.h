#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include "observer.h"
#include "state.h"

class Display: public Observer<State> {
    public:
        std::vector<std::vector<char>> tiles;

    // public:
    //     void update(void);
    //     void update(Subject<State> &whoFrom);
    //     Display();
    //     ~Display();
};

#endif