#include "pawnType.h"
using  namespace std;
#include <iostream>

pawnType::pawnType(bool color) : chessPiece(color)
{

}
bool pawnType::move(int startRow, int startCol, int endRow, 
	int endCol, chessPiece*** board)
{
    int sC = startCol;
	int eC = endCol;
    
    if (board[startRow][sC]->moveCount == 0 && board[startRow][sC]->getPlayerType() == false)
    {  
        if (endRow - startRow == 1 && abs(eC-sC) == 1)
            {
                if (board[endRow][eC] != nullptr)
                {
                    if (board[endRow][eC]->getPlayerType() == true)
                    {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        if (endRow - startRow == 2 && board[endRow][eC] == nullptr && eC - sC == 0)
        {
            if (board[startRow+1][eC]== nullptr)
            {
                return true;
            }
            if (board[startRow+1][eC] != nullptr)
            { 
                return false;
            }
        }
        if (endRow - startRow == 1 && eC - sC == 0)
        {
            if (board[endRow][eC] == nullptr)
                {
                    return true;
                }
                if (board[endRow][eC] != nullptr)
                {
                    return false;
                }
        }
        else
        {
            return false;
        }
    }
    if (board[startRow][sC]->moveCount == 0 && board[startRow][sC]->getPlayerType() == true)
    {
        if (endRow - startRow == -1 && abs(eC-sC) == 1)
        {
            if (board[endRow][eC] != nullptr)
            {
                if (board[endRow][eC]->getPlayerType() == false)
                {
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        if (endRow - startRow == -2 && board[endRow][eC] == nullptr && eC - sC == 0)
        {
            if (board[startRow-1][eC]== nullptr)
            {
                return true;
            }
            if (board[startRow-1][eC] != nullptr)
            { 
                return false;
            }
        }
        if (endRow - startRow == -1 && eC - sC == 0)
        {
            if (board[endRow][eC] == nullptr)
                {
                    return true;
                }
                if (board[endRow][eC] != nullptr)
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
    {
        if (board[startRow][sC]->getPlayerType() == true)
        {
            if (endRow - startRow == -1 && abs(eC-sC) == 1)
            {
                if (board[endRow][eC] != nullptr)
                {
                    if (board[endRow][eC]->getPlayerType() == false)
                    {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            if (endRow-startRow == -1 && eC - sC == 0)
            { 
                if (board[endRow][eC] == nullptr)
                {
                    return true;
                }
                if (board[endRow][eC] != nullptr)
                {
                    return false;
                }
            }
        }
        if (board[startRow][sC]->getPlayerType() == false)
        {
            if (endRow - startRow == 1 && abs(eC-sC) == 1)
            {
                if (board[endRow][eC] != nullptr)
                {
                    if (board[endRow][eC]->getPlayerType() == true)
                    {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            if (endRow - startRow == 1 && eC - sC == 0)
            { 
                if (board[endRow][eC] == nullptr)
                {
                    return true;
                }
                if (board[endRow][eC] != nullptr)
                {
                    return false;
                }
            }
        }
    }
    return false;
}

pawnType::~pawnType()
{
    cout << "Pawn taken." << endl << endl;
}