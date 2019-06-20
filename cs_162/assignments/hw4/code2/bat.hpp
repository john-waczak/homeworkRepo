#ifndef BAT_H
#define BAT_H


#include "event.hpp"



class Bat : public Event{
public:
  Bat();
  ~Bat();
  void percept();
  void encounter();


};



#endif
