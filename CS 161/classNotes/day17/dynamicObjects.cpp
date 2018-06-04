#include <iostream>
#include "classes.hpp"

using namespace std;

int main(){
  Circle circ1 = Circle();
  Circle circ2 = Circle(1.25);
  Circle circ3 = Circle(10.0); 

  Circle* circ1Ptr = &circ1;

  cout << "the tricky way to get area " << (*circ1Ptr).calcArea() << endl; 
  // now if we want to access members of circ1 we need to dereference and access member
  cout << "Circ1 area = " << circ1Ptr->calcArea() << endl; 

  Circle* circPtrArray[3] = {&circ1, &circ2, &circ3};
  for (int i=0; i<3; i++){
    cout << "circ" << i+1 << " area = " << circPtrArray[i]->calcArea() << endl; 
  }
}
