#include "pawn.h"
using namespace std;

Pawn::Pawn(Colour colour, PieceType pt) : Piece{colour, pt} {}

bool Pawn::isLegal(Move m, vector<vector<shared_ptr<Piece>>> &tiles) {
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
        if (!hasMoved) {
            if (m.end.getCol() - m.start.getCol() == 2) {
                return true;
            }
        } else if (m.end.getCol() - m.start.getCol() == 1) {
            if ((m.end.getRow() - m.start.getRow() == 0) &&
                (tiles[m.end.getCol()][m.end.getRow()] != nullptr)) {
                return true;
            } else if (m.end.getRow() - m.start.getRow() == 1) {
                // check for capturable piece
                shared_ptr<Piece> front = tiles[m.end.getCol()][m.end.getRow() + 1];
                if ((front != nullptr) && (front->colour != colour)) {
                    return true;
                }
                // check for en_passanable piece
                shared_ptr<Piece> left = tiles[m.end.getCol() - 1][m.end.getRow()];
                shared_ptr<Piece> right = tiles[m.end.getCol() + 1][m.end.getRow()];
                if ((left->pt == 'P' && left->is_en_passanable) ||
                    (right->pt == 'P' && right->is_en_passanable)) {
                    return true;
                }
            }
        }
    } else {
        if (!hasMoved) {
            if (m.start.getCol() - m.end.getCol() == 2) {
                return true;
            }
        } else if (m.start.getCol() - m.end.getCol() == 1) {
            if ((m.start.getRow() - m.end.getRow() == 0) &&
                (tiles[m.end.getCol()][m.end.getRow()] != nullptr)) {
                return true;
            } else if (m.start.getRow() - m.end.getRow() == 1) {
                // check for capturable piece
                shared_ptr<Piece> front = tiles[m.end.getCol()][m.end.getRow() - 1];
                if ((front != nullptr) && (front->colour != colour)) {
                    return true;
                }
                // check for en_passanable piece
                shared_ptr<Piece> left = tiles[m.end.getCol() - 1][m.end.getRow()];
                shared_ptr<Piece> right = tiles[m.end.getCol() + 1][m.end.getRow()];
                if ((left->pt == 'P' && left->is_en_passanable) ||
                    (right->pt == 'P' && right->is_en_passanable)) {
                    return true;
                }
            }
        }

    }
    return false;
}