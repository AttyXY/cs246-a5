#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include <memory>
#include "piece.h"
#include "move.h"

class Pawn: public Piece {
     public:
         Pawn(Colour colour);
         bool isLegal(Move m,
                      std::vector<std::vector<std::shared_ptr<Piece>>> &tile);
 };

 #endif