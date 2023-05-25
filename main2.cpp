/*
Name: Markiece Givens, NSHE: 2001489836, 1003, ASSIGNMENT 5
Description: This assignment is a chess game that allows the user
to make moves and check to see if the move is valid. It also
alternates players turns between black and red.
Input: The user inputs an initial move that must correlate to a
piece on the board. The user then inputs a final move that must
either contain a nullptr or a piece of the opposite color.
Output: The output is the board with the pieces in their positions.
It also displays black and red pieces.
*/
#include "Board.h"
#include <iostream>

int main()
{
    // Invoke board class
    Board chessBoard;
    chessBoard.playGame();


    return 0;
}
