#include <iostream>
#include <string>
#include "Ship.hpp"
#include "BBoard.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;


/***************************************************
  Default constructor for BBoard Class. 
 **************************************************/
BBoard::BBoard(){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      attacksArray[i][j] = false;
      shipsArray[i][j] = NULL; 
    }
  }

}


/***************************************************
  getter for the attacksArray
***************************************************/
bool BBoard::getAttacksArrayElement(int i, int j){
  return attacksArray[i][j]; 
}


/***************************************************
  getter for shipsArray
***************************************************/
Ship* BBoard::getShipsArrayElement(int i, int j){
  return shipsArray[i][j];
}


/***************************************************
  getter for the number of unsunk ships
***************************************************/
int BBoard::getNumShipsRemaining(){
  return shipsUnsunk;
}


bool BBoard::placeShip(Ship* newShip, int i, int j, char Orientation){

  // make sure we chose a position on the board in
  if (i >> 9 || j >> 10){
    return false;
  }

  if (Orientation == 'C'){
    //ship too tall
    if ((i + newShip->getLength())>10){
      return false;
    }

    else{
      // add newShip's address to shipArray
      for (int y =0; y< newShip->getLength(); y++){
        shipsArray[y][j] = newShip;
      }

      return true;
    }

  }

  else if (Orientation == 'R'){
    // ship too wide
    if ((j+newShip->getLength())>10){
      return false;
    }

    else{
      // add newShip's address to shipArray
      for (int x = 0; x<newShip->getLength(); x++){
        shipsArray[i][x] = newShip;
      }

      return true;
    }
  }

  // if not 'C' or 'R' then it's not a valid orientation
  else{
    return false;
  }
}

bool BBoard::attack(int i, int j){
  return false; 
}


bool BBoard::allShipsSunk(){
  return false; 
}
