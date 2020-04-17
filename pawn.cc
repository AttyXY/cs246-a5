#include "pawn.h"
using namespace std;

Pawn::Pawn(Colour colour, PieceType pt) : Piece{colour, pt} {}

bool Pawn::isLegalMove(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
    // check if the end is out of the grid
    if (m.end.getRow() < 0 || m.end.getRow() > 7 || m.end.getCol() < 0 || m.end.getCol() > 7) {
        return false;
    }

    // check if the end if occupied by own colour
    if ((tiles[m.start.getCol()][m.start.getRow()]->colour == tiles[m.end.getCol()][m.end.getRow()]->colour)
        && tiles[m.end.getCol()][m.end.getRow()] != nullptr) {
        return false;
    }

    // check if move is valid
    if (colour == Colour::White) {
        // Moving forward move
        if (m.end.getCol() == m.start.getCol()) {
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (m.end.getRow() - m.start.getRow() == 2) {
                    // Check if there is any piece is between start and end
                    if (tiles[m.start.getCol()][m.start.getRow() + 1] == nullptr) {
                        return true;
                    }
                }
            }
            // Check if it can move forward by 1
            if (m.end.getRow() - m.start.getRow() == 1) {
                // Check if there is any piece at the end tile
                if (tiles[m.start.getCol()][m.end.getRow()] == nullptr) {
                    return true;
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (m.end.getRow() - m.start.getRow() == 1) {
                if (abs(m.end.getCol() - m.start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[m.end.getCol()][m.end.getRow()] != nullptr) &&
                        (tiles[m.end.getCol()][m.end.getRow()]->colour == Colour::Black)) {
                            return true;
                        }
                }
            }
        }
    } else if (colour == Colour::Black) {
        if (m.end.getCol() == m.start.getCol()) {
            // Check if it can move forward by 2
            if (!hasMoved) {
                if (m.end.getRow() - m.start.getRow() == -2) {
                    // Check if there is any piece is between start and end
                    if (tiles[m.start.getCol()][m.start.getRow() - 1] == nullptr) {
                        return true;
                    }
                }
            }
            // Check if it can move forward by 1
            if (m.end.getRow() - m.start.getRow() == -1) {
                // Check if there is any piece at the end tile
                if (tiles[m.start.getCol()][m.end.getRow()] == nullptr) {
                    return true;
                }
            }
        } else {
            // Check if it moves diagonally up by 1
            if (m.end.getRow() - m.start.getRow() == -1) {
                if (abs(m.end.getCol() - m.start.getCol()) == 1) {
                    // Check if there is some black piece at the end
                    if ((tiles[m.end.getCol()][m.end.getRow()] != nullptr) &&
                        (tiles[m.end.getCol()][m.end.getRow()]->colour == Colour::White)) {
                            return true;
                        }
                }
            }
        }
    }
    return false;
}