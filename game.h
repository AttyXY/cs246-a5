#ifndef GAME_H
#define GAME_H
#include <memory>
#include <sstream>
#include <cctype>
#include "textDisplay.h"
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "graphDisplay.h"

// Wrapper class for game logic
class Game {
    public:
        std::unique_ptr<TextDisplay> td = std::make_unique<TextDisplay> ();
        std::unique_ptr<GraphDisplay> gd = std::make_unique<GraphDisplay>();
        std::unique_ptr<Board> b = std::make_unique<Board>();
        std::unique_ptr<Player> p1 = nullptr;
        std::unique_ptr<Player> p2 = nullptr;

        void getPlayers();
        void runGame();

        bool ongoingGame = false;
        bool customSetup = false;
        bool isWhiteTurn = true;
};

#endif
