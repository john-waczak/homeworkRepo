#include <iostream>
#include <string>

#include "shape.h"
#include "rectangle.h"


using namespace std;



Rectangle::Rectangle() : Shape("Rectangle"){
}

Rectangle::Rectangle(float width, float height) : Shape("Rectangle"){
  this->width = width;
  this->height = height;
}

//accessor
float Rectangle::get_width() const{
  return this->width;
}
float Rectangle::get_height() const{
  return this->height;
}

//mutators
void Rectangle::set_width(float new_width){
  this->width = new_width;
}
void Rectangle::set_height(float new_height){
  this->height = new_height;
}

float Rectangle::area(){
  return (this->width)*(this->height);
}
