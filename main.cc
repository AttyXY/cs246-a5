#include "coord.h"
#include "enums.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
#include "board.h"
#include "player.h"
#include "human.h"
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
	vector<char> row(8, '-');
	vector<vector<char>> setupTiles(8, row);
	bool whiteTurn = true;
    shared_ptr<Player> p1;
    shared_ptr<Player> p2;


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
					shared_ptr<Board> b = make_shared<Board>(setupTiles);
				} else {
					// TODO: Invalid command error
				}
            /*

		} else if (command == "game") {
            cout << "STARTING GAME!" << endl;

			cin >> command;
			if (command == "human") {
                p1 = make_shared<Human>(Colour::White);
                p2 = make_shared<Human>(Colour::Black);
                setupDefaultTiles(setupTiles);
                b->init(setupTiles);
                p1->attach(b.get());
                p2->attach(b.get());
                Move m;
                p1->move(m);
            } else if (command == "move") {
                Coord start;
                Coord end;
                cin >> start;
                cin >> end;
                Move m{start, end};
                if (isWhiteTurn) {
                    p1->move(m);
                } else {
                    p2->move(m);
                }
                if (b->whiteInCheck) {
                    cout << "White is in check." << endl;
                    if (b->isCheckmate) {
                        cout << "Checkmate! Black wins!" << endl;
                    }
                } else if (b->blackInCheck) {
                    cout << "Black is in check." << endl;
                    if (b->isCheckmate) {
                        cout << "Checkmate! White wins!" << endl;
                    }
                } else if (b->isStalemate) {
                    cout << "Stalemate!" << endl;
                } else if (!b->lastMoveValid) {
                    cout << "Invalid move. Input another move." << endl;
                }

                // todo
            } else if (command = "resign") {
                if (isWhiteTurn) {
                    ++p2->score;
                    cout << "Black wins!" << endl;
                } else {
                    ++p1->score;
                    cout << "White wins!" << endl;
                }
                // print score
                cout << "Final Score:" << endl;
                cout << "White: " << p1->score << endl;
                cout << "Black: " << p2->score << endl;
            }
        } else if (command == "computer") {
            // todo
        }
        // quit peacefully?
		*/
        }
    }
}