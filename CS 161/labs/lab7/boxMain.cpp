#include <iostream>
#include "Box.hpp"
using namespace std;


int main(){
  Box box1(2.4, 7.1, 5.0);
  Box box2;
  double volume1 = box1.get_volume();
  double surfaceArea1 = box1.get_SurfArea();
  double volume2 = box2.get_volume();
  double surfaceArea2 = box2.get_SurfArea();

  cout << volume1 << endl;
  cout << surfaceArea1 << endl;
  cout << volume2 << endl;
  cout << surfaceArea2 << endl; 
  return 0; 
}
