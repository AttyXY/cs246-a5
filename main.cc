#include <iostream>
#include <string>
#include "game.h"
using namespace std;


int main(int argc, char *argv[]) {
	// TODO: PARSE FLAGS

	// TODO: PARSE SETUP
    cout << "WELCOME TO CHESS! ";
    cout << "PLEASE ENTER ONE OF THE FOLLOWING COMMANDS TO BEGIN:" << endl;
    cout << "- setup" << endl;
    cout << "- game [player1] [player2]" << endl;
    cout << endl;

    unique_ptr<Game> g = make_unique<Game>();

    // SETUP BOARD
    string command;
    while (cin >> command) {
        if (command == "quit") {
            break;
        }
        else if (command != "game" && command != "setup") {
            cout << "Invalid command." << endl;
        }
        else if (command == "game") {
            if (!g->customSetup) {
                g->td->setupTiles(g->isWhiteTurn, false);
                g->b->init(g->td->tiles); // validity already checked
            }
            g->b->attach(g->td.get());
            // g->b->attach(g->gd);
            g->runGame();
            cout << "Final Score:" << endl;
            cout << "White: " << g->p1->score << endl;
            cout << "Black: " << g->p2->score << endl;
        }
        else if (command == "setup") {
            cout << "STARTING SETUP" << endl << endl;
            g->td->reset(); // Make sure td is clear
            if (g->td->setupTiles(g->isWhiteTurn, true) &&
                g->b->init(g->td->tiles)) {
                g->customSetup = true;
            } else {
                cout << "Invalid setup." << endl << endl;
            }
        }
    }
    cout << "THANKS FOR PLAYING CHESS!" << endl;

}