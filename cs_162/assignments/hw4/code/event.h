#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>


class Event{
 private:
  char mark;

 public:
  Event();
  Event(char mark);

  virtual void percept() = 0;
  virtual void encounter() = 0;


  char get_mark() const;
};




#endif
