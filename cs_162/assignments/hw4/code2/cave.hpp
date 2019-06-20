#ifndef CAVE_H
#define CAVE_H

#include <iostream>
#include <string>
#include <vector>

#include "room.hpp"
#include "event.hpp"

using std::vector;

class Cave{

private:
  int size;
  vector< vector<Room*>> cave;

  int start_x;
  int start_y;

  int player_x;
  int player_y;

  bool is_player_alive;
  bool has_gold;
  bool has_player_won;

  int num_arrows;

public:
  Cave(int size);
  ~Cave();

  int get_num_arrows();
  bool get_is_player_alive();
  bool get_has_player_won();

  void set_board();
  void set_room(char type);


  void perception_check();

  void print_board_for_cheaters();
  void print_board();
  void print_line();
  void print_empty_row();
  void print_row(int row);


  void player_action();
  void shoot_arrow();
  void cave_encounter();
  void check_for_win();

};


#endif
