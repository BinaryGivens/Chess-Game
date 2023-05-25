#pragma once
#include "chessPiece.h"

// Declaration of the Board class
class Board {
    public:
        bool promote;
        Board();
        void outputBoard();
        void movePiece(chessPiece ***);
        void clearBoard(chessPiece ***);
        void playGame();
        void promotePawn(int, int);
        int convertColumnCharToInt(char);
        ~Board();
    private:
        chessPiece *** board;
};