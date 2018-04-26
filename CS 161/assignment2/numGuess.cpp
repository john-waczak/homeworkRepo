/********************************************************************* 
 ** Author: John Waczak  
 ** Date: 4/25/2018
 ** Description: Simple game in which a user tries to guess the value of
 ** an entered integer. 
 *********************************************************************/ 

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
  int userNum, playerGuess, guessCount;
  cout << "Enter an integer for player to guess." << endl;
  cin >> userNum ;

  bool isCorrect = false;
  guessCount = 0;

  do{
    cout << "Enter a guess." << endl;
    cin >> playerGuess;

    if (playerGuess < userNum){
      cout << "Too low -- try again." << endl; 
    }
    else if (playerGuess > userNum){
      cout << "Too high -- try again." << endl; 
    }
    else{
      isCorrect = true; 
    }

    guessCount ++;

  }while(!isCorrect);

  cout << "Correct! You guessed " << userNum << " in " << guessCount << " tries." << endl; 

  return 0;
}
