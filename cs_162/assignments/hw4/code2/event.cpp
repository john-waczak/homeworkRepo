/******************************************************
 ** Program: event.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description:  implementation file for event class
 ******************************************************/
#include <iostream>
#include <string>
#include "event.hpp"
#include "empty.hpp"

using std::cout;
using std::endl;


Event::Event(char type){
  this->type = type;
}

Event::~Event(){
}
