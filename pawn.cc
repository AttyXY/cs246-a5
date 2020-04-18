#include "pawn.h"
#include "enums.h"
using namespace std;

Pawn::Pawn(Colour colour, PieceType pt) : Piece{colour, pt} {}

bool Pawn::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    if (colour == Colour::White) {
        // Moving forward move
        if (m.end.getCol() == m.start.getCol()) {
            if (m.end.getRow() - m.start.getRow() == 1) {
                return true;
            }
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (m.end.getRow() - m.start.getRow() == 2) {
                    // Check if there is any piece is between start and end
                    if (tiles[m.start.getRow() + 1][m.start.getCol()] == nullptr) {
                        return true;
                    }
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (m.end.getRow() - m.start.getRow() == 1) {
                if (abs(m.end.getCol() - m.start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[m.end.getRow()][m.end.getCol()] != nullptr) &&
                        (tiles[m.end.getRow()][m.end.getCol()]->colour == Colour::Black)) {
                            return true;
                        }
                }
            }
        }
    } else if (colour == Colour::Black) {
        if (m.end.getCol() == m.start.getCol()) {
            if (m.start.getRow() - m.end.getRow() == 1) {
                return true;
            }
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (m.start.getRow() - m.end.getRow() == 2) {
                    // Check if there is any piece is between start and end
                    if (tiles[m.start.getRow() - 1][m.start.getCol()] == nullptr) {
                        return true;
                    }
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (m.end.getRow() - m.start.getRow() == -1) {
                if (abs(m.end.getCol() - m.start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[m.end.getRow()][m.end.getCol()] != nullptr) &&
                        (tiles[m.end.getRow()][m.end.getCol()]->colour == Colour::White)) {
                            return true;
                        }
                }
            }
        }
    }
    return false;
}