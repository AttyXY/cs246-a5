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

void GraphDisplay::updateTiles(const std::vector<std::vector<char>> &setupTiles){
    reset();
    tiles = setupTiles;
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            if(tiles[7 - x][7 - y] != '-'){
                xw.drawString(75 + 50 * (7 - y), 75 + 50 * x, std::string(1,tiles[7 - x][7 - y]), Xwindow::Red);
            }
        }
    }
}


void GraphDisplay::update(Subject<State> &whoFrom){
    State s = whoFrom.getState();
    reset();
    updateTiles(s.tiles);
}
