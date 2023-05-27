/*
Name: Markiece Givens, NSHE: 2001489836, 1003, ASSIGNMENT 5
Description: This file has the queenType piece function declarations
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
		// this section of code handles the queen moving like the rook
		// this if statement checks to see if the queen moves left
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
		// this if statement checks to see if the queen moves right
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
		// this checks if the queen moves up
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
		// this if statement checks to see if the queen moves downwards
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
	// this section of code handles if the queen moves like a bishop
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
		// this is up and to the right
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
