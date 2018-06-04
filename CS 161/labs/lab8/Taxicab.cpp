#include <iostream>
#include "Taxicab.hpp"

int Taxicab::getX(){
  return x; 
}

int Taxicab::getY(){
  return y; 
}

int Taxicab::getDistanceTraveled(){
  return dist; 
}




Taxicab::Taxicab(){
  x=0;
  y=0;
  dist = 0; 
}

Taxicab::Taxicab(int q1, int q2){
  x = q1;
  y = q2;
  dist = 0; 
}


void Taxicab::moveX(int dx){
  x += dx;
  dist += dx;
}

void Taxicab::moveY(int dy){
  y += dy;
  dist += dy; 
}

