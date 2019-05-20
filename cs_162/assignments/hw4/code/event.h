#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>

class Event{

 private:
  char type;

 public:
  Event(char type);

  virtual void percept() = 0;
  virtual void encounter() = 0;
};


class Bottomless_pit : Event{
 public:
  Bottomless_pit();
  void percept();
  void encounter();
};

class Super_bats : Event{
 public:
  Super_bats();
  void percept();
  void encounter();
};

class Gold_teasure : Event{
 public:
  Gold_teasure();
  void percept();
  void encounter();
};



#endif
