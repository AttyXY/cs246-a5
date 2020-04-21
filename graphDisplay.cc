#include "graphDisplay.h"

GraphDisplay::GraphDisplay(){ 
  char colIndex[] = "abcdefgh";
  for (int row = 0; row < 8; row++) {
    xw.drawString(25, 75 + 50 * row, std::to_string(8-row), Xwindow::Black);
    for (int col = 0; col < 8; col++) {
      xw.drawString(75 + 50 * col, 475, std::string(1,colIndex[col]), Xwindow::Black);
      if ((row + col) % 2 != 0) {
        xw.fillRectangle(50 + 50 * row,50 + 50 * col, 50, 50, Xwindow::Black);
      } else{
        xw.fillRectangle(50 + 50 * row,50 + 50 * col, 50, 50, Xwindow::White);
      }
    }
  }
}
bool GraphDisplay::setupTiles(bool &isWhiteTurn, bool custom){
    
    std::vector<char> row(8, '-');
	  tiles = std::vector<std::vector<char>>(8, row);
    if(!custom){
      for (int col = 0; col < 8; ++col) {
            for (int row = 0; row < 8; ++row) {
                if (row == 0) {
                    if (col == 0 || col == 7) {
                        tiles[row][col] = 'R';
                    } else if (col == 1 || col == 6) {
                        tiles[row][col] = 'N';
                    } else if (col == 2 || col == 5) {
                        tiles[row][col] = 'B';
                    }  else if (col == 3) {
                        tiles[row][col] = 'Q';
                    } else if (col == 4) {
                        tiles[row][col] = 'K';
                    }
                } else if (row == 7) {
                    if (col == 0 || col == 7) {
                        tiles[row][col] = 'r';
                    } else if (col == 1 || col == 6) {
                        tiles[row][col] = 'n';
                    } else if (col == 2 || col == 5) {
                        tiles[row][col] = 'b';
                    }  else if (col == 3) {
                        tiles[row][col] = 'q';
                    } else if (col == 4) {
                        tiles[row][col] = 'k';
                    }
                } else if (row == 1) {
                    tiles[row][col] = 'P';
                } else if (row == 6) {
                    tiles[row][col] = 'p';
                } else {
                    tiles[row][col] = '-';
                }
            }
        }
        updateTiles(tiles);
    }else{
      
      std::string command;
      char piece;
      Coord coord;
      while (std::cin >> command) {
            if (command == "+") {
                if (isValidPiece(piece) && IsValidInput(coord)) {
                    tiles[coord.row][coord.col] = piece;
                    updateTiles(tiles);
                    
                }
            } else if (command == "-") {
                if (isValidPiece(piece) && IsValidInput(coord)) {
                    tiles[coord.row][coord.col] = '-';
                    updateTiles(tiles);
                }
            } else if (command == "=") {
                std::string turn;
                std::cin >> turn;
                if (turn == "black") {
                    isWhiteTurn = false;
                } else if (turn == "white") {
                    isWhiteTurn = true;
                } else {
                    std::cout << "Invalid turn colour." << std::endl;
                }
            } else if (command == "done") {
                // TODO: Check setup is valid
                if (!isValidSetup()) {
                    return false;
                }
                return true;
            } else {
                std::cout << "Invalid command." << std::endl;
                // throw invalid_argument("Invalid command.");
            }
        }
    }
    return true;
}

bool GraphDisplay::isValidSetup() {
    int numWhiteKings = 0;
    int numBlackKings = 0;
    bool noPawnsLastRows = true;

    for (int col = 0; col < 8; ++col) {
        for (int row = 0; row < 8; ++row) {
            if (tiles[row][col] == 'k') {
                ++numBlackKings;
            } else if (tiles[row][col] == 'K') {
                ++numWhiteKings;
            } else if (row == 0 || row == 7) {
                if (toupper(tiles[row][col]) == 'P') {
                    noPawnsLastRows = false;
                }
            }
        }
    }
    return (numWhiteKings == 1 && numBlackKings == 1  && noPawnsLastRows);
}

void GraphDisplay::updateTiles(const std::vector<std::vector<char>> &setupTiles){
    tiles = setupTiles;
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            if(tiles[7 - x][7 - y] != '-'){
                xw.drawString(75 + 50 * (7 - y), 75 + 50 * x, std::string(1,tiles[7 - x][7 - y]), Xwindow::Red);
            }
        }
    }
}

// bool GraphDisplay::setupTiles(bool &isWhiteTurn, bool custom){
//     if(!custom){

//     }else{

//     }
// }

void GraphDisplay::reset(){
    for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if ((row + col) % 2 != 0) {
        xw.fillRectangle(50 + 50 * row,50 + 50 * col, 50, 50, Xwindow::Black);
      }else{
        xw.fillRectangle(50 + 50 * row,50 + 50 * col, 50, 50, Xwindow::White);
      }
    }
  }
}

void GraphDisplay::update(Subject<State> &whoFrom){
    State s = whoFrom.getState();
    reset();
    updateTiles(s.tiles);
}