/************************************************************************************
** Author: Elizabeth Graalum
** Date: May 23rd, 2018
** Description: This program sets up the board game class for squareGame
************************************************************************************/

#ifndef SQUAREGAME_HPP
#define SQUAREGAME_HPP

class squareGame
{
private:
	int x, y; 	// points for placing and assigning piece
	int a, b; 	// points for selecting piece
	
	int i, j;	// used to cycle through arrays
	
	int board[3][3];	// set up board
	int turn;		// track turns
	int move;		// traack moves
	int player_piece[2];	// arrays of pieces for each player
	int playerNum;		// assign players a number
		
	int row_score, column_score;	// row & column score used to find winner 
	int left_score, right_score;	// diagonal score used to find winner
	
public:
	squareGame();	// initalizer
	squareGame(int, int);

	void print_board();	// print board function prototype
	 
	int move_piece(int);	// move piece function prototype
	void next_turn();	// turn function prototype
	void place_piece(int); 	// place piece function prototype
	
	int finished();		// end game function prototype
	void print_winner();	// winner statement function prototype
};
#endif
