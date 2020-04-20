#include "pawn.h"
#include "enums.h"
using namespace std;

Pawn::Pawn(Colour colour, PieceType pt, Coord pos) : Piece{colour, pt, pos} {}

bool Pawn::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    if (colour == Colour::White) {
        // Moving forward move
        if (end.getCol() == start.getCol()) {
            if (end.getRow() - start.getRow() == 1) {
                return true;
            }
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (end.getRow() - start.getRow() == 2) {
                    // Check if there is any piece is between start and end
                    if (tiles[start.getRow() + 1][start.getCol()] == nullptr) {
                        return true;
                    }
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (end.getRow() - start.getRow() == 1) {
                if (abs(end.getCol() - start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[end.getRow()][end.getCol()] != nullptr) &&
                        (tiles[end.getRow()][end.getCol()]->colour == Colour::Black)) {
                            return true;
                        }
                }
            }
        }
    } else if (colour == Colour::Black) {
        if (end.getCol() == start.getCol()) {
            if (start.getRow() - end.getRow() == 1) {
                return true;
            }
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (start.getRow() - end.getRow() == 2) {
                    // Check if there is any piece is between start and end
                    if (tiles[start.getRow() - 1][start.getCol()] == nullptr) {
                        return true;
                    }
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (end.getRow() - start.getRow() == -1) {
                if (abs(end.getCol() - start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[end.getRow()][end.getCol()] != nullptr) &&
                        (tiles[end.getRow()][end.getCol()]->colour == Colour::White)) {
                            return true;
                        }
                }
            }
        }
    }
    return false;
}