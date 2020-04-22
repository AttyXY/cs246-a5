#include <string>
#include "game.h"
#include "enums.h"
using namespace std;


int main(int argc, char *argv[]) {
	// TODO: PARSE FLAGS
    unique_ptr<Game> g = make_unique<Game>();

    cout << "WELCOME TO CHESS! " << endl;
    cout << "PLEASE ENTER ONE OF THE FOLLOWING COMMANDS TO BEGIN:" << endl;
    cout << "- setup" << endl;
    cout << "- game [player1] [player2]" << endl;
    cout << "- quit (to exit)" << endl;
    cout << endl;

    string command;
    while (cin >> command) {
        if (command == "quit") {
            break;
        }
        else if (command != "game" && command != "setup") {
            cout << "Invalid command." << endl;
        }
        else if (command == "game") {
            if (!g->ongoingGame) {
                // Initialize default setup if setup wasn't called
                if (!g->customSetup) {
                    g->td->setupTiles(g->isWhiteTurn, false);
                    g->gd->updateTiles(g->td->tiles);
                    g->b->init(g->td->tiles);
                }
                g->b->attach(g->td.get());
                g->b->attach(g->gd.get());

                // sets ongoingGame to true first time called
                g->getPlayers();
            } else {
                g->td->loadPreviousSetup(g->isWhiteTurn);
                g->gd->updateTiles(g->td->tiles);
                g->b->init(g->td->tiles);
                cout << "Starting new game with previous "
                     << "setup and players." << endl;
            }
            g->runGame();

            cout << endl;
            cout << "PLEASE ENTER ONE OF THE FOLLOWING COMMANDS TO CONTINUE:" << endl;
            cout << "- setup (to create new setup)" << endl;
            cout << "- game (to continue with previous setup)" << endl;
            cout << "- quit (to exit)" << endl;
            cout << endl;
        }
        else if (command == "setup") {
            if (g->td->setupTiles(g->isWhiteTurn, true) &&
                g->b->init(g->td->tiles)) {
                g->gd->updateTiles(g->td->tiles);
                g->customSetup = true;
            } else {
                cout << "Invalid setup." << endl << endl;
            }

            if (!g->ongoingGame) {
                cout << "PLEASE ENTER THE FOLLOWING COMMANDS TO BEGIN:" << endl;
                cout << "- game [player1] [player2]" << endl;
                cout << endl;
            } else {
                cout << "PLEASE ENTER THE FOLLOWING COMMANDS TO BEGIN:" << endl;
                cout << "- game (to continue with previous setup)" << endl;
                cout << endl;
            }
        }
    }

    cout << "THANKS FOR PLAYING CHESS!" << endl;
    cout << "Final Score:" << endl;
    if (g->p1 != nullptr && g->p2 != nullptr) {
        cout << "White: " << g->p1->score << endl;
        cout << "Black: " << g->p2->score << endl;
    }
}