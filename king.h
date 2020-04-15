#ifndef KING_H
#define KING_H
#include "piece.h"

class King: public Piece {
    public:
        King(Colour colour);
        bool isLegal(void);
}

#endif