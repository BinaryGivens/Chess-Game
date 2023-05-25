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
	if (abs(startRow - endRow) == abs(sC - eC))
	{
		if (startRow < endRow && sC < eC)
		{
			for (int i = 1; i <= q; i++)
			{
				if (board[startRow+i][sC+i] == nullptr)
				{
					return true;
				}
				if (board[startRow+i][sC+i] != nullptr)
				{
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
					else
						return false;
				}
			}
		}
		// this is up and to the left
		if (startRow < endRow && sC < eC)
		{
			for (int i = 1; i <= q; i++)
			{
				if (board[startRow+i][sC+i] == nullptr)
				{
					return true;
				}
				if (board[startRow+i][sC+i] != nullptr)
				{
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
					else
						return false;
				}
			}
		}
		// this is up and to the left
		if (startRow > endRow && sC < eC)
		{
			for (int j = 1; j <= q; j++)
			{
				if (board[startRow-j][sC+j] == nullptr)
				{
					return true;
				}
				if (board[startRow-j][sC+j] != nullptr)
				{
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
					else
						return false;
				}
			}
		}
		// this is down and the left
		if (startRow > endRow && sC > eC)
		{
			for (int j = 1; j <= q; j++)
			{
				if (board[startRow-j][sC-j] == nullptr)
				{
					return true;
				}
				if (board[startRow-j][sC-j] != nullptr)
				{
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
					else
						return false;
				}
			}
		}
		// this is down and to the right
		if (startRow < endRow && sC > eC)
		{
			for (int j = 1; j <= q; j++)
			{
				if (board[startRow+j][sC-j] == nullptr)
				{
					return true;
				}
				if (board[startRow+j][sC-j] != nullptr)
				{
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
