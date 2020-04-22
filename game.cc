#include "game.h"
using namespace std;


void Game::getPlayers(void) {
    bool validP1 = false;
    bool validP2 = false;

    string player;
    while (!validP1 || !validP2) {
        cin >> player;
        if (player == "human") {
            p1 = make_shared<Human>(Colour::White);
            validP1 = true;
        } else {
            int level = (int)player.back() - '0';
            player.pop_back();
            if (player == "computer") {
                if (level == 1 || level == 2 || level == 3) {
                    p1 = make_shared<Computer>(level, Colour::White);
                    validP1 = true;
                }
            }
        }
        if (!validP1) {
            cout << "Invalid player type." << endl;
            continue;
        }

        cin >> player;
        if (player == "human") {
            p2 = make_shared<Human>(Colour::Black);
            validP2 = true;
        } else {
            int level = (int)player.back() - '0';
            player.pop_back();
            if (player == "computer") {
                if (level == 1 || level == 2 || level == 3) {
                    p2 = make_shared<Computer>(level, Colour::Black);
                    validP2 = true;
                }
            }
        }
        if (!validP2) {
            validP1 = false;
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

    // make sure board is not already in stalemate before making first move
    if (isWhiteTurn) {
        b->stalemated = b->isStalemate(Colour::Black);
    } else {
        b->stalemated = b->isStalemate(Colour::White);
    }
    if (b->stalemated) {
        p1->score = p1->score + 0.5;
        p2->score = p2->score + 0.5;
        cout << "Stalemate!" << endl;
        return;
    }

    // Parse commands
    string line;
    while (getline(cin, line)) {
        istringstream ss{line};
        string command;
        ss >> command;
        if (command == "quit") {
            return;
        }
        else if (command == "move") {
            // Get move
            Move m;
            Coord start;
            Coord end;
            char promoteTo;
            try {
                ss >> start;
                ss >> end;
                m.start = start; m.end = end;
                if (ss >> promoteTo) {
                    charToPiece.at(toupper(promoteTo)); // validate piece
                    if (toupper(promoteTo) == 'X' ||
                        toupper(promoteTo) == 'P' ||
                        toupper(promoteTo) == 'K') {
                        throw out_of_range("");
                    } else {
                        if (isWhiteTurn) {
                            m.promoteTo = toupper(promoteTo);
                        } else {
                            m.promoteTo = tolower(promoteTo);
                        }
                    }
                }
            } catch (const std::invalid_argument &e) {
                cerr << e.what() << endl;
                continue;
            } catch (const out_of_range &e) {
                cout << "Invalid pawn promotion type." << endl;
                continue;
            }

            // Make move
            if (isWhiteTurn) {
                p1->move(m);
            } else {
                p2->move(m);
            }

            // Output board state
            if (b->whiteInCheck) {
                cout << "White is in check." << endl;
                if (b->checkmated) {
                    ++p2->score;
                    cout << "Checkmate! Black wins!" << endl;
                    return;
                }
            } else if (b->blackInCheck) {
                cout << "Black is in check." << endl;
                if (b->checkmated) {
                    ++p1->score;
                    cout << "Checkmate! White wins!" << endl;
                    return;
                }
            } else if (b->stalemated) {
                p1->score = p1->score + 0.5;
                p2->score = p2->score + 0.5;
                cout << "Stalemate!" << endl;
                return;
            }

            // Prompt to reenter move if last one was invalid
            if (!b->legalLastMove) {
                cout << "Invalid move. Input another move." << endl;
            } else {
                isWhiteTurn = !isWhiteTurn;
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
            return;
        }
    }
}
