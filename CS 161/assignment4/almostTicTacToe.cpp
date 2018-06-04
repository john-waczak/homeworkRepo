/********************************************************************* 
 ** Author: John Waczak 
 ** Date: 5/23/2018
 ** Description: Main file for almost-tic-tac-toe game. Uses board
 ** Class from Board.cpp / Board.hpp 
 *********************************************************************/ 




#include <iostream>
#include "Board.hpp"

using std::cin;
using std::cout;
using std::endl;


int main(){

  Board board;
  int turn = 1;
  int turnCount = 0; 

  cout << ".........................................................................." << endl;
  cout << endl << endl;
  cout << "\t\t\tAlmost Tic Tac Toe" << endl << endl << endl;
  cout << "\t\t\t\t\t\t(press ENTER to continue)" << endl;
  cout << ".........................................................................." << endl;
  cin.get();  

  while(!board.isOver()){
    cout << "It is player ("<< turn << ")'s turn." << endl << endl;
    board.print_board(); 
    cout << endl; 

    char player;
    if (turn == 1){
      player = 'x'; 
    }
    else{
      player = 'o'; 
    }


    //-------------------------------- board not full yet -------------------------------
    if (!board.checkBoardFull(player)){
      int i;
      int j;
      cout << "You still have pieces to put on the board." << endl;
      cout << "Please enter the row and column of position to place your piece." << endl;
      cin >> i;
      cin >> j;

      bool goodMove = false;
      while(!goodMove){
        if(board.isLegalMove(i, j, turnCount)){
          board.set_boardValue(i, j, player);
          goodMove = true;
        }
        else{
          cout << endl;
          cout << "You can not move there. Please enter new coordinates." << endl;
          cin >> i;
          cin >> j;
        }
      }
    }

    //------------------------------- board full ----------------------------------------
    else{
      int i_old;
      int j_old;
      int i_new;
      int j_new;
      bool goodMove = false;
      cout << "The board is full. You can move one of your pieces adjacent or diagonally." << endl;

      //------ pick spot to place piece ----------
      cout << endl;
      cout << "Please enter coordinates of the piece you would like to move." << endl;
      cin >> i_old;
      cin >> j_old;
      cout << "Please enter the coordinates of where you would like to move it" << endl;
      cin >> i_new;
      cin >> j_new; 
      while(!goodMove){
        if (board.isLegalMove(i_old, j_old, i_new, j_new, player)){
          board.set_boardValue(i_new, j_new, player);
          board.set_boardValue(i_old, j_old, '*');                                          
          goodMove = true;
        }
        else{
          cout<< endl;
          cout << "You can not move there. Please enter new coordinates." << endl;
          cout << "Which peice would you like to move?" << endl; 
          cin >> i_old;
          cin >> j_old;
          cout << "Where would you like to move it?" << endl; 
        }
      }
    }


    // switch turn to other player
    if (turn == 1){
      turn = 2;
    }
    else if (turn == 2){
      turn = 1;
    }
    turnCount ++ ; 
  }


  cout << "...................................................." << endl << endl << endl;
  cout << "\t\tGAME OVER"<< endl<<endl;
  board.print_board();
  cout << endl;
  if (board.get_winner() == 'x'){
    cout << "\t\tPlayer 1 wins!" << endl << endl << endl;
  }
  else{
    cout <<"\t\tPlayer 2 wins!" << endl << endl << endl;
  }

  return 0; 
}
