#include "enums.h"
using namespace std;

map<Colour, string> colourToStr = {
    {Colour::NoColour, "NoColour"},
    {Colour::Black, "Black"},
    {Colour::White, "White"}
};

map<PieceType, char> pieceToStr = {
    { P,'P'},
    { B,'B'},
    { N,'N'},
    { R,'R'},
    { Q,'Q'},
    { K,'K'}
};
