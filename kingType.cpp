#include "kingType.h"
using  namespace std;
#include <iostream>

kingType::kingType(bool color) : chessPiece(color)
{

}
bool kingType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
    int sC = startCol;
	int eC = endCol;
    if ((abs(endRow - startRow) == 1 && !(abs(eC-sC) > 1)) || (abs(eC - sC) == 1 && !(abs(endRow-startRow) > 1)))
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