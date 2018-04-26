/********************************************************************* 
  ** Author: John Waczak
  ** Date: 4/25/2018
  ** Description: Program that allows user to input a number of integers
  ** and returns the max and min of that set. 
  *********************************************************************/


#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
  int max, min, numInts;

  cout << "Enter desired number of integers." << endl;
  cin >> numInts;

  max = 0;
  min = 0;

  for(int i = 0; i < numInts; i++)
  {
    int integer;
    cout << "Please enter a number." << endl;
    cin >> integer;

    // if it's the first time through set both to first input 
    if (i == 0){
      min = integer;
      max = integer; 
    }


    if (integer > max)
      max = integer;
    else if (integer < min)
      min = integer;
    else
      continue;  // don't do anyting if the entered number is between max and min 
  }

  cout << "Max: " << max << " Min: " << min << endl; 

  return 0; 
}
