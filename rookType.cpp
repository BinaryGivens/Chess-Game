/*
Name: Markiece Givens, NSHE: 2001489836, 1003, ASSIGNMENT 5
Description: This is the function for if a piece is a ROok
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
			// this for loop checks the route of the move to make sure there are no pieces
			// obstructing the move
			for (int j = 1; j < q; j++)
			{
				if (board[startRow-j][sC] != nullptr)
				{
					return false;
				}
			}
			// if the end position is to empty, check to see if the piece can be captured
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
			// this for loop checks the route of the move to make sure there are no pieces
			// obstructing the move
			for (int j = 1; j < q; j++)
			{
				if (board[startRow+j][sC] != nullptr)
				{
					return false;
				}
			}
			// if the end position is to empty, check to see if the piece can be captured
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
			// this for loop checks the route of the move to make sure there are no pieces
			// obstructing the move
			for (int j = 1; j < p; j++)
			{
				if (board[startRow][sC+j] != nullptr)
				{
					return false;
				}
				
			}
			// if the end position is to empty, check to see if the piece can be captured
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
			// this for loop checks the route of the move to make sure there are no pieces
			// obstructing the move
			for (int j = 1; j < p; j++)
			{
				if (board[startRow][sC-j] != nullptr)
				{
					return false;
				}
			}
			// if the end position is to empty, check to see if the piece can be captured
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
