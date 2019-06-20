#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <string>
#include <vector>

#include "event.h"


class Wumpus : public Event{
 private:
  bool is_awake;

 public:
  Wumpus();
  ~Wumpus();


  void wake_up();
  void move();
  void percept();
  void encounter();
};




#endif
