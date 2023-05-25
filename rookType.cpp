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
#include "rookType.h"
#include <iostream>
using namespace std;

rookType::rookType(bool color) : chessPiece(color)
{ 
	// sets the color in chesspiece to the color 
	// passed in rookType
}

bool rookType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
	// checks if the move is valid
	int sC = startCol;
	int eC = endCol;
	int p = abs(eC-sC);
	int q = abs(endRow-startRow);
	// this checks to make sure that the rook is only moving in one direction
	// if it isnt then it returns false
	if ((q == 0 && p > 0) || (p == 0 && q > 0))
	{
		// this if statement checks to see if we move left
		if (endRow-startRow < 0)
		{
			for (int j = 1; j < q; j++)
			{
				if (board[startRow-j][sC] != nullptr)
				{
					return false;
				}
			}
			if (board[endRow][eC] != nullptr)
			{
				if (board[endRow][sC]->getPlayerType() != this->getPlayerType())
				{
					return true;
				}
				else
					return false;
			}
			else
				return true;
			
		}
		// this if statement checks to see if we move right
		if (endRow-startRow > 0)
		{
			for (int j = 1; j < q; j++)
			{
				if (board[startRow+j][sC] != nullptr)
				{
					return false;
				}
			}
			if (board[endRow][eC] != nullptr)
			{
				if (board[endRow][sC]->getPlayerType() != this->getPlayerType())
				{
					return true;
				}
				else
					return false;
			}
			else
				return true;
		}
		if (eC-sC > 0)
		{
			for (int j = 1; j < p; j++)
			{
				if (board[startRow][sC+j] != nullptr)
				{
					return false;
				}
				
			}
			if (board[endRow][eC] != nullptr)
			{
				if (board[endRow][sC]->getPlayerType() != this->getPlayerType())
				{
					return true;
				}
				else
					return false;
			}
			else
				return true;
			
		}
		// this if statement checks to see if we move downwards
		if (eC-sC < 0)
		{
			for (int j = 1; j < p; j++)
			{
				if (board[startRow][sC-j] != nullptr)
				{
					return false;
				}
			}
			if (board[endRow][eC] != nullptr)
			{
				if (board[endRow][sC]->getPlayerType() != this->getPlayerType())
				{
					return true;
				}
				else
					return false;
			}
			else
				return true;
		}
		
	}
	else
		return false;
	return false;
}
// this lets us know when a rook is taken
rookType::~rookType()
{
	cout << "Rook Taken." << endl << endl;
}
