#include <iostream>
#include <string>

#include "shape.h"

using namespace std;
using std::string;




// constructors
Shape::Shape(){
  this->name = "";
  this->color = "";
}


Shape::Shape(string name){
  this->name = name;
  this->color = "black";
}


Shape::Shape(string name, string color){
  this->name = name;
  this->color = color;
}

// getters
string Shape::get_name() const{
  return this->name;
}

string Shape::get_color() const{
  return this->color;
}

// setters
void Shape::set_name(string new_name){
  this->name = new_name;
}


void Shape::set_color(string new_color){
  this->color =new_color;
}








bool operator>( Shape &s1, Shape &s2){
  cout << s1.area() << " " << s2.area() << endl;
  if(s1.area()>s2.area()){
    cout << "true" << endl;
    return true;
  }
  else{return false;}
}


bool operator<( Shape &s1, Shape &s2){
  cout << s1.area() << " " << s2.area() << endl;
  if(s1.area()<s2.area()){
    cout << "true" << endl;
    return true;
  }
  else{return false;}
}





