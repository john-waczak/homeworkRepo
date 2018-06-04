#include "classes.hpp"


Circle::Circle(){
  radius = 1.0;
}

Circle::Circle(double radiusIn){
  radius = radiusIn; 
}

double Circle::calcArea(){
  return 3.14159*radius*radius;
}

double Circle::calcPerimiter(){
  return 3.14159*2.0*radius; 
}

Car::Car(){
  year = 1994;
  make = "BMW 325 is";
  speed = 25; 
}

Car::Car(int y, std::string m, int s){
  year = y;
  make = m;
  speed = s; 
}


void Car::accelerate(){
  speed += 5; 
}

void Car::deccelerate(){
  speed -= 5;
}

int Car::get_speed(){

  return speed; 
}


void Car::set_speed(int s){
  speed = s; 
}
