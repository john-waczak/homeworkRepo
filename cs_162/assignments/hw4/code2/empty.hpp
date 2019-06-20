#ifndef EMPTY_H
#define EMPTY_H

#include "event.hpp"

class Empty : public Event{
public:
  Empty();
  ~Empty();
  void percept();
  void encounter();
};


#endif
