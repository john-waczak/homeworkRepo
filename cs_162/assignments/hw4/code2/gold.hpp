#ifndef GOLD_H
#define GOLD_H


#include "event.hpp"



class Gold : public Event{
public:
  Gold();
  ~Gold(); 
  void percept();
  void encounter();


};



#endif
