/*
Description: handles the movements for the king

*/
#include "kingType.h"
using  namespace std;
#include <iostream>

kingType::kingType(bool color) : chessPiece(color)
{

}
// king move function
bool kingType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
    int sC = startCol;
	int eC = endCol;
	// checks if the king moves by only one in any direction
    if ((abs(endRow - startRow) == 1 && !(abs(eC-sC) > 1)) || (abs(eC - sC) == 1 && !(abs(endRow-startRow) > 1)))
    {
	    // if the kings end position is empty return true
        if (board[endRow][eC] == nullptr)
        {
            return true;
        }
	   // if end position is not empty check if piece can be captured
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
        else
        {
            return false;
        }
        
    }
    else
        return false;
    return false;
}
kingType::~kingType()
{
    cout << "King taken." << endl << endl;
}
