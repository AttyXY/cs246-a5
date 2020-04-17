#include "textDisplay.h"
#include "coord.h"
#include "state.h"

TextDisplay::TextDisplay() {}

void TextDisplay::update(Subject<State> &whoFrom)
{
    State s = whoFrom.getState();
    Move m = whoFrom.getState().m;
    Coord start = whoFrom.getState().m.start;
    Coord end = whoFrom.getState().m.end;
    char oldPiece = tiles[start.getCol()][start.getRow()];

    switch (s.moveType)
    {
    case MoveType::Normal:
    {
        tiles[end.getCol()][end.getRow()] = oldPiece;
        if ((start.getCol() % 2 == 0 && start.getRow() % 2 == 0) ||
            (start.getCol() % 2 != 0 && start.getRow() % 2 != 0))
        {
            tiles[start.getCol()][start.getRow()] = '-';
        }
        else
        {
            tiles[start.getCol()][start.getRow()] = ' ';
        }
        break;
    }
    // case MoveType::PawnPromotion:
    // {
    //     char pawnPromotion = s.promotion;
    //     if ((start.getCol() % 2 == 0 && start.getRow() % 2 == 0) ||
    //         (start.getCol() % 2 != 0 && start.getRow() % 2 != 0))
    //     {
    //         tiles[start.getCol()][start.getRow()] = '-';
    //     }
    //     else
    //     {
    //         tiles[start.getCol()][start.getRow()] = ' ';
    //     }
    //     if (pawnPromotion == 'Q' || pawnPromotion == 'q')
    //     {
    //         tiles[end.getCol()][end.getRow()] = {isupper(oldPiece) ? 'Q' : 'q'};
    //     }
    //     else if (pawnPromotion == 'B' || pawnPromotion == 'b')
    //     {
    //         tiles[end.getCol()][end.getRow()] = {isupper(oldPiece) ? 'B' : 'b'};
    //     }
    //     else if (pawnPromotion == 'R' || pawnPromotion == 'r')
    //     {
    //         tiles[end.getCol()][end.getRow()] = {isupper(oldPiece) ? 'R' : 'r'};
    //     }
    //     else if (pawnPromotion == 'N' || pawnPromotion == 'n')
    //     {
    //         tiles[end.getCol()][end.getRow()] = {isupper(oldPiece) ? 'N' : 'n'};
    //     }
    //     break;
    // }
    // case MoveType::Castle:
    // {
    //     char rook;
    //     if (end.getCol() == 2)
    //     {
    //         rook = tiles[0][end.getRow()];
    //         tiles[4][end.getRow()] = {end.getRow() ? ' ' : '-'};
    //         tiles[2][end.getRow()] = oldPiece;
    //         tiles[0][end.getRow()] = {end.getRow() ? ' ' : '-'};
    //         tiles[3][end.getRow()] = rook;
    //     }
    //     else if (end.getCol() == 6)
    //     {
    //         rook = tiles[7][end.getRow()];
    //         tiles[4][end.getRow()] = {end.getRow() ? ' ' : '-'};
    //         tiles[6][end.getRow()] = oldPiece;
    //         tiles[7][end.getRow()] = {end.getRow() ? '-' : ' '};
    //         tiles[5][end.getRow()] = rook;
    //     }
    //     break;
    // }
    // case MoveType::EnPassant:
    //     break;
    // }
    printTile();
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