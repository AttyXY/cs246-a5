#include "coord.h"
#include "enums.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
#include "board.h"
//#include "game.h"
using namespace std;

void outputSetupTiles(std::vector<std::vector<char>> &tiles) {
	for (int row = 0; row < 8; ++row) {
		cout << 8 - row << "  "; // print rows in reverse
		for (int col = 0; col < 8; ++col) {
			cout << tiles[col][7 - row];
		}
		cout << endl;
	}
	cout << "   abcdefgh" << endl << endl;
}

void setupDefaultTiles(std::vector<std::vector<char>> &tiles) {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (row == 0) {
                if (col == 0 || col == 7) {
                    tiles[col][row] = 'R';
                } else if (col == 1 || col == 6) {
                    tiles[col][row] = 'N';
                } else if (col == 2 || col == 5) {
                    tiles[col][row] = 'B';
                }  else if (col == 3) {
                    tiles[col][row] = 'K';
                } else if (col == 4) {
                    tiles[col][row] = 'Q';
                }
            } else if (row == 7) {
                if (col == 0 || col == 7) {
                    tiles[col][row] = 'r';
                } else if (col == 1 || col == 6) {
                    tiles[col][row] = 'n';
                } else if (col == 2 || col == 5) {
                    tiles[col][row] = 'b';
                }  else if (col == 3) {
                    tiles[col][row] = 'k';
                } else if (col == 4) {
                    tiles[col][row] = 'q';
                }
            } else if (row == 1) {
                tiles[col][row] = 'P';
            } else if (row == 6) {
                tiles[col][row] = 'p';
            } else {
                tiles[col][row] = '-';
            }

        }
    }
}

int main(int argc, char *argv[]) {
	bool whiteTurn = true;
	vector<char> row(8, '-');
	vector<vector<char>> setupTiles(8, row);


	// TODO: Parse flags

	// Parse commands
    cout << "WELCOME TO CHESS!" << endl;
    cout << "PLEASE ENTER ONE OF THE FOLLOWING COMMANDS TO BEGIN:" << endl;
    cout << "- setup" << endl << endl;

	string command{""};
	while (cin >> command) {
		// Setup
		if (command == "setup") {
			cout << "STARTING SETUP" << endl;

			char piece;
			Coord location;
			string turn;
			while (cin >> command) {
				if (command == "+") {
					cin >> piece;
					cin >> location;
					setupTiles[location.row][location.col] = piece;
					outputSetupTiles(setupTiles);
				} else if (command == "-") {
					cin >> location;
					setupTiles[location.row][location.col] = '-';
					outputSetupTiles(setupTiles);
				} else if (command == "=") {
					cin >> turn;
					if (turn == "black") {
						whiteTurn = false;
					}
				} else if (command == "done") {
					// TODO: Check setup is valid
					Board b{setupTiles};
				} else {
					// TODO: Invalid command error
				}
			}
		/*
		} else if (command == "game") {
			cin >> command;
			if (command == "human") {
				Player p1 {}
				Player p2 {};
                setupDefaultTiles(setupTiles);
				Board b{setupTiles};
				Game g = new Game{p1, p2, board};


				} else if (command == "move") {
					// todo
				} else if (command = "resign") {
					// print score
					// quit gracefully?
				}
			} else if (command == "computer") {
				// todo
			}

		*/
		}
	}
}