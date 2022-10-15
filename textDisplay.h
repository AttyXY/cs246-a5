#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include "display.h"
#include "subject.h"
#include "state.h"
#include "coord.h"
#include "utils.h"

class TextDisplay: public BoardDisplay {
    void reset() override;
    std::vector<std::vector<char>> previousSetup;
    bool previousIsWhiteTurn;

    public:
        TextDisplay();
        bool setupTiles(bool &isWhiteTurn, bool custom = false);
        bool isValidSetup();
        void printTiles();
        void loadPreviousSetup(bool &isWhiteTurn);

        void update(Subject<State> &whoFrom); // This updates the textDisplay with the grid it receives
};

#endif
