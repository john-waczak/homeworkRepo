#ifndef ROOM_H
#define ROOM_H

#include "event.hpp"
#include "wumpus.hpp"
#include "gold.hpp"
#include "bat.hpp"
#include "pit.hpp"
#include "empty.hpp"


class Room{

private:
  char type;
  bool is_player_in_room;
  Event* evntptr;

public:
  Room();
  ~Room();

  // getters
  char get_type();
  bool get_is_player_in_room();

  //setters
  void set_is_player_in_room(bool p);
  void set_event(char type);


  void percept();


};



#endif
