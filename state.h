#ifndef STATE_H
#define STATE_H
#include "enums.h"
#include "coord.h"

/* State types are:
    TODO
*/

enum class StateType {NewTile, /*PlayerMove,*/ UpdatingBoard, /*NoType*/};
enum class MoveType { PawnPromotion, Castle, Normal, NoType, Enpassant };

struct Move {
  MoveType moveType;
  Coord newLoc;
  Coord oldLoc;
  char pawnPromotion;
  std::vector<std::vector<char>> tile;
};

struct State {
  StateType type;
  Move move;
  Colour c;
};

#endif
