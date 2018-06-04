#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;

void smallSort2(int*, int*, int*); 


int main(){
  int a = 14;
  int b = -90;
  int c = 2;
  smallSort2(&a, &b, &c);
  cout << a << ", " << b << ", " << c << endl;

  return 0; 
}


void smallSort2(int* a, int* b, int* c){
  int intArray[3] = {*a, *b, *c};
  std::sort(intArray, intArray+3); 
  *a = intArray[0];
  *b = intArray[1];
  *c = intArray[2]; 


}
