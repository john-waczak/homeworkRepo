#include <iostream>

using std::cout;
using std::cin;
using std::endl; 



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
