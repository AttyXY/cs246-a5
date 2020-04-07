#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>

class Display {
    public:
        vector<vector<char>> pieces;
        void update(void);

        Display();
        ~Display();
};


std::ostream &operator<<(std::ostream &out, const Display &d);
std::istream &operator>>(std::istream &in, Display &d);

#endif