/********************************************************************
 * Author:Katelynn Thorn
 * Date: 05/20/18
 * Description: This program runs a tic-tac-toe style game between
 * two players.
 * ******************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl; 

void printBoard(char arr[][3]);
bool gameOver(char arr[][3]);

int main()
{
	char board[3][3] = {{'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'}};
        printBoard(board);

        int count = 0;
        int x;
        int y;
        int player = 1;
        int winner;
        bool illegal = false;
        bool wrong = false;
        int r;
        int c;
        int r2;
        int c2;

        do{
             illegal = false;
	    
	     //Start of game- each player gets to play three pieces on the board
             cout << "Player " << player;
	     cout <<  ", please enter a spot (row, column) that you would like to play a piece." << endl;
             cin >> x;
             cin.ignore();
             cin >> y;

	     //First player cannot place piece at 1,1 on the first move of the game
	     //For all illegal moves, the game board reprints and the program asks 
	     //the user to re-enter their move.
             if(count == 0 && (x == 1 && y == 1))
	     {
                  printBoard(board);
                  cout << "This is an illegal move. Please re-enter your move." << endl;
                  illegal = true;
	     }

             else
		  //It is illegal to move to an occupied space
	          if(board[x][y] == 'x' || board[x][y] == 'o')
		  {
                       printBoard(board);
                       cout << "This is an illegal move. Please re-enter your move." << endl;
                       illegal = true;
                  }
             else
                  if (player == 1)
                       board[x][y] = '1';
                  else
                       if(player == 2)
                          board[x][y] = '2';

	     //Only if the player plays a legal move will it switch to the next player's turn
             if(illegal == false)
	     {
                  printBoard(board);
	          if(player == 1)
                       player = 2;
        	  else
                       player = 1;
		  count++;
	     }

        }
	while(gameOver(board) == false && count < 6);

	//This will continue the game until one of the player's wins
        while(gameOver(board) == false)
	{
	      //Asks the player to choose a piece they would like to move
              cout << "Player " << player;
              cout << ", please choose one of your pieces you would like to move (row, column)." << endl;
              cin >> r;
              cin.ignore();
              cin >> c;

	      //Players cannot choose a piece that isn't theirs or an empty piece
              if(player == 1)
	      {
                   if(board[r][c] == '.' || board[r][c] == 'o')
		   {
                        cout << "This is an illegal move. Please re-enter your move." << endl;
                        illegal = true;
		   }
                   else
                        illegal = false;
	      }
              else
                   if(player == 2)
		   {
                        if(board[r][c] == '.' || board[r][c] == 'x')
			{
                	     cout << "This is an illegal move. Please re-enter your move." << endl;
                             illegal = true;
			}
                        else
                             illegal = false;
		   }

	     //Asks player where they would like to move a piece to
             if(illegal == false)
	     {
                  cout << "Please enter where you would like to move it to (row,column)." << endl;
        	  cin >> r2;
        	  cin.ignore();
        	  cin >> c2;

		  //A player cannot move to a non-adjacent spot
		  if((r2 == r && c2 == c+1) || (r2 == r && c2 == c-1) || (r2 == r+1 && c2 == c) || (r2 == r-1 && c2 == c) || (r2 == r+1 && c2 == c+1) || (r2 == r-1 && c == c-1) || (r2 == r-1 && c2 == c+1) || (r2 == r+1 && c2 == c-1))
		  {
                       illegal = false;
                       wrong = false;
                  }

        	  else
		  {
		       cout << "This is an illegal move. Please re-enter your move." << endl;
                       printBoard(board);
                       illegal = true;
                       wrong = true;
		  }

		  //A player cannot move to an occupied spot
                  if(board[r2][c2] == 'x' || board[r2][c2] == 'o')
		  {
                       cout << "This is an illegal move. Please re-enter your move." << endl;
                       printBoard(board);
                       illegal = true;
                       wrong = true;
		  }
        	  else
        	       if(board[r2][c2] == '.')
        	       {
                            illegal = false;
                	    wrong = false;
		       }

		//When a player chooses a legal piece and spot, it will move there
		//and it will become the next player's turn
        	if(wrong == false)
		{
        	      board[r][c] = '0';
        	      if (player == 1)
        	           board[r2][c2] = '1';
        	      else
                           if(player == 2)
                                board[r2][c2] = '2';
                      printBoard(board);

        	      if(player == 1)
                           player = 2;
        	      else
                           player = 1;
		}
	}
}

	//If a player wins, the winner will be displayed
        if(gameOver(board) == true)
	{       
	     if(player == 1)
                  player = 2;
             else
                  player = 1;
             cout << "Player " << player << " wins!" << endl;
	}

	return 0;
}

void printBoard(char arr[][3])
{
	//This function prints the board layout
	for (int i = 0; i < 3; i++)
        {
                for(int j = 0; j < 3; j++)
		{
                     if (arr[i][j] == '0')
                     arr[i][j] = '.';
                     else
                     if (arr[i][j] == '1')
                     arr[i][j] = 'x';
                     else
                     if(arr[i][j] == '2')
                     arr[i][j] = 'o';
                }
        }

        cout << "  " << "0 " << "1 " << "2 " << endl;
        cout << "0 " << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << endl;
        cout << "1 " << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << endl;
        cout << "2 " << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << endl;
}

bool gameOver(char arr[][3])
{
	//This function checks to see if a player has won
	//It looks to see if a player has three pieces in a row
	bool threeInRow = false;
        if (arr[0][0] == 'x' && arr[0][1] == 'x' && arr[0][2] == 'x')
                threeInRow = true;
        else
                if(arr[1][0] == 'x' && arr[1][1] == 'x' && arr[1][2] == 'x')
                threeInRow = true;
        else
                if(arr[2][0] == 'x' && arr[2][1] == 'x' && arr[2][2] == 'x')
                threeInRow = true;
        else
                if(arr[0][0] == 'x' && arr[1][0] == 'x' && arr[2][0] == 'x')
                threeInRow = true;
        else
                if(arr[0][1] == 'x' && arr[1][1] == 'x' && arr[2][1] == 'x')
                threeInRow = true;
        else
                if(arr[0][2] == 'x' && arr[1][2] == 'x' && arr[2][2] == 'x')
                threeInRow = true;
        else
                if(arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x')
                threeInRow = true;
        else
                if(arr[0][2] == 'x' && arr[1][1] == 'x' && arr[0][2] == 'x')
                threeInRow = true;

        else
                if(arr[0][0] == 'o' && arr[0][1] == 'o' && arr[0][2] == 'o')
                threeInRow = true;
        else
                if(arr[1][0] == 'o' && arr[1][1] == 'o' && arr[1][2] == 'o')
                threeInRow = true;
        else
                if(arr[2][0] == 'o' && arr[2][1] == 'o' && arr[2][2] == 'o')
                threeInRow = true;
        else
                if(arr[0][0] == 'o' && arr[1][0] == 'o' && arr[2][0] == 'o')
                threeInRow = true;
        else
                if(arr[0][1] == 'o' && arr[1][1] == 'o' && arr[2][1] == 'o')
                threeInRow = true;
        else
                if(arr[0][2] == 'o' && arr[1][2] == 'o' && arr[2][2] == 'o')
                threeInRow = true;
        else
                if(arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o')
                threeInRow = true;
        else
                if(arr[0][2] == 'o' && arr[1][1] == 'o' && arr[0][2] == 'o')
                threeInRow = true;

        return threeInRow;
}

