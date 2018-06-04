#include <iostream>

using namespace std;



void changeInt(int* num){
  *num = 12; 
}

int main(){


  int num = 92; 
  int* intPtr;


  intPtr = &num; //set pointer to address of num variable
  cout << "num = " << num << endl;
  cout << "num = " << *intPtr << endl; // the * de-references the pointer
  // this hands us the value at the adress given by intPtr.

  *intPtr = -17; // set the thing at intPtr to -17. The thing at intPtr is num
  cout << "num = " << num << endl; 

  int num2 = 32;
  int* num2Ptr = &num2; 
  cout << "num2 = " << num2 << endl;
  changeInt(num2Ptr);
  cout << "num2 = " << num2 << endl;

  int someArray[3] = {1,2,3};

  cout << *someArray << endl; // this gets address of first element in array and prints its value
  cout << *(someArray +2) << endl;  // this pointer arithmetic adds two int-sized chunks of memory to get to the 3rd element in the array


  return 0;
}
