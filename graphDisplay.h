#ifndef GRAPH_DISPLAY_H
#define GRAPH_DISPLAY_H
#include <vector>
#include "window.h"
#include "display.h"
#include "subject.h"
#include "state.h"
#include "coord.h"
#include "utils.h"

class GraphDisplay:public BoardDisplay {
    Xwindow xw;
    void reset() override;

    public:
        GraphDisplay();
        bool setupTiles(bool &isWhiteTurn, bool custom = false);
        void updateTiles(const std::vector<std::vector<char>> &setupTiles);
        void update(Subject<State> &whoFrom);
};

#endif