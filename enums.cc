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
    { K,'K'},
    { X,'X'}
};
// map<PieceType, char> pieceToStr = {
//     { PieceType::NoPiece, '-'},
//     { PieceType::Pawn,'P'},
//     { PieceType::Bishop,'B'},
//     { PieceType::Knight,'N'},
//     { PieceType::Rook,'R'},
//     { PieceType::Queen,'Q'},
//     { PieceType::King,'K'}
// };
