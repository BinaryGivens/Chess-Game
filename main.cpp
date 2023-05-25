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
#include <iostream>
#include "chessPiece.h"
#include "queenType.h"
#include "rookType.h"
#include "bishopType.h"
#include "pawnType.h"
#include "kingType.h"
#include "knightType.h"
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
void outputBoard(chessPiece***);
void clearBoard(chessPiece***);

int main()
{
	chessPiece *** board;
	board = new chessPiece**[8];
	for (int i = 0; i < 8; i++)
		board[i] = new chessPiece*[8];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;
	//place the black chess pieces onto
	//the board
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
	//place the red chess pieces onto
	//the board
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
	
	outputBoard(board);
	int	startCol, endCol;
	
	char startRow, endRow;
	int redPieces = 16;
	int blackPieces = 16;
	bool turn = true;
	while (redPieces > 0 && blackPieces > 0)
	{
		// this checks whos turn it is and changes the input based
		// of that
		if (turn == true)
		{
			cout << "Enter starting Coordinates (red turn): ";
		}
		if (turn == false)
		{
			cout << "Enter starting Coordinates (black turn): ";
		}
		// this has the user input the starting coordinates
		cin >> startRow >> startCol;
		// this makes sure the starting cooridnate corresponds
		// to a piece
		startRow = toupper(startRow);
		startRow -= 'A';
		int c = int(startRow);
		startCol -= 1;
		if (board[startCol][c] == nullptr)
		{
			cout << "Starting Coordinate is empty!" << endl << endl;
			continue;
		}
		// this makes sure the piece and player are the same
		if (turn != board[startCol][c]->getPlayerType())
		{
			cout << "Invalid piece selected." << endl << endl;
			continue;
		}
		
		// this is the ending coordinate.
		// it is user inputed
		cout << "Enter ending coordinates: " << endl;
		cin >> endRow >> endCol;
		endRow = toupper(endRow);
		endRow -= 'A';
		int d = int(endRow);
		endCol -= 1;
		// checks if the row and column indices are within range of 
		// the board
		bool promote = false;
		if (board[startCol][c]->getPlayerType() == true && endCol == 0 && dynamic_cast<pawnType*>(board[startCol][c]) != nullptr && board[startCol][c]->moveCount > 0) { // red pawn reached the last rank
			promote = true;
		}
        if (board[startCol][c]->getPlayerType() == false && endCol == 7 && dynamic_cast<pawnType*>(board[startCol][c]) != nullptr && board[startCol][c]->moveCount > 0) { // black pawn reached the last rank
			promote = true;
		}
		// this calls the move function and verifies the move is legal
		if (!(board[startCol][c]->move(startCol, startRow, endCol, endRow, board)))
		{
			cout << "Invalid move!" << endl << endl;
			continue;
		}
		if (board[startCol][c]->move(startCol, startRow, endCol, endRow, board))
		{	// this handles for when a piece takes another piece
			if (board[endCol][d] != nullptr)
			{
				if (board[endCol][d]->getPlayerType() == true)
				{
					if (dynamic_cast<kingType*>(board[endCol][d]) != nullptr)
					{
						cout << "Black Wins!";
						break;
					}
					else
					{
						redPieces--;
					}	
				}
				if (board[endCol][d]->getPlayerType() == false)
				{
					if (dynamic_cast<kingType*>(board[endCol][d]) != nullptr)
					{
						cout << "Red Wins!";
						break;
					}
					else
					{
						blackPieces--;
					}
				}
				delete board[endCol][d];

			}
			
			// this sets the end position equal to the piece the start position is pointing to
			
			board[endCol][d] = board[startCol][c];
			board[startCol][c]->moveCount++;
			// this sets the start position to null
			board[startCol][c] = nullptr;
			// checks if the piece we are moving is a pawn
			if (promote) {
				bool validPromotion = false;
				while (!validPromotion) {
					cout << "Choose a piece to promote the pawn to: queen (Q), rook (R), bishop (B), or knight (N)" << endl;
					char choice;
					cin >> choice;
					switch (toupper(choice)) {
						case 'Q':
							board[endCol][d] = new queenType(board[endCol][d]->getPlayerType());
							validPromotion = true;
							break;
						case 'R':
							board[endCol][d] = new rookType(board[endCol][d]->getPlayerType());
							validPromotion = true;
							break;
						case 'B':
							board[endCol][d] = new bishopType(board[endCol][d]->getPlayerType());
							validPromotion = true;
							break;
						case 'N':
							board[endCol][d] = new knightType(board[endCol][d]->getPlayerType());
							validPromotion = true;
							break;
						default:
							cout << "Invalid choice. Please choose again." << endl;
							break;
					}
				}
			}
			// this changes the turn
			turn = !turn;
			if (redPieces == 0)
			{
				outputBoard(board);
				cout << "Black wins" << endl << endl;
				break;
			}
			if (blackPieces == 0)
			{
				outputBoard(board);
				cout << "Red wins!" << endl << endl;
				break;
			}
		}
		outputBoard(board);
	}
	clearBoard(board);
	return 0;
}
void outputBoard(chessPiece *** board)
{
	// this prints the numbers on the top of the board
	cout << "   a  b  c  d  e  f  g  h " << endl;
	// nested for loop loops through the board and prints the pieces
	// and whether or not they are black or red
	for (int i = 0; i < 8; i++)
	{
		cout << i+1 << "  ";
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == nullptr)
			{
				cout << "- " << RESET;
			}
			if (board[i][j] != nullptr)
			{
				// this checks if the player is red. If it is then it prints
				// everything in red
				if (board[i][j]->getPlayerType() == true)
				{
					if (dynamic_cast<queenType*>(board[i][j]) != nullptr)
					{
						cout << RED << "Q " << RESET;
					}
					if (dynamic_cast<kingType*>(board[i][j]) != nullptr)
					{
						cout << RED << "K " << RESET;
					}
					if (dynamic_cast<pawnType*>(board[i][j]) != nullptr)
					{
						cout << RED << "P " << RESET;
					}
					if (dynamic_cast<knightType*>(board[i][j]) != nullptr)
					{
						cout << RED << "N " << RESET;
					}
					if (dynamic_cast<rookType*>(board[i][j]) != nullptr)
					{
						cout << RED << "R " << RESET;
					}
					if (dynamic_cast<bishopType*>(board[i][j]) != nullptr)
					{
						cout << RED << "B " << RESET;
					}
				}
				// this checks if the player is black. If it is then it prints
				if (board[i][j]->getPlayerType() == false)
				{
					if (dynamic_cast<queenType*>(board[i][j]) != nullptr)
					{
						cout << "Q " << RESET;
					}
					if (dynamic_cast<kingType*>(board[i][j]) != nullptr)
					{
						cout << "K " << RESET;
					}
					if (dynamic_cast<pawnType*>(board[i][j]) != nullptr)
					{
						cout << "P " << RESET;
					}
					if (dynamic_cast<knightType*>(board[i][j]) != nullptr)
					{
						cout <<"N " << RESET;
					}
					if (dynamic_cast<rookType*>(board[i][j]) != nullptr)
					{
						cout << "R " << RESET;
					}
					if (dynamic_cast<bishopType*>(board[i][j]) != nullptr)
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
void clearBoard(chessPiece *** board)
{
	// this nested for loop goes through 
	// the board and deletes all the chess pieces
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// checks if a piece is void. If it is not void it
			// deletes the piece
			if (board[i][j] != nullptr)
				delete board[i][j];
		}
		// this deletes the array of pointers
		delete[] board[i];
	}
	// this deletes the board
	delete[] board;	
}