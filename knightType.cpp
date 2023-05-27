/*
Description: This file has the Knight movement and destructor
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
		// checks if the end position is empty 
        if (board[endRow][eC] == nullptr)
        {
            return true;
        }
		// if end position isnt empty check if the piece can be captured
        if (board[endRow][eC] != nullptr)
        {
            if (board[endRow][eC]->getPlayerType() != this->getPlayerType())
            {
                return true;
            }
		// if the piece cant be captured return false
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
