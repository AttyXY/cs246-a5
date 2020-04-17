#include "textDisplay.h"
using namespace std;


TextDisplay::TextDisplay() {
    vector<char> row(8, '-');
	tiles = vector<vector<char>>(8, row);
}

void TextDisplay::printTiles() {
    for (int row = 8; row > 0; --row) {
		cout << row << "  "; // print rows in reverse
		for (int col = 0; col < 8; ++col) {
			cout << tiles[row - 1][col];
		}
		cout << endl;
	}
	cout << "   abcdefgh" << endl << endl;
}




bool TextDisplay::setupTiles(bool &isWhiteTurn, bool custom) {
    if (!custom) {
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
    } else {
        string command;
        char piece;
        Coord coord;
        while (cin >> command) {
            if (command == "+") {
                if (isValidPiece(piece) && IsValidInput(coord)) {
                    tiles[coord.row][coord.col] = piece;
                    printTiles();
                }
            } else if (command == "-") {
                if (isValidPiece(piece) && IsValidInput(coord)) {
                    tiles[coord.row][coord.col] = '-';
                    printTiles();
                }
            } else if (command == "=") {
                string turn;
                cin >> turn;
                if (turn == "black") {
                    isWhiteTurn = false;
                } else if (turn == "white") {
                    isWhiteTurn = true;
                } else {
                    cout << "Invalid turn colour." << endl;
                }
            } else if (command == "done") {
                // TODO: Check setup is valid
                // if (!isValidSetup()) {
                //     return false;
                // }
                return true;
            } else {
                cout << "Invalid command." << endl;
                // throw invalid_argument("Invalid command.");
            }
        }
    }
    return true;
}

// bool TextDisplay::isValidSetup() {
    // bool oneWhiteKing = false;
    // bool oneBlackKing = false;
    // bool noPawnsLastRows = true;
    // bool kingInCheck = false;
// }

void TextDisplay::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();
    cout << s.m.start << endl;
    cout << s.m.end << endl;
}
