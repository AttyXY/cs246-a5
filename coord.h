#ifndef COORD_H
#define COORD_H
#include <iostream>
#include <map>

class Coord {
    public:
        int row;
        int col;
        std::map<char, int> rowIdx = {
            {'a', 0},
            {'b', 1},
            {'c', 2},
            {'d', 3},
            {'e', 4},
            {'f', 5},
            {'g', 6},
            {'h', 7}
        };

        Coord(int row = 0, int col = 0);
        ~Coord();
};

std::ostream &operator<<(std::ostream &out, const Coord &c);
std::istream &operator>>(std::istream &in, Coord &c);

#endif