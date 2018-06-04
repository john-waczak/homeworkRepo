/********************************************************************* 
 ** Author: John Waczak
 ** Date: 5/8/2018
 ** Description: A simple dice game 
 *********************************************************************/ 



#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string; 


/********************************************************************* 
 ** Description: Function for handling a player's turn. Roll's dice
 ** and gives player option to hold or continue after their roll. 
 *********************************************************************/ 
void takeTurn(int& playerScore ){
  bool turnOver = false;
  int turnScore = 0; 
  while(turnOver != true){
    int roll_1 = (rand()%6)+1;
    int roll_2 = (rand()%6)+1;
    cout << "Your current turn total is: " << turnScore << endl; 
    cout << "You rolled " << roll_1 << ", " << roll_2 << endl; 
    if (roll_1 == 1 or roll_2 == 1){
      cout << "You rolled a single 1. Your turn is over" << endl;
      turnOver = true; 
    }

    else if (roll_1 == 1 and roll_2 == 1) {
      playerScore = 0;
      turnOver = true; 
    }
    else{
      char yesNo; 
      cout << "Would you like to hold? (y/n)" << endl;
      cin >> yesNo;
      cout << endl; 
      if (yesNo == 'y' or yesNo == 'Y'){
        turnOver = true;
        turnScore += roll_1 + roll_2;
      }
      else if (yesNo == 'n' or yesNo == 'N'){
        turnScore += roll_1 + roll_2;
      }
      playerScore += turnScore; 
    }   
  }
}



int main(){

  srand(time(0));
  int player_1_score = 0;
  int player_2_score = 0;
  int turn = 1; 
  bool gameOver = false;

  cout << "__________DICE GAME__________" << endl << endl; 

  while(gameOver == false){
    
    if(turn == 1){
      cout << "Player One's Turn." << endl;
      takeTurn(player_1_score);
      turn = 2; 
    }

    else if (turn == 2){
      cout << "Player Two's Turn." << endl;
     takeTurn(player_2_score);
      turn = 1; 
    }
    else{}

    
    cout << "\tPlayer one: "<< player_1_score << endl;
    cout << "\tPlayer two: "<< player_2_score << endl << endl;


    if (player_1_score >= 100){

      cout << "___________________________" << endl; 
      cout << "___________________________" << endl; 
      cout << "Game over! Player one wins." << endl;
     gameOver = true; 
    }

    else if (player_2_score >= 100){
      cout << "___________________________" << endl; 
      cout << "___________________________" << endl; 
      cout << "Game over! Player two wins." << endl;
      gameOver = true; 
   }
    else{} 
  }



  return 0; 
}
