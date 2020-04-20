#ifndef GRAPH_DISPLAY_H
#define GRAPH_DISPLAY_H
#include <iostream>
#include <vector>
#include "window.h"
#include "display.h"
#include "subject.h"
#include "state.h"

class GraphDisplay:public BoardDisplay {
        Xwindow xw;
    public:
        GraphDisplay();
        // bool setupTiles(bool &isWhiteTurn, bool custom = false);
        bool setupTiles(const std::vector<std::vector<char>> &setupTiles);
        void update(Subject<State> &whoFrom);
        void reset() override;
};

#endif