/*********************************************************************
 ** Program Filename: wumpus.cpp
 ** Author: John Waczak
 ** Date: 05/26/2019
 ** Description: wumpus class driver file
 *********************************************************************/

#include <iostream>
#include <string>

#include "event.hpp"
#include "wumpus.hpp"

using std::cout;
using std::endl;

Wumpus::Wumpus() : Event('W'){
}

Wumpus::~Wumpus(){
}


void Wumpus::percept(){
  cout << "You smell a terrible stench" << endl;
}


void Wumpus::encounter(){}


