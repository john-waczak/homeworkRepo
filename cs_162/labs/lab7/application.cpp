#include <iostream>
#include <string>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;


void print_shape_info(Shape &s){
  cout << "Name " << s.get_name() << endl;
  cout << "Color: " << s.get_color() << endl;
  cout << "Area: " << s.area() << endl;
}


int main(){

  Rectangle r1 = Rectangle(5.0, 6.0);
  Circle c1 = Circle(1.00);
  cout << (c1<r1) << endl;
  cout << (c1>r1) << endl;

  print_shape_info(c1);
  print_shape_info(r1);
  return 0;
}


