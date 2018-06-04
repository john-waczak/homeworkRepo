#include <iostream>
#include <string>
#include "Ship.hpp"
#include "BBoard.hpp"


using namespace std;


int main()
{
  BBoard board;  // creates BBoard object
  Ship ship1("Boaty McBoatface", 2);  // creates Ship object
  board.placeShip(&ship1, 2, 2, 'R');  // adds the Ship object to the Board object
  cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
  board.attack(2, 2);  // attacks one square the Ship is on
  cout << "damage = " << ship1.getDamage() << endl;  // asks the Ship for its damage
  board.attack(2, 3);  // attacks the other square the Ship is on to sink the Ship
  cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
  board.attack(2, 3);  // attacks a square that was already attacked
  Ship* shipPtr = board.getShipsArrayElement(2, 3);  // gets the address of the Ship on square (2,3)

  return 0;
}
