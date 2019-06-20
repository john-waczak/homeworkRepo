#include <iostream>
#include <string>
#include <vector>

#include "event.h"


using namespace std;



Event::Event(char mark){
  this->mark = mark;
}

Event::Event(){
  this->mark = ' ';
}



char Event::get_mark() const{
  return this->mark;
}
