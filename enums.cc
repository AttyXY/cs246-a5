#include "enums.h"
using namespace std;

map<Colour, string> colourToStr = {
    {Colour::NoColour, "NoColour"},
    {Colour::Black, "Black"},
    {Colour::White, "White"}
};

map<char, PieceType> charToPiece = {
    { 'P', PieceType::P },
    { 'B', PieceType::B },
    { 'N', PieceType::N },
    { 'R', PieceType::R },
    { 'Q', PieceType::Q },
    { 'K', PieceType::K },
    { 'X', PieceType::X }
};

map<string, PieceType> strToPiece = {
    { "P", PieceType::P },
    { "B", PieceType::B },
    { "N", PieceType::K },
    { "R", PieceType::R },
    { "Q", PieceType::Q },
    { "K", PieceType::K },
    { "X", PieceType::X }
};