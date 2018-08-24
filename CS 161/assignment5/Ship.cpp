/*********************************
John Waczak
6/3/2018

Implementation file for Ship class
 ********************************/


#include <iostream>
#include <string>
#include "Ship.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************
Constructor that sets name and
length to passed parameters and
starts the damage at 0
 *******************************/
Ship::Ship(string n, int l){
  name = n;
  length = l;
  damage = 0;
}

string Ship::getName(){
  return name; 
}

int Ship::getLength(){
  return length; 
}

int Ship::getDamage(){
  return damage; 
}



/********************************
Function to increase damage when
ship has been hit
********************************/
void Ship::takeHit(){
  damage ++; 
}
