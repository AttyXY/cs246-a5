#include "textDisplay.h"
using namespace std;


TextDisplay::TextDisplay() {
    reset();
}

void TextDisplay::reset() {
    vector<char> row(8, '-');
	tiles = vector<vector<char>>(8, row);
}

void TextDisplay::printTiles() {
    for (int row = 8; row > 0; --row) { // print rows in reverse
		cout << row << "  ";
		for (int col = 0; col < 8; ++col) {
			cout << tiles[row - 1][col];
		}
		cout << endl;
	}
	cout << "   abcdefgh" << endl << endl;
}

bool TextDisplay::setupTiles(bool &isWhiteTurn, bool custom) {
    reset(); // start with clear, fully initialized vector
    if (!custom) {
        for (int col = 0; col < 8; ++col) {
            for (int row = 0; row < 8; ++row) {
                if (row == 0) {
                    if (col == 0 || col == 7) {
                        tiles[row][col] = 'R';
                    } else if (col == 1 || col == 6) {
                        tiles[row][col] = 'N';
                    } else if (col == 2 || col == 5) {
                        tiles[row][col] = 'B';
                    }  else if (col == 3) {
                        tiles[row][col] = 'Q';
                    } else if (col == 4) {
                        tiles[row][col] = 'K';
                    }
                } else if (row == 7) {
                    if (col == 0 || col == 7) {
                        tiles[row][col] = 'r';
                    } else if (col == 1 || col == 6) {
                        tiles[row][col] = 'n';
                    } else if (col == 2 || col == 5) {
                        tiles[row][col] = 'b';
                    }  else if (col == 3) {
                        tiles[row][col] = 'q';
                    } else if (col == 4) {
                        tiles[row][col] = 'k';
                    }
                } else if (row == 1) {
                    tiles[row][col] = 'P';
                } else if (row == 6) {
                    tiles[row][col] = 'p';
                } else {
                    tiles[row][col] = '-';
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
                if (!isValidSetup()) {
                    return false;
                }
                return true;
            } else {
                cout << "Invalid command." << endl;
                // throw invalid_argument("Invalid command.");
            }
        }
    }
    return true;
}

bool TextDisplay::isValidSetup() {
    int numWhiteKings = 0;
    int numBlackKings = 0;
    bool noPawnsLastRows = true;

    for (int col = 0; col < 8; ++col) {
        for (int row = 0; row < 8; ++row) {
            if (tiles[row][col] == 'k') {
                ++numBlackKings;
            } else if (tiles[row][col] == 'K') {
                ++numWhiteKings;
            } else if (row == 0 || row == 7) {
                if (toupper(tiles[row][col]) == 'P') {
                    noPawnsLastRows = false;
                }
            }
        }
    }
    return (numWhiteKings == 1 && numBlackKings == 1  && noPawnsLastRows);
}

void TextDisplay::update(Subject<State> &whoFrom) {
    State s = whoFrom.getState();

    tiles = s.tiles;
    printTiles();
}
