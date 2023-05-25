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
#include "queenType.h"
#include <iostream>
using namespace std;

queenType::queenType(bool color) : chessPiece(color)
{ 
    // sets the color in chesspiece to the passed
    // in color in queentype
}
	
bool queenType::move(int startRow, int startCol, int endRow, int endCol, chessPiece*** board)
{
	int sC = startCol;
	int eC = endCol;
	int p = abs(eC-sC);
	int q = abs(endRow-startRow);
    // this returns true the checking of the
    // movement to make sure
    // it follows the rook or bishop movements
    // since queen can move like both
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
	
    return false;
}

queenType::~queenType()
{
    // lets you know when a queen is taken
	cout << "Queen Taken." << endl << endl;
}
