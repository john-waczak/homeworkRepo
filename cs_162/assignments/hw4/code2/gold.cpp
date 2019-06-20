/*********************************************************************
 ** Program Filename: gold.cpp
 ** Author: John Waczak
 ** Date: 05/26/2019
 ** Description: gold class driver file
 *********************************************************************/


#include <iostream>
#include <string>
#include "event.hpp"
#include "gold.hpp"


using std::cout;
using std::endl;

Gold::Gold() : Event('G'){
}

Gold::~Gold(){
}

void Gold::percept(){
  cout << "You see a glimmer nearby" << endl;
}

void Gold::encounter(){}
