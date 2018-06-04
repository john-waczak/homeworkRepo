#include <iostream>
using namespace std;


int main(){
  double* arrayPtr;
  int size = 10;

  double arr[10]; // regular old array
  arrayPtr = arr; // make arrayPtr point to arr
  arrayPtr[3] = 7; // set 4th element to 7
  cout << "arr[3] =" << arr[3] << endl; 

  
  return 0; 
}
