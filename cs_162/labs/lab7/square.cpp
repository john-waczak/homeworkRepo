#include <iostream>
#include <string>

#include "square.h"

using namespace std;


Square::Square() : Rectangle(0.0, 0.0){
  this->set_name("Square");
};

Square::Square(float side_length) : Rectangle(side_length, side_length){
  this->set_name("Square");
};
