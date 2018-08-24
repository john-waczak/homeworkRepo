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
  cout << board.attack(2, 3) << endl;  // attacks a square that was already attacked
  cout << board.attack(0,0) << endl; // attacks square with no ship
  Ship ship2("boat2", 10);
  cout << board.placeShip(&ship2, 2, 0, 'R') << endl; 
  cout << board.placeShip(&ship2, 0, 0, 'R') << endl; 
  cout << std::boolalpha << board.allShipsSunk() << endl;
  return 0;
}
