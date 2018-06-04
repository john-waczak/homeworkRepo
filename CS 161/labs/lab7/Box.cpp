#include <iostream>
#include "Box.hpp"

Box::Box(){
  height = 0.00;
  width = 0.00;
  length = 0.00; 
}

Box::Box(double h, double w, double l){

  height = h;
  width = w;
  length = l; 
}

void Box::set_height(double h){
  height = h; 
}
void Box::set_width(double w){
  width = w; 
}
void Box::set_length(double l){
  length = l; 
}


double Box::get_height(){
  return height; 
}

double Box::get_width(){
  return width; 
}

double Box::get_length(){
  return length; 
}


double Box::get_volume(){

  return height*width*length; 
} 

double Box::get_SurfArea(){
  return 2*height*width+2*height*length+2*width*length;
}








 












