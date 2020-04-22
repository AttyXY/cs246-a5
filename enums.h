#ifndef ENUMS_H
#define ENUMS_H
#include <map>
#include <string>

enum Colour { NoColour, Black, White };
enum PieceType { P='P', B='B', N='N', R='R', Q='Q', K='K', X='X'};
enum MoveType { H, L1, L2, L3, L4 };

extern std::map<Colour, std::string> colourToStr;
extern std::map<char, PieceType> charToPiece;
extern std::map<std::string, PieceType> strToPiece;



#endif