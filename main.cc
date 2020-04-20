#include <iostream>
#include <string>
#include "game.h"
#include "enums.h"
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
                g->b->init(g->td->tiles); // default setup is always valid
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
            if (g->td->setupTiles(g->isWhiteTurn, true) &&
                g->b->init(g->td->tiles)) {
                g->customSetup = true;
                // TODO: set stalemate flag before first move
                // if (g->isWhiteTurn) {
                //     g->b->checkEndGame(Colour::White);
                // } else {
                //     g->b->checkEndGame(Colour::Black);
                // }
            } else {
                cout << "Invalid setup." << endl << endl;
            }
        }
    }
    cout << "THANKS FOR PLAYING CHESS!" << endl;

}