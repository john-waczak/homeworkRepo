/**********************************************
John Waczak
6/5/2018

Program to take array and replace with one
twice as long with original values followed
by those values plus one
**********************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl; 


/*********************************************
Function takes referce of pointer to dynamic
array and replaces array with one twice as
long following specifactions in above
comment.
*********************************************/
void transformArray(int* &intArray, int size){
  int* newArray = new int[size*2];
  for (int i = 0; i<size*2; i++){
    if (i < size){
      newArray[i] = intArray[i]; 
    }
    else if (size <= i && i < size*2){
      newArray[i] = intArray[i-size]+1;
    }
  }

  delete[] intArray;
  intArray = newArray; 
}


// int main(){
//   int* myArray = new int[3];
//   myArray[0] = 4;
//   myArray[1] = 2;
//   myArray[2] = 5;

//   transformArray(myArray, 3);
//   for (int i=0; i<6; i++)
//     cout << myArray[i] << endl;

//   delete []myArray;


// }
