/**************************************************
  John Waczak
  6/5/2018

  implementation file for BBoard class
**************************************************/





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


/***************************************************
  function that takes pointer to ship, coordinates
  closest to (0,0) and orientation 'C' for column
  'R' for row and attmepts to place the ship there
***************************************************/
bool BBoard::placeShip(Ship* newShip, int i, int j, char Orientation){
  // make sure we chose a position on the board in
  if (i > 9 || j > 9){
    return false;
  }


  if (Orientation == 'C'){
    //ship too tall
    if ((i + newShip->getLength())>10){
      return false;
    }

    else{

      // first check for interection w/other ships
      for (int y = i; y<newShip->getLength()+i; y++){
        if (getShipsArrayElement(y,j) != NULL){
          return false; 
        }
      }
      // add newShip's address to shipArray
      for (int y =i; y< newShip->getLength()+i; y++){
        shipsArray[y][j] = newShip;
      }
      // add one tober of ships
      // unsunk on the board
      shipsUnsunk++;
      return true;
    }

  }

  else if (Orientation == 'R'){
    // ship too wide
    if ((j+newShip->getLength())>10){
      return false;
    }

    else{
      // first check for interection w/other ships
      for (int x = j; x<newShip->getLength()+j; x++){
        if (getShipsArrayElement(i,x) != NULL){
          return false; 
        }
      }

      // add newShip's address to shipArray
      for (int x = j; x<newShip->getLength()+j; x++){
        shipsArray[i][x] = newShip;
      }
      // add one t ototal number of shipsUnsunk
      // unsunk on the board
      shipsUnsunk++; 
      return true;
    }
  }
 
  // if not 'C' or 'R' then it's not a valid orientation
  else{
    return false; 
  }
}


/*********************************************************
Function to attack the position (i, j) on the board
*********************************************************/
bool BBoard::attack(int i, int j){
  Ship* ship =  getShipsArrayElement(i, j);
  // if the attack is not a hit, reccord attack
  // in the bool array and return false
  //  cout << "ship length: " << ship->getLength() << endl;
  //  cout << "ship damage: " << ship->getDamage() << endl; 
  if (ship== NULL){
    attacksArray[i][j] = true; 
    return false;
  }

  else{
    // if is not sunk, take a hit!
    if (ship->getLength() != ship->getDamage()){
      if (getAttacksArrayElement(i,j)== false){
        attacksArray[i][j] = true;
        ship->takeHit();
      }

      // condition for ship being sunk 
      if (ship->getLength() == ship->getDamage()){
        cout << "They sank " << ship->getName() << "!" << endl;
        shipsUnsunk --; 
      }

      return true;
    }

    // you've already sunk that ship! 
    else if (ship->getLength() == ship->getDamage()){
      return false;
    }

    // in case something crazy happens 
    else{
      return false; 
    }
  }
}

/***************************************************
  Function to check if all ships on bord have benn
  sunk 
****************************************************/
bool BBoard::allShipsSunk(){
  if (getNumShipsRemaining() == 0){
    return true; 
  }

  else {
    return false; 
  }
}
