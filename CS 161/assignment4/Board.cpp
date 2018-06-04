/********************************************************************* 
 ** Author: John Waczak
 ** Date: 5/23/2018
 ** Description: Implementation file for Board Class 
 *********************************************************************/ 


#include <iostream>
#include <assert.h>
#include "Board.hpp"

using std::cin;
using std::cout;
using std::endl;


/********************************************************************* 
 ** Description: Default constructor.
 *********************************************************************/
Board::Board(){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      board[i][j] = '*';
    }
  }
  isFull = false;
}


/********************************************************************* 
 ** Description: Get current value of position on board.
 *********************************************************************/
char Board::get_boardValue(int i, int j){
  assert(i < 3 && j<3 && i >= 0 && j>= 0);  // make sure indices are appropriate
  return board[i][j]; 
}


/********************************************************************* 
 ** Description: Set current value at position on the board. 
 *********************************************************************/
void Board::set_boardValue(int i, int j, char val){
  assert(i < 3 && j<3 && i >= 0 && j>= 0);  // make sure indices are appropriate
  board[i][j] = val;
}


/********************************************************************* 
 ** Description: Cout the current board configuration 
 *********************************************************************/
void Board::print_board(){
  cout<< "\t0\t1\t2" << endl << endl; 
  for (int i=0; i<3; i++){
    cout << i << "\t"; 
    for (int j=0; j<3; j++){
      cout << board[i][j] << "\t"; 
    }
    cout << endl << endl; 
  }
}


/********************************************************************* 
 ** Description: Check to see if game is over (i.e. 3 of same piece
 ** in a row) 
 *********************************************************************/
bool Board::isOver(){
  if(board[0][0]==board[0][1] && board[0][1] == board[0][2]){
    if (board[0][0]== 'x'){
      winner = 'x'; 
      return  true;
    }
    else if (board[0][0] == 'o'){
      winner = 'o';
      return true;
   }
    else
      return false; 
  }
  else if(board[1][0]==board[1][1] && board[1][1] == board[1][2]){
    if (board[1][0]== 'x'){
      winner = 'x'; 
      return  true;
    }
    else if (board[1][0] == 'o'){
      winner = 'o';
      return true;
    }
    else
      return false;
  }
  else if(board[2][0]==board[2][1] && board[2][1] == board[2][2]){
    if (board[2][0]== 'x'){
      winner = 'x'; 
      return  true;
    }
    else if (board[2][0] == 'o'){
      winner = 'o';
      return true;
    }
    else
      return false;
  }

  else if(board[0][0]==board[1][1] && board[1][1] == board[2][2]){
    if (board[0][0]== 'x'){
      winner = 'x'; 
      return  true;
    }
    else if (board[0][0] == 'o')
      return 'o';
    else
      return false;
  }

  else if(board[0][2]==board[1][1] && board[1][1] == board[2][0]){
    if (board[0][2]== 'x'){
      winner = 'x'; 
      return  true;
    }
    else if (board[0][2] == 'o'){
      winner = 'o';
      return true;
    }
    else
      return false;
  }
  else
    return false; 
}


/*********************************************************************
 ** Description: Check to see if player has all 3 pieces on board
 *********************************************************************/
bool Board::checkBoardFull(char piece){
  int numPieces = 0;
  for (int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
      if (board[i][j] == piece){
        numPieces ++; 
      }
    }
  }

  if (numPieces == 3)
    return true; 
  else
    return false; 
}


/********************************************************************* 
 ** Description: Check if move is acceptible. This one is overloaded
 ** for checking before all of a player's pieces have been placed
 ** on the board. 
 *********************************************************************/
bool Board::isLegalMove(int i, int j, int turnCount){
  if (turnCount == 0){
    if(i == 1 && j == 1){
      return false; 
    } 
  }

  if (!(i == 0 || i == 1 || i == 2)){
    return false;
  }
  if (!(j==0 || j==1 || j==2)){
    return false; 
  }

  if (board[i][j] == 'x' || board[i][j] == 'o'){
    return false; 
  }
  else
    return true; 
}


/********************************************************************* 
 ** Description: Check if move is acceptible. This overload is for 
 ** checking after all of the player's pieces are on the board. 
 *********************************************************************/
bool Board::isLegalMove(int i_old, int j_old, int i_new, int j_new,  char player){
  // guarantee that you've chosen good numbers 
  if (!(i_old >= 0 || i_old<3)){
    return false;
  }
  if (!(j_old >= 0 || j_old < 3)){
    return false; 
  }

  if (!(i_new >= 0 || i_new < 3)){
    return false;
  }

  if(!(j_new >= 0 || j_new < 3)){
    return false; 
  }



  // ------------------make sure move is orthogonal or adjacent------------------- // 
  if (board[i_old][j_old] == player){
    if((i_new == i_old+1 && j_new == j_old+1)||(i_new == i_old && j_new == j_old+1)||(i_new == i_old-1 && j_new == j_old+1)||(i_new == i_old-1 && j_new == j_old)||(i_new == i_old-1 && j_new == j_old-1)||(i_new == i_old && j_new == j_old-1)||(i_new == i_old+1 && j_new == j_old-1)||(i_new == i_old+1 && j_new == j_old)){
      return true; 
    }
    else{
      return false; 
    }
  }

  else
    return false; 
}


/********************************************************************* 
 ** Description: Return current value of winner member. 
 *********************************************************************/
char Board::get_winner(){
  return winner; 
}
