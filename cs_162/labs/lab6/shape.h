#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using std::string;


class Shape {
 private:
  string name;
  string color;

 public:

  // constructors
  Shape();
  Shape(string name);
  Shape(string name, string color);




  // getters
  string get_name() const;
  string get_color() const;

  // setters
  void set_name(string new_name);
  void set_color(string new_color);


  // other member functions
  virtual float area() = 0;
};

#endif
