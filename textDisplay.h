#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <iostream>
// #include <vector>
#include "subject.h"
#include "display.h"
#include "state.h"

class TextDisplay: public Display {
    public:
        TextDisplay();
        // ~TextDisplay();
        void notify(Subject<State> &whoFrom); // This updates the textDisplay with the grid it receives
};


std::ostream &operator<<(std::ostream &out, const TextDisplay &d);
std::istream &operator>>(std::istream &in, TextDisplay &d);

#endif