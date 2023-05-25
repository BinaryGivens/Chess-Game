#include <iostream>

#include "Board.h"
#include "queenType.h"
#include "rookType.h"
#include "bishopType.h"
#include "pawnType.h"
#include "kingType.h"
#include "knightType.h"

using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"

Board::Board() {

    // Create the board
    board = new chessPiece**[8];

    // Create the columns
    for (int i = 0; i < 8; i++) {
        board[i] = new chessPiece*[8];
    }

    // Initialize the board to nullptr
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }

    // Place the black chess pieces onto the board
    board[0][1] = new knightType(false);
    board[0][0] = new rookType(false);
    board[0][5] = new bishopType(false);
    board[0][3] = new queenType(false);
    board[0][2] = new bishopType(false);
    board[0][7] = new rookType(false);
    board[0][6] = new knightType(false);
    board[0][4] = new kingType(false);
    board[1][7] = new pawnType(false);
    board[1][6] = new pawnType(false);
    board[1][5] = new pawnType(false);
    board[1][4] = new pawnType(false);
    board[1][3] = new pawnType(false);
    board[1][2] = new pawnType(false);
    board[1][1] = new pawnType(false);
    board[1][0] = new pawnType(false);

    // Place the red chess pieces onto the board
    board[7][1] = new knightType(true);
    board[7][7] = new rookType(true);
    board[7][2] = new bishopType(true);
    board[7][4] = new queenType(true);
    board[7][5] = new bishopType(true);
    board[7][0] = new rookType(true);
    board[7][6] = new knightType(true);
    board[7][3] = new kingType(true);
    board[6][7] = new pawnType(true);
    board[6][6] = new pawnType(true);
    board[6][5] = new pawnType(true);
    board[6][4] = new pawnType(true);
    board[6][3] = new pawnType(true);
    board[6][2] = new pawnType(true);
    board[6][1] = new pawnType(true);
    board[6][0] = new pawnType(true);

}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete board[i][j];
        }
    }
    for (int i = 0; i < 8; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Board::promotePawn(int row, int col) {
	
	bool validPromotion = false;
	while (!validPromotion) {
		cout << "Choose a piece to promote the pawn to: queen (Q), rook (R), bishop (B), or knight (N)" << endl;
		char choice;
		cin >> choice;
		switch (toupper(choice)) {
			case 'Q':
				board[row][col] = new queenType(board[row][col]->getPlayerType());
				validPromotion = true;
				break;
			case 'R':
				board[row][col] = new rookType(board[row][col]->getPlayerType());
				validPromotion = true;
				break;
			case 'B':
				board[row][col] = new bishopType(board[row][col]->getPlayerType());
				validPromotion = true;
				break;
			case 'N':
				board[row][col] = new knightType(board[row][col]->getPlayerType());
				validPromotion = true;
				break;
			default:
				cout << "Invalid choice. Please choose again." << endl;
				break;
		}
	}
}


void Board::outputBoard()
{
    // this prints the numbers on the top of the board
    cout << "   a  b  c  d  e  f  g  h " << endl;
    // nested for loop loops through the board and prints the pieces
    // and whether or not they are black or red
    for (int rowMarker = 0; rowMarker < 8; rowMarker++)
    {
        cout << rowMarker + 1 << "  ";
        for (int j = 0; j < 8; j++)
        {
            if (board[rowMarker][j] == nullptr)
            {
                cout << "- " << RESET;
            }
            if (board[rowMarker][j] != nullptr)
            {
                // this checks if the player is red. If it is then it prints
                // everything in red
                if (board[rowMarker][j]->getPlayerType() == true)
                {
                    if (dynamic_cast<queenType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "Q " << RESET;
                    }
                    if (dynamic_cast<kingType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "K " << RESET;
                    }
                    if (dynamic_cast<pawnType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "P " << RESET;
                    }
                    if (dynamic_cast<knightType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "N " << RESET;
                    }
                    if (dynamic_cast<rookType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "R " << RESET;
                    }
                    if (dynamic_cast<bishopType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << RED << "B " << RESET;
                    }
                }
                // this checks if the player is black. If it is then it prints
                if (board[rowMarker][j]->getPlayerType() == false)
                {
                    if (dynamic_cast<queenType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << "Q " << RESET;
                    }
                    if (dynamic_cast<kingType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << "K " << RESET;
                    }
                    if (dynamic_cast<pawnType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << "P " << RESET;
                    }
                    if (dynamic_cast<knightType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout <<"N " << RESET;
                    }
                    if (dynamic_cast<rookType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << "R " << RESET;
                    }
                    if (dynamic_cast<bishopType*>(board[rowMarker][j]) != nullptr)
                    {
                        cout << "B " << RESET;
                    }
                }
            
            }
            cout << ' ';
        }
        cout << RESET << endl << endl;
    }
}

void Board::clearBoard(chessPiece *** board)
{
    // this nested for loop goes through 
    // the board and deletes all the chess pieces
    for (int rowMarker = 0; rowMarker < 8; rowMarker++)
    {
        for (int j = 0; j < 8; j++)
        {
            // checks if a piece is void. If it is not void it
            // deletes the piece
            if (board[rowMarker][j] != nullptr)
                delete board[rowMarker][j];
        }
        // this deletes the array of pointers
        delete[] board[rowMarker];
    }
    // this deletes the board
    delete[] board;	
}

int Board::convertColumnCharToInt(char lowerCaseColumn) {
    char upperCaseColumn = toupper(lowerCaseColumn);
    upperCaseColumn -= 'A';
    int returnUpperCase = int(upperCaseColumn);
    return returnUpperCase;
}
