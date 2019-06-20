#ifndef EVENT_H
#define EVENT_H


class Event{
private:
  char type;
public:
  Event(char type);
  virtual ~Event();
  virtual void percept() = 0;
  virtual void encounter() = 0;
};



#endif

