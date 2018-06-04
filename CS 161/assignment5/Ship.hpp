#ifndef SHIP_HPP
#define SHIP_HPP

#include <string>
using std::string;




class Ship{

private:
  string name;
  int length;
  int damage;
public:
  Ship(string, int); 

  string getName();
  int getLength();
  int getDamage();

  void takeHit(); 
};



#endif 
