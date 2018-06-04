#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;




double fallDistance(double fallTime){
  return 0.5*9.81*fallTime*fallTime;
    }

int numVowels(string word){

  int numLetters = word.length();
  int numVowels = 0; 
  for (int i =0; i<numLetters; i++){
    char letter = word.at(i); 
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
      numVowels ++; 
    }
    else if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U'){
      numVowels ++; 
    }
  }

  return numVowels; 
}


int hailstone(int num){
  int numSteps = 0;
  int currentVal = num;
  cout << "Beginning hailstone." << endl; 

  if (num == 1){
    return 0; 
  }
  else {
    while (currentVal != 1){
      cout << "\t" << currentVal << endl; 
      if(currentVal%2==0){
        currentVal = currentVal / 2; 
      }
      else{
        currentVal = 3*currentVal + 1; 
      }
      numSteps ++; 
    }
    return numSteps; 
  }
}




int main(){

  cout << "The distance travelled after a 3.0 second fall is: " << fallDistance(3.0) << endl; 
  cout << "The number of vowels in Oregon is: " << numVowels("Oregon") << endl;  

  int steps = hailstone(3); 
  cout << "It took " << steps << " steps." << endl; 
  return 0; 
}
