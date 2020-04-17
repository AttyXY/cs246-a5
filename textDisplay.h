#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <iostream>
#include "display.h"
#include "subject.h"
#include "state.h"
#include "coord.h"
#include "utils.h"

class TextDisplay: public Display {
    public:
        TextDisplay();
        bool setupTiles(bool &isWhiteTurn, bool custom = false);
        bool isValidSetup();
        void printTiles();

        void update(Subject<State> &whoFrom); // This updates the textDisplay with the grid it receives
};

#endif