#include <iostream>


using namespace std;


int main(){


  int ageArray[5] = {12, 11, 10, 11, 12}; 
  char board[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}}; 


  for (int i=0; i<5; i++){
    cout << ageArray[i] << endl; 
  }

  for (int i = 0; i<3; i++){
    for (int j=0; j<3; j++){
      cout << board[i][j] << '\t'; 
    }
    cout << endl; 
  }
  return 0; 
}
