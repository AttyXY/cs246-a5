#include "pawn.h"
#include "enums.h"
using namespace std;

Pawn::Pawn(Colour colour, PieceType pt, Coord pos) : Piece{colour, pt, pos} {}

bool Pawn::isLegalMove(const Coord start, const Coord end,
                        const vector<vector<shared_ptr<Piece>>> &tiles) {
    if (isBasicInvalidMove(start, end, tiles)) { return false; }

    if (colour == Colour::White) {
        // Move forward by 2
        if ((end.getRow() - start.getRow() == 2) &&
            (end.getCol() == start.getCol()) && !hasMoved) {
            // Check for no pieces in front
            if (tiles[start.getRow() + 1][start.getCol()]->pt == PieceType::X &&
                tiles[start.getRow() + 2][start.getCol()]->pt == PieceType::X) {
                isEnPassanable = true;
                return true;
            }
        }
        // Move forward by 1
        else if (end.getRow() - start.getRow() == 1) {
            if (end.getCol() == start.getCol()) {
                // Check for no pieces in end
                if (tiles[end.getRow()][end.getCol()]->pt == PieceType::X) {
                    return true;
                }
            } else if (abs(end.getCol() - start.getCol()) == 1) {
                // Check if there is some piece at the end
                if (tiles[end.getRow()][end.getCol()]->pt != PieceType::X) {
                    return true;
                }
            }
        }
    } else if (colour == Colour::Black) {
        // Move forward by 2
        if ((end.getRow() - start.getRow() == -2) &&
            (end.getCol() == start.getCol()) && !hasMoved) {
            // Check for no pieces in front
            if (tiles[start.getRow() - 1][start.getCol()]->pt == PieceType::X &&
                tiles[start.getRow() - 2][start.getCol()]->pt == PieceType::X) {
                isEnPassanable = true;
                return true;
            }
        }
        // Move forward by 1
        else if (end.getRow() - start.getRow() == -1) {
            if (end.getCol() == start.getCol()) {
                // Check for no pieces in front
                if (tiles[end.getRow()][end.getCol()]->pt == PieceType::X) {
                    return true;
                }
            } else if (abs(end.getCol() - start.getCol()) == 1) {
                // Check if there is some piece at the end
                if (tiles[end.getRow()][end.getCol()]->pt != PieceType::X) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Pawn::getLineOfCheck(const Coord king, vector<Coord> &lineOfCheck) {
    return; // pawn has no line of check
}

bool Pawn::isStuck(vector<vector<shared_ptr<Piece>>> &tiles) {
    Coord top{pos.getRow() + 1, pos.getCol()};
    Coord topRight{pos.getRow() + 1, pos.getCol() + 1};
    Coord topLeft{pos.getRow() + 1, pos.getCol() - 1};

    if (isLegalMove(pos, top, tiles)) {
        return false;
    } else if (isLegalMove(pos, topRight, tiles)) {
        return false;
    } else if (isLegalMove(pos, topLeft, tiles)) {
        return false;
    }
    return true;
}