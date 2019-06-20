/******************************************************
 ** Program: pit.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description:  implementation file for pit class
 ******************************************************/


#include <iostream>
#include <string>
#include "event.hpp"
#include "pit.hpp"

using std::cout;
using std::endl;

Pit::Pit() : Event('P'){}
Pit::~Pit(){
}


void Pit::percept(){
  cout << "You feel a breeze." << endl;
}

void Pit::encounter(){}
