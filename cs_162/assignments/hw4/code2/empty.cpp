/******************************************************
 ** Program: empty.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description:  implementation file for empty class
 ******************************************************/

#include <iostream>
#include <string>

#include "event.hpp"
#include "empty.hpp"

using std::cout;
using std::endl;

Empty::Empty() : Event(' '){}
Empty::~Empty(){
}


void Empty::percept(){}
void Empty::encounter(){}
