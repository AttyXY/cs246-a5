#ifndef KING_H
#define KING_H
#include "piece.h"

class King: public Piece {
    public:
        bool isLegal(void);
}

#endif