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
#include <iostream>
#include "chessPiece.h"
using namespace std;

// sets the color of the chess piece
chessPiece::chessPiece(bool color)
{
    this->moveCount = 0;
	this->color = color;
}
// this sets the players type to the current player
bool chessPiece::getPlayerType() const
{
    // this says the player is red
	if (this->color == true)
    {
        return true;
    }
    // this says the player is black
    if (this->color == false)
    {
        return false;
    }
    return true;
    
}
// this lets us know when a chess piece is taken
chessPiece::~chessPiece()
{
    
	cout << "Piece removed from board." << endl << endl << endl;
}
