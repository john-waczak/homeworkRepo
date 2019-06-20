#include <iostream>
#include <string>
#include <vector>

#include "room.h"
#include "event.h"

using std::cout;
using std::endl;



Room::Room(){
  this->is_empty = true;
  this->evnt = NULL;
}

Room::Room(Event *ev){
  this->is_empty = false;
  this->evnt = ev;
}


// big three

Room::~Room(){
  this->is_empty = true;
  this->evnt = NULL;
}


Room::Room(const Room &rm){
  this->is_empty = rm.is_empty;
  
}


// getters
bool Room::get_is_empty() const{
  return this->is_empty;
}

Event* Room::get_event(){
  return this->evnt;
}



// setters
void Room::set_is_empty(bool new_is_empty){
  this->is_empty = new_is_empty;
}

void Room::set_event(Event *ev){
  this->is_empty = false;
  this->evnt = ev;
}




