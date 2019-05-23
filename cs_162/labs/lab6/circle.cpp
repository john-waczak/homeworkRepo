#include <iostream>
#include <string>

#include "shape.h"
#include "circle.h"


using namespace std;



Circle::Circle() : Shape("Circle"){
}

Circle::Circle(float radius) : Shape("Circle"){
  this->radius = radius;
}

//accessor
float Circle::get_radius() const{
  return this->radius;
}

//mutators
void Circle::set_radius(float new_radius){
  this->radius = new_radius;
}


float Circle::area(){
  return (this->radius)*(this->radius)*3.14159;
}
