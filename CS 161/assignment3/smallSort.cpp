/********************************************************************* 
 ** Author: John Waczak
 ** Date: 5/8/2018
 ** Description: Program illustrating how by-reference functions can
 ** be used to sort data. 
 *********************************************************************/ 



#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/********************************************************************* 
 ** Description: Function that takes three ints by reference and
 ** re-orders them into ascending value. 
 *********************************************************************/ 

void smallSort(int& one, int& two, int& three){
  int temp;

  if (one < two && two < three);

  else if (one < three && three < two){
    temp = two; 
    two = three;
    three = temp; 
  }

  else if (two < one && one < three){
    temp = two;
    two = one;
    one = temp;

  }

  else if (two < three && three < one){
    temp = one; 
    one = two;
    two = three;
    three = temp;
  }

  else if (three < one && one < two){
    temp = two; 
    one = three;
    two = one;
    three = temp; 
  }

  else if (three < two && two < one){
    temp = one; 
    one = three;
    three = temp; 
  }
  
  
  else
    cout << "Something went wrong. Please make sure you enter 3 distinct integers.\n";


}
 int main()
{

  int first = 14;
  int second = -90;
  int third = 2;
  smallSort(first, second, third);
  cout << first << ", " << second << ", " << third << endl;

  return 0; 
}
