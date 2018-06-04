#include <iostream>
#include <string> 
#include "person.hpp"

using std::string; 



Person::Person(string n, double a){
  name = n;
  age = a; 
}


string Person::getName(){
  return name; 
}

double Person::getAge(){
  return age; 
}
