/*
Description: This cpp file handles the bishopType class that handles the bishops movements

*/
#include "bishopType.h"
#include <cmath>
#include <iostream>
using namespace std;

bishopType::bishopType(bool color) : chessPiece(color)
{
	// this sets the color in chesspiece to the color
	// passed from bishoptype
}
	
bool bishopType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
	// this variable stores how much the bishop moves diagonally
	int sC = startCol;
	int eC = endCol;
	int q = abs(endRow-startRow);
	// this makes sure that the bishop moves equally in both directions
	if (abs(startRow - endRow) != abs(sC - eC))
	{
		return false;
	}
	// this makes sure the bishop is moving the same way in each direction (diagonally)
	if (abs(startRow - endRow) == abs(sC - eC))
	{
		// this checks if the bishop is moving up and to the right
		if (startRow < endRow && sC < eC)
		{
			// iterates through every spot the bishops moves over
			for (int i = 1; i <= q; i++)
			{
				// return true if every spot the bishop moves through is empty
				if (board[startRow+i][sC+i] == nullptr)
				{
					return true;
				}
				// if a spot isnt empty check if its the end position
				if (board[startRow+i][sC+i] != nullptr)
				{
					// if it is the end position check if the piece can be captured
					if ((startRow+i) == endRow)
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
					// if its not the end position return false
					else
						return false;
				}
			}
		}
		// this checks if bishop is moving up and to the left
		if (startRow > endRow && sC < eC)
		{
			// iterates through every spot the bishops moves over
			for (int j = 1; j <= q; j++)
			{
				// return true if every spot the bishop moves through is empty
				if (board[startRow-j][sC+j] == nullptr)
				{
					return true;
				}
				// if a spot isnt empty check if its the end position
				if (board[startRow-j][sC+j] != nullptr)
				{
					// if it is the end position check if the piece can be captured
					if ((sC+j) == eC)
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
					// if its not the end position return false
					else
						return false;
				}
			}
		}
		// this checks if bishop down and the left
		if (startRow > endRow && sC > eC)
		{
			// iterates through every spot the bishops moves over
			for (int j = 1; j <= q; j++)
			{
				// return true if every spot the bishop moves through is empty
				if (board[startRow-j][sC-j] == nullptr)
				{
					return true;
				}
				// if a spot isnt empty check if its the end position
				if (board[startRow-j][sC-j] != nullptr)
				{
					// if it is the end position check if the piece can be captured
					if ((startRow-j) == endRow)
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
					// if its not the end position return false
					else
						return false;
				}
			}
		}
		// this checks if bishop is moving down and to the right
		if (startRow < endRow && sC > eC)
		{
			// iterates through every spot the bishops moves over
			for (int j = 1; j <= q; j++)
			{
				// return true if every spot the bishop moves through is empty
				if (board[startRow+j][sC-j] == nullptr)
				{
					return true;
				}
				// if a spot isnt empty check if its the end position
				if (board[startRow+j][sC-j] != nullptr)
				{
					// if it is the end position check if the piece can be captured
					if ((startRow+j) == endRow)
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
					// if its not the end position return false
					else
						return false;
				}
			}
		}
		// this checks if the moving piece has a different color
		// than any piece thats in the final position
		
	}
	else
		return false;
	// this handles for when the bisop moves up and to the right
	
	return false;
}
bishopType::~bishopType()
{
	// lets you know when a bishop is taken
	cout << "Bishop Taken." << endl << endl;
}
