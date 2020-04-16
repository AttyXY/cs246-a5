#include "textDisplay.h"
#include "coord.h"
#include "state.h"

TextDisplay::TextDisplay() {}

void TextDisplay::update(Subject<State> &whoFrom) {
    /*
    State s = whoFrom.getState();
    MoveState m = whoFrom.getState().move;
    switch (s.type)
    {
    // case StateType::PlayerMove:
    //     break;
    // case StateType::NoType:
    //     break;
    case StateType::NewTile:
        tiles = m.tiles
        printTile();
        break;
    case StateType::UpdatingBoard:
        Coord oldLoc = m.oldLoc;
        Coord newLoc = m.newLoc;
        char oldPiece = tiles[oldLoc.getCol()][oldLoc.getRow()];
        switch (m.moveType)
        {
        case MoveType::Normal:
        {
            tiles[newLoc.getCol()][newLoc.getRow()] = oldPiece;
            if ((oldLoc.getCol() % 2 == 0 && oldLoc.getRow() % 2 == 0) ||
                (oldLoc.getCol() % 2 != 0 && oldLoc.getRow() % 2 != 0))
            {
                tiles[oldLoc.getCol()][oldLoc.getRow()] = '-';
            }
            else
            {
                tiles[oldLoc.getCol()][oldLoc.getRow()] = ' ';
            }
            break;
        }
        case MoveType::PawnPromotion:
        {
            char pawnPromotion = m.pawnPromotion;
            if ((oldLoc.getCol() % 2 == 0 && oldLoc.getRow() % 2 == 0) ||
                (oldLoc.getCol() % 2 != 0 && oldLoc.getRow() % 2 != 0))
            {
                tiles[oldLoc.getCol()][oldLoc.getRow()] = '-';
            }
            else
            {
                tiles[oldLoc.getCol()][oldLoc.getRow()] = ' ';
            }
            if (pawnPromotion == 'Q' || pawnPromotion == 'q')
            {
                tiles[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'Q' : 'q'};
            }
            else if (pawnPromotion == 'B' || pawnPromotion == 'b')
            {
                tiles[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'B' : 'b'};
            }
            else if (pawnPromotion == 'R' || pawnPromotion == 'r')
            {
                tiles[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'R' : 'r'};
            }
            else if (pawnPromotion == 'N' || pawnPromotion == 'n')
            {
                tiles[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'N' : 'n'};
            }
            break;
        }
        case MoveType::Castle:
        {
            char rook;
            if (newLoc.getCol() == 2)
            {
                rook = tiles[0][newLoc.getRow()];
                tiles[4][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tiles[2][newLoc.getRow()] = oldPiece;
                tiles[0][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tiles[3][newLoc.getRow()] = rook;
            }
            else if (newLoc.getCol() == 6)
            {
                rook = tiles[7][newLoc.getRow()];
                tiles[4][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tiles[6][newLoc.getRow()] = oldPiece;
                tiles[7][newLoc.getRow()] = {newLoc.getRow() ? '-' : ' '};
                tiles[5][newLoc.getRow()] = rook;
            }
            break;
        }
        case MoveType::Enpassant:
            break;
        }
        printTile();
        break;
    }
    */
}

void TextDisplay::printTile()
{
    for (int row = 0; row < 8; row++)
    {
        std::cout << 8 - row << "  ";
        for (int col = 0; row < 8; col++)
        {
            std::cout << tiles[col][7 - row];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "   abcdefgh" << std::endl;
}