#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <iostream>
#include <string>
#include "shape.h"

class Rectangle : public Shape {
 private:
  float width;
  float height;

 public:
  Rectangle();
  Rectangle(float width, float height);

  //accessor
  float get_width() const;
  float get_height() const;

  //mutators
  void set_width(float new_width);
  void set_height(float new_height);


  float area();





#endif
