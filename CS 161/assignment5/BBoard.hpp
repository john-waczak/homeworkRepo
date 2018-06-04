#ifndef BBOARD_HPP
#define BBOARD_HPP

#include "Ship.hpp"


class BBoard{

private:
  bool attacksArray[10][10];
  Ship* shipsArray[10][10];
  int shipsUnsunk;


public:
  BBoard();
  bool getAttacksArrayElement(int, int);
  Ship* getShipsArrayElement(int, int);
  int getNumShipsRemaining();
  bool placeShip(Ship*, int, int, char);
  bool attack(int, int);
  bool allShipsSunk(); 


};



#endif 
