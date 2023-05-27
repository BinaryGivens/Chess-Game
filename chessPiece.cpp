/*
Description: inherited class that sets eats chesspieces color, player and handles prints when a piece is removed
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
