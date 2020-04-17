#include "board.h"
using namespace std;

void Board::init(std::vector<std::vector<char>> &setupTiles) {
    charTiles = setupTiles;

    // TODO: Convert setupTiles into board
    for (int row = 0; row < 8; ++row) {
        tiles.emplace_back(std::vector<std::shared_ptr<Piece>>());
        for (int col = 0; col < 8; ++col) {
            tiles[col].emplace_back(nullptr);
        }
    }

    /*
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8, ++col) {
            switch(setupTiles[col][row]) {
                case 'k': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::Black, PieceType::K);
                }
                case 'K': {
                    tiles[col][row] =
                        std::make_shared<King>(Colour::White, PieceType::K);
                }
                case 'q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::Black, PieceType::Q);
                }
                case 'Q': {
                    tiles[col][row] =
                        std::make_shared<Queen>(Colour::White, PieceType::Q);
                }
                case 'r': {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::Black, PieceType::R);
                }
                case 'R' {
                    tiles[col][row] =
                        std::make_shared<Rook>(Colour::White, PieceType::R);
                }
                case 'n': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::Black, PieceType::N);
                }
                case 'N': {
                    tiles[col][row] =
                        std::make_shared<Knight>(Colour::White, PieceType::N);
                }
                case 'b': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::Black, PieceType::B);
                }
                case 'B': {
                    tiles[col][row] =
                        std::make_shared<Bishop>(Colour::White, PieceType::B);
                }
                case 'p': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::Black, PieceType::P);
                }
                case 'P': {
                    tiles[col][row] =
                        std::make_shared<Pawn>(Colour::White, PieceType::P);
                }
            }
        }
    }
    td = std::make_shared<TextDisplay();

    this->attach(td.get());
    this->attach(gd.get());
    this->setState(State{StateType::NewGrid, Move{MoveType::NoType, Coordinate{},
                                                    Coordinate{}, '-', tempGrid}});
    this->notify();

    */
    //gd = std::make_shared<GraphicsDisplay>();
}

Board::~Board() {}

bool Board::canMove(Subject <State> &whoFrom) { // check if can move
    /* LEGAL MOVE CHECKS
    
    // TODO: check
    if (isCheck(m)) {
        whiteInCheck = true;
        blackInCheck = true;
        // TODO: checkmate
    }
    else if (isStalemate(m)) {
        // no legal move 
        // game is a draw
    }
    // TODO: threefold repetition
    // TODO: fifty-move-rule
    */
    State s = whoFrom.getState();
    Colour playerColour = whoFrom.getState().c;
    Move playerMove = whoFrom.getState().m;
    Coord start = whoFrom.getState().m.start;
    Coord end = whoFrom.getState().m.end;
    shared_ptr<Piece> p = tiles[start.getCol()][start.getRow()];

    //If the piece is not moving
    if(start.getCol() == end.getCol() && start.getRow() == end.getRow()){
        return false;
    }
    //If player tries to move an empty tile
    if(!p) return false;

    //If the regular move is illegal
    if(!p->isLegal(playerMove,tiles)) return false; // isLegal checks if piece is moving within board, is valid, or if the piece is capturing enemy's piece

    //If a white player tries to move a black piece
    if(playerColour == Colour::White && isBlack(start)) return false;

    //If a black player tries to move a white piece
    if(playerColour == Colour::Black && isWhite(start)) return false;

    return true;
}

void Board::update(Subject<State> &whoFrom){ // Player notifies Board
    Coord start = whoFrom.getState().m.start;
    Coord end = whoFrom.getState().m.end;
    Move playerMove = whoFrom.getState().m;
    Colour playerColour = whoFrom.getState().c;
    if(canMove(whoFrom)){
        // checks if special move
        if(isPawnPromotion(whoFrom)){
            // lastMoveValid = promotePawn(whoFrom); // return boolean
            return; 
        }else if (isEnPassant(whoFrom)){
            // lastMoveValid = isEnpassant(whoFrom); // return boolean
            return;
        }else if (isCastling(whoFrom)){
            // lastMoveValid = castle(whoFrom); // return boolean
            return;
        } else { //if regular move
            lastMoveValid = true;
            add(playerMove);
            State s;
            s.m = whoFrom.getState().m;
            s.c = whoFrom.getState().c;
            s.moveType = MoveType::Normal;// to tell td to print normal move 
            s.tiles = charTiles;
            this->setState(s);
            this->notify(); //notifies td and gd 
            return;
        }
    } else {
        lastMoveValid = false;
        return;
    }
}

void Board::add(Move m) {
    Coord start = m.start;
    Coord end = m.end;
    std::shared_ptr<Piece> p = tiles[start.getCol()][start.getRow()];
    std::shared_ptr<Piece> capturedPiece = tiles[end.getCol()][end.getRow()];
    if(capturedPiece){ // check if a piece if captured
        remove(end);
    }
    p->loc = end;
    if(!p->hasMoved){
        p->hasMoved = true;
    }
    tiles[end.getCol()][end.getRow()] = p;
    tiles[start.getCol()][start.getRow()] = nullptr;
}

void Board::remove(Coord c) {
    if(tiles[c.getCol()][c.getRow()]){
        tiles[c.getCol()][c.getRow()] = nullptr;
    }
    // if using vector of blackPieces $ whitePieces needs to delete the corresponding piece
}

//void undo(void)
// void redo(void);
//TextDisplay td;
//GraphDisplay gd;

//  // TODO: stalemate
//     bool isStalemate(Move m) {
//         // Insufficient pieces
//         if (King and Bishop || King and Knight) {

//         }
//         // No legal moves
//         for (auto &p: pieces) {if (p.legalMove(m))}
//     }


bool Board::isPawnPromotion(Subject<State> &whoFrom){
    return false;
}
bool Board::isEnPassant(Subject<State> &whoFrom){
    return false;
}
bool Board::isCastling(Subject<State> &whoFrom){
    return false;
}

bool Board::isBlack(Coord pos){
    shared_ptr<Piece> p = tiles[pos.getCol()][pos.getRow()];
    if(p->colour == Colour::Black) return true;
    return false;
}


bool Board::isWhite(Coord pos){
    shared_ptr<Piece> p = tiles[pos.getCol()][pos.getRow()];
    if(p->colour == Colour::White) return true;
    return false;
}