

#include <iostream>
#include "classes.hpp"

using namespace std; 


int main() {
  
  Circle c1;
  Circle c2 = Circle(10.0); 


  Car car1;
  Car car2 = Car(1999, "Toyota Brown-Cow", 25); 
  cout << c1.calcArea() << endl;
  cout << c2.calcArea() << endl;
  cout << car1.get_speed() << endl;
  car2.accelerate();
  cout << car2.get_speed() << endl; 
  return 0; 
}
 
 
