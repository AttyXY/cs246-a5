#ifndef KING_H
#define KING_H
#include "piece.h"
#include <vector>
#include <memory>

class King: public Piece {
     public:
         King(Colour colour);
         bool isLegal(Coord, Coord, std::vector<std::vector<std::shared_ptr<Piece>>> &tile);
 };

 #endif