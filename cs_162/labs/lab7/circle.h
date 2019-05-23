#ifndef CIRCLE_H
#define CIRCLE_H


#include <iostream>
#include <string>
#include "shape.h"

class Circle : public Shape {
 private:
  float radius;
 public:
  Circle();
  Circle(float radius);

  //accessor
  float get_radius() const;

  //mutators
  void set_radius(float new_radius);

  float area();
};





#endif
