/*
Description: This file has the pawn movement function
*/
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
    // this handles the movements for a black pawn first time moving
    if (board[startRow][sC]->moveCount == 0 && board[startRow][sC]->getPlayerType() == false)
    {  
	    // checks if the pawn is capturing a piece for its first move
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
	    // this checks if a pawn is moving up 2 spaces for its first turn
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
	    // this checks if a pawn is moving by only one for its first turn
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
	// this handles the red pawn movements for its first move
    if (board[startRow][sC]->moveCount == 0 && board[startRow][sC]->getPlayerType() == true)
    {
	    // checks if the pawn is capturing a piece for its first move
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
	     // this checks if a pawn is moving up 2 spaces for its first turn
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
	    // this checks if a pawn is moving by only one for its first turn
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
	// this handles the basic movements for a pawn including moving up by 1 and capturing after its first move
    else
    {
	    // checks the movements for the red pawns
        if (board[startRow][sC]->getPlayerType() == true)
        {
		// checks if the red pawn is capturing a piece
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
		// checks the red pawns basic movement
            if (endRow-startRow == -1 && eC - sC == 0)
            { 
		    // if the space is empty return true
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
	    //checks the movements for the black pawns
        if (board[startRow][sC]->getPlayerType() == false)
        {
		// checks if black pawn is capturing a piece
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
		// checks if the black pawn is moving forward
            if (endRow - startRow == 1 && eC - sC == 0)
            { 
		    // if the spapce is empty return true
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
