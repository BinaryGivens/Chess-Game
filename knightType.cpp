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
#include "knightType.h"
#include <iostream>
using namespace std;

knightType::knightType(bool color) : chessPiece(color)
{ 
    // sets the color in chesspiece to the color
    // passed in knight type
}
	
bool knightType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
    int sC = startCol;
	int eC = endCol;
    // this checks and makes sure that the knight is moving 
    // correctly. this checks if it moves 2 spaces and 1 spaces
    // in different directions
	if ((abs(startRow-endRow) == 2 || abs(sC-eC) == 2)
        && (abs(startRow-endRow) == 1 || abs(sC - eC) == 1))
    {
        if (board[endRow][eC] == nullptr)
        {
            return true;
        }
        if (board[endRow][eC] != nullptr)
        {
            if (board[endRow][eC]->getPlayerType() != this->getPlayerType())
            {
                return true;
            }
            if (board[endRow][eC]->getPlayerType() == this->getPlayerType())
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
	return false;
}
knightType::~knightType()
{
    //lets you know when a knight is taken
	cout << "Knight taken." << endl << endl;
}
