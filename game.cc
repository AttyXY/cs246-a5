#include "game.h"
using namespace std;


void Game::getPlayers(void) {
    bool validP1 = false;
    bool validP2 = false;
    string player1;
    string player2;

    while (!validP1) {
        cin >> player1;
        if (player1 == "computer") {
            // p1 = make_shared<Computer>(Colour::White);
            validP1 = true;
        } else if (player1 == "human") {
            p1 = make_shared<Human>(Colour::White);
            validP1 = true;
        } else {
           cout << "Invalid player type." << endl;
        }
    }
    while (!validP2) {
        cin >> player2;
        if (player2 == "computer") {
            // p2 = make_shared<Computer>(Colour::Black);
            validP2 = true;
        } else if (player2 == "human") {
            p2 = make_shared<Human>(Colour::Black);
            validP2 = true;
        } else {
            cout << "Invalid player type." << endl;
        }
    }
    p1->attach(b.get());
    p2->attach(b.get());
}

void Game::runGame(void) {
    getPlayers();

    cout << "STARTING GAME!" << endl << endl;
    td->printTiles();
    string command;
    while (cin >> command) {
        if (command == "move") {
            Coord start;
            Coord end;
            Move m;
            // TODO: Pawn promotion
            // char promotedPiece;
            if (IsValidInput(start) && IsValidInput(end)) {
                m.start = start; m.end = end;
            }

            // Move + output outcome
            if (isWhiteTurn) {
                p1->move(m);
            } else {
                p2->move(m);
            }

            if (b->whiteInCheck) {
                cout << "White is in check." << endl;
                if (b->checkmated) {
                    cout << "Checkmate! Black wins!" << endl;
                }
            } else if (b->blackInCheck) {
                cout << "Black is in check." << endl;
                if (b->checkmated) {
                    cout << "Checkmate! White wins!" << endl;
                }
            } else if (b->stalemated) {
                cout << "Stalemate!" << endl;
            } else if (!b->legalLastMove) {
                cout << "Invalid move. Input another move." << endl;
            }
        }
        else if (command == "resign") {
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
    }
}
