#include "enums.h"
using namespace std;

map<Colour, string> colourToStr = {
    {Colour::NoColour, "NoColour"},
    {Colour::Black, "Black"},
    {Colour::White, "White"}
};

map<char, PieceType> charToPiece = {
    { 'P', P },
    { 'B', B },
    { 'N', N },
    { 'R', R },
    { 'Q', Q },
    { 'K', K },
    { 'X', X }
};
map<string, PieceType> strToPiece = {
    { "P", PieceType::P },
    { "B", PieceType::B },
    { "N", PieceType::K },
    { "R", PieceType::R },
    { "Q", PieceType::Q },
    { "K", PieceType::K }
};
