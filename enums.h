#ifndef ENUMS_H
#define ENUMS_H
#include <map>
#include <string>

enum Colour { NoColour, Black, White };
enum PieceType { P='P', B='B', N='N', R='R', Q='Q', K='K'};

extern std::map<Colour, std::string> colourToStr;
extern std::map<PieceType, char> pieceToStr;


extern std::map<Colour, std::string> colourToStr;
extern std::map<PieceType, char> pieceToStr;


#endif