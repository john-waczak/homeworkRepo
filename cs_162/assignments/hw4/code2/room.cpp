/*********************************************************************
 ** Program Filename: room.cpp
 ** Author: John Waczak
 ** Date: 05/26/2019
 ** Description: implementation file for room class 
 *********************************************************************/
#include <iostream>
#include <string>

#include "event.hpp"
#include "room.hpp"

#include "wumpus.hpp"
#include "gold.hpp"
#include "bat.hpp"
#include "pit.hpp"
#include "empty.hpp"


using std::cout;
using std::endl;


Room::Room(){
  // default room is empty
  this->type = ' ';
  this->is_player_in_room = false;
  this->evntptr = new Empty; 
}

Room::~Room(){
  delete this->evntptr;
}


char Room::get_type(){
  return this->type;
}

bool Room::get_is_player_in_room(){
  return this->is_player_in_room;
}

void Room::set_is_player_in_room(bool p){
  this->is_player_in_room = p;
}

void Room::set_event(char new_type){
  if(new_type == 'W'){
    this->type = 'W';
    delete this->evntptr; // delete the old one first
    this->evntptr = new Wumpus;
  }
  else if (new_type == 'G'){
    this->type = 'G';
    delete this->evntptr; // delete the old one first
    this->evntptr = new Gold;
  }
  else if (new_type == 'B'){
    this->type = 'B';
    delete this->evntptr; // delete the old one first
    this->evntptr = new Bat;
  }
  else if (new_type == 'P'){
    this->type = 'P';
    delete this->evntptr; // delete the old one first
    this->evntptr = new Pit;
  }
  else{
    this->type= ' ';
    delete this->evntptr; // delete the old one first
    this->evntptr = new Empty;
  }
}

// print percept message from event class 
void Room::percept(){
  this->evntptr->percept();
}
