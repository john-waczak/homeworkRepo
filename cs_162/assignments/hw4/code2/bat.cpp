/******************************************************
 ** Program: bat.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description:  implementation file for bat class
 ******************************************************/


#include <iostream>
#include <string>
#include "event.hpp"
#include "bat.hpp"


using std::cout;
using std::endl;

Bat::Bat() : Event('B'){
}

Bat::~Bat(){
}


void Bat::percept(){
  cout << "You hear wings flapping." << endl;
}


void Bat::encounter(){}
