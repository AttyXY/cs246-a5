#ifndef GRAPH_DISPLAY_H
#define GRAPH_DISPLAY_H
#include <iostream>
#include <vector>
#include "window.h"

class GraphDisplay {
    public:
        vector<vector<char>> pieces;
        XWindow xw;
        void update(void);

        GraphDisplay();
        ~GraphDisplay();
};

std::ostream &operator<<(std::ostream &out, const GraphDisplay &d);
std::istream &operator>>(std::istream &in, GraphDisplay &d);

#endif