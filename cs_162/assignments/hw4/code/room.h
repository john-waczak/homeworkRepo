#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include "event.h"

class Room{
 private:
  bool is_empty;
  Event *evnt;
 public:
  Room();
  Room(Event *ev);

  // big three
  ~Room();
  Room(const Room &rm);


  // getters
  bool get_is_empty() const;
  Event* get_event();

  // setters
  void set_is_empty(bool new_is_empty);
  void set_event(Event *ev);
};


#endif
