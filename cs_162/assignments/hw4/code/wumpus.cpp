#include <iostream>
#include <string>
#include <vector>

#include "event.h"
#include "wumpus.h"

using std::cout;
using std::endl;


Wumpus::Wumpus() : Event('w'){
  this->is_awake = false;
}

Wumpus::~Wumpus(){
}


void Wumpus::wake_up(){
  this->is_awake = 0;
}

void move();

void Wumpus::percept(){
  cout << "You smell a terrible stench" << endl;
}
void Wumpus::encounter(){
  cout << "Wumpus encounter" << endl;
}
