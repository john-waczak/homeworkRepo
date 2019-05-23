#include <iostream>
#include <string>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;


int main(){

  Shape s1 = Shape("Box", "Blue");
  cout << s1.get_name() << endl;
  cout << s1.get_color() << endl;
  cout << s1.area() << endl;

  Rectangle r1 = Rectangle(5.0, 6.0);
  cout << r1.get_name() << endl;
  cout << r1.get_color() << endl;
  cout << r1.area() << endl;

  Circle c1 = Circle(1.00);
  cout << c1.get_name() << endl;
  cout << c1.get_color() << endl;
  cout << c1.area() << endl;

  Square sq1 = Square(5.0);
  cout << sq1.get_name() << endl;
  cout << sq1.get_color() << endl;
  cout << sq1.area() << endl;

  return 0;
}
