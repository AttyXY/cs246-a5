#include "textDisplay.h"
#include "coord.h"
#include "state.h"

TextDisplay::TextDisplay() {}

void TextDisplay::notify(Subject<State> &whoFrom)
{
    State s = whoFrom.getState();
    Move m = whoFrom.getState().move;
    switch (s.type)
    {
    // case StateType::PlayerMove:
    //     break;
    // case StateType::NoType:
    //     break;
    case StateType::NewTile:
        tile = m.tile;
        printTile();
        break;
    case StateType::UpdatingBoard:
        Coord oldLoc = m.oldLoc;
        Coord newLoc = m.newLoc;
        char oldPiece = tile[oldLoc.getCol()][oldLoc.getRow()];
        switch (m.moveType)
        {
        case MoveType::Normal:
        {
            tile[newLoc.getCol()][newLoc.getRow()] = oldPiece;
            if ((oldLoc.getCol() % 2 == 0 && oldLoc.getRow() % 2 == 0) ||
                (oldLoc.getCol() % 2 != 0 && oldLoc.getRow() % 2 != 0))
            {
                tile[oldLoc.getCol()][oldLoc.getRow()] = '-';
            }
            else
            {
                tile[oldLoc.getCol()][oldLoc.getRow()] = ' ';
            }
            break;
        }
        case MoveType::PawnPromotion:
        {
            char pawnPromotion = m.pawnPromotion;
            if ((oldLoc.getCol() % 2 == 0 && oldLoc.getRow() % 2 == 0) ||
                (oldLoc.getCol() % 2 != 0 && oldLoc.getRow() % 2 != 0))
            {
                tile[oldLoc.getCol()][oldLoc.getRow()] = '-';
            }
            else
            {
                tile[oldLoc.getCol()][oldLoc.getRow()] = ' ';
            }
            if (pawnPromotion == 'Q' || pawnPromotion == 'q')
            {
                tile[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'Q' : 'q'};
            }
            else if (pawnPromotion == 'B' || pawnPromotion == 'b')
            {
                tile[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'B' : 'b'};
            }
            else if (pawnPromotion == 'R' || pawnPromotion == 'r')
            {
                tile[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'R' : 'r'};
            }
            else if (pawnPromotion == 'N' || pawnPromotion == 'n')
            {
                tile[newLoc.getCol()][newLoc.getRow()] = {isupper(oldPiece) ? 'N' : 'n'};
            }
            break;
        }
        case MoveType::Castle:
        {
            char rook;
            if (newLoc.getCol() == 2)
            {
                rook = tile[0][newLoc.getRow()];
                tile[4][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tile[2][newLoc.getRow()] = oldPiece;
                tile[0][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tile[3][newLoc.getRow()] = rook;
            }
            else if (newLoc.getCol() == 6)
            {
                rook = tile[7][newLoc.getRow()];
                tile[4][newLoc.getRow()] = {newLoc.getRow() ? ' ' : '-'};
                tile[6][newLoc.getRow()] = oldPiece;
                tile[7][newLoc.getRow()] = {newLoc.getRow() ? '-' : ' '};
                tile[5][newLoc.getRow()] = rook;
            }
            break;
        }
        case MoveType::Enpassant:
            break;
        }
        printTile();
        break;
    }
}

void TextDisplay::printTile()
{
    for (int row = 0; row < 8; row++)
    {
        std::cout << 8 - row << "  ";
        for (int col = 0; row < 8; col++)
        {
            std::cout << tile[col][7 - row];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "   abcdefgh" << std::endl;
}