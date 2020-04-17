#include <iostream>
#include <vector>
#include "coord.h"
using namespace std;

int main() {
    vector<char> row(8, '-');
	tiles = vector<vector<char>>(8, row);
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (col == 0) {
                if (row == 0 || row == 7) {
                    tiles[col][row] = 'R';
                } else if (row == 1 || row == 6) {
                    tiles[col][row] = 'N';
                } else if (row == 2 || row == 5) {
                    tiles[col][row] = 'B';
                }  else if (row == 3) {
                    tiles[col][row] = 'Q';
                } else if (row == 4) {
                    tiles[col][row] = 'K';
                }
            } else if (col == 7) {
                if (row == 0 || row == 7) {
                    tiles[col][row] = 'r';
                } else if (row == 1 || row == 6) {
                    tiles[col][row] = 'n';
                } else if (row == 2 || row == 5) {
                    tiles[col][row] = 'b';
                }  else if (row == 3) {
                    tiles[col][row] = 'q';
                } else if (row == 4) {
                    tiles[col][row] = 'k';
                }
            } else if (col == 1) {
                tiles[col][row] = 'P';
            } else if (col == 6) {
                tiles[col][row] = 'p';
            } else {
                tiles[col][row] = '-';
            }
        }
    }

    Coord c;
    cin >> c;
    cout << c.col << c.row << endl;
    cout << c << endl;
}

