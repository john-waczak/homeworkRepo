/********************************************************************************************************************
 ** Author: Elizabeth Graalum
 ** Date: May 23rd, 2018
 ** Description: This program sets up a board game that can be played by two players.
It begins with each player having three game pieces each, the objective of the game is to have all three piece 
in a row (horizontally, diagonally, or vertically). The game alternated between each player asking them to place 
their game piece somewhere on the board and prints a new board after each turn. Once all of a players pieces are
on the board, they can move their pieces around the board to spaces next to the piece’s original position. 
Illegal moves include moving to the center point on a player’s first turn, moving a piece to a position not directly 
adjacent to its original position, moving from a square where there isn’t a piece placed, or moving to an occupied 
square. An error message will be displayed and the player will be asked to make a legal move.
********************************************************************************************************************/
#include <iostream>
#include "squareGame.hpp"


using std::cout;
using std::cin;
using std::endl;

const int empty         = 7;	// labels empty spaces as 7
const int player1       = 0;	// player 1's spaces as 0
const int player2       = 1;	// player 2's spaces as 1

squareGame::squareGame()	// initializer for game
{
	int i, j;
	for (i = 0; i < 3; i++)
        {
                for (j = 0; j < 3; j++)
			board[i][j] = empty;	//clear the board
        }
	turn = 0;		// clear turns

	move = 0;		// clear moves
	
	player_piece[0] = 0;	// clear player 1's pieces
	player_piece[1] = 0;	// clear player 2's pieces
	
}

int squareGame::move_piece(int playerNum)	// piece move function
{
	int a, b;
	int x, y;
	do
        {
                cout << "Player " <<playerNum + 1 << " which piece do you want to move?" <<endl;
                cin >> a;
                cin >> b;
		 if (a < 0 || a > 2 || b < 0 || b > 2 || board[a][b] != playerNum)
		// keeps a & b on board and makes only player's pieces movable
                        cout << "Your move is not valid." << endl;	// error message

        }
        while (a < 0 || a > 2 || b < 0 || b > 2 || board[a][b] != playerNum);

         do
        {
                cout << "Player " <<playerNum + 1 << " where do you want to move your piece at " << a << ", " << b << "?" <<endl;
                cin >> x;
                cin >> y;
		 if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 7)
                        cout << "Your move is not valid." << endl;

	}
       while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 7 || x > (a+1) || x < (a-1) || y > (b+1) || y < (b-1));
	
	board[x][y] = playerNum;	// puts player's piece in spot
	board[a][b] = 7;		// resets original position to empty
}
void squareGame::print_board()	// print board function
{
	int i, j;
	cout << "  0  1  2" << endl;
	for (i = 0; i < 3; i++)
	{
	cout << i;
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] == 7)
				cout << " . ";	// empty space pips
			if (board[i][j] == 0)
				cout << " x ";	// player 1's markers
			if (board[i][j] == 1)
				cout << " o ";	// player 2's markers
		}
		cout << endl;
	}
}

void squareGame::place_piece(int playerNum)	// place first three pieces on board for each player
{
	int x, y;
	do
	{
		cout << "Player " <<playerNum + 1 << " where do you want to place your piece?" <<endl;

		cin >> x;
		cin >> y;
	
		if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 7 || ((x == 1 && y == 1) && move == 0) )
		// specific exception for the first move of the game: player 1's first piece can't be on (1, 1)
			cout << "Your move is not valid." << endl;
	}	
	while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 7 || ((x == 1 && y == 1) && move == 0) );
	
	board[x][y] = playerNum;	//place piece
	
	player_piece[playerNum]++;	// add to total pieces on the board
	move++;	// increase move
}	

void squareGame::next_turn()	// cycle function
{
	print_board();
	
	if (player_piece[turn] < 3)	// execute if not all pieces are on the board
		place_piece(turn);	// place more pieces
	else
		move_piece(turn);	// if all pieces are down, allow movement of pieces

	if (turn == 1)		// if it's currently player 1's turn
		turn = 0;	// make it player 2's turn
	else			// if it's player 2's turn
		turn = 1;	// make it player 1s turn
}

int squareGame::finished() // has anyone won? let's check
{
	int i;
	int row_score, column_score;
        int left_score, right_score;
	int winner = 0;

	for (i = 0; i < 3; i++)
	{
		row_score = board[i][0] + board[i][1] + board[i][2];		
		column_score = board[0][i] + board[1][i] + board[2][i];
		
		if (row_score == 0 || column_score == 0)	// if the score is 0, player 1 has won 
			winner = 1;
		if (row_score == 3 || column_score == 3)	// if the score is 3, player 2 has won
			winner = 2;
	}

	left_score  	= board[0][0] + board[1][1] + board[2][2];
	right_score  	= board[0][2] + board[1][1] + board[2][0];
	   
	if (left_score == 0 || right_score == 0)
		winner = 1;	// player 1 has won
        if (left_score == 3 || right_score == 3)
		winner = 2;	// player 2 has won
	
	if (winner == 1)
	{
		cout << "Congratulations Player One! You’ve won!" << endl;
		print_board();
	}
	if (winner == 2)
	{
		cout << "Congratulations Player Two! You’ve won!" << endl;
		print_board();
        }

return winner;
}

