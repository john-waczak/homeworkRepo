/********************************************************************* 
 ** Author: John Waczak  
 ** Date: 5/23/2018
 ** Description: Headder file for Board class to be used in almost-tic
 ** -tac-toe game 
 *********************************************************************/ 

#ifndef BOARD_HPP
#define BOARD_HPP

class Board{

private:
  char board[3][3]; 
  bool isFull; 
  char winner; 
public:
  Board(); 
  void print_board();
  char get_boardValue(int, int);
  void set_boardValue(int, int, char);
  char get_winner(); 
  bool isOver();
  bool checkBoardFull(char);
  bool isLegalMove(int, int, int);
  bool isLegalMove(int, int, int, int, char);
};



#endif  
