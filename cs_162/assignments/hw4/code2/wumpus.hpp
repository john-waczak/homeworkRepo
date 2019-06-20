#ifndef WUMPUS_H
#define WUMPUS_H


#include "event.hpp"

class Wumpus : public Event{

public:
  Wumpus();
  ~Wumpus();
  void percept();
  void encounter();

};





#endif
