#include "coord.h"
#include "enums.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
#include "board.h"
//#include "game.h"
using namespace std;

void outputSetupGrid(std::vector<std::vector<char>> &grid) {
	for (int row = 0; row < 8; row++) {
		cout << 8 - row << "  "; // print rows in reverse
		for (int col = 0; col < 8; col++) {
			cout << grid[col][7 - row];
		}
		cout << endl;
	}
	cout << "   abcdefgh" << endl << endl;
}

int main(int argc, char *argv[]) {
	bool whiteTurn = true;
	vector<char> row(8, '-');
	vector<vector<char>> setupGrid(8, row);


	// TODO: Parse flags

	// Parse commands
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
					setupGrid[location.row][location.col] = piece;
					outputSetupGrid(setupGrid);
				} else if (command == "-") {
					cin >> location;
					setupGrid[location.row][location.col] = '-';
					outputSetupGrid(setupGrid);
				} else if (command == "=") {
					cin >> turn;
					if (turn == "black") {
						whiteTurn = false;
					}
				} else if (command == "done") {
					// TODO: Check setup is valid
					Board b{setupGrid};
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
				Board board;
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