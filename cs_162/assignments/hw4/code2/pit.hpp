#ifndef PIT_H
#define PIT_H


#include "event.hpp"



class Pit : public Event{
public:
  Pit();
  ~Pit();
  void percept();
  void encounter();


};



#endif
