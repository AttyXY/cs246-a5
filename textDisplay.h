#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <iostream>
#include <vector>

class TextDisplay {
    public:
        vector<vector<char>> pieces;
        void update(void);

        TextDisplay();
        ~TextDisplay();
};


std::ostream &operator<<(std::ostream &out, const TextDisplay &d);
std::istream &operator>>(std::istream &in, TextDisplay &d);

#endif