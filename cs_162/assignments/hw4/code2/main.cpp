/******************************************************
 ** Program: main.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description:  Driver file for wumpus program
 ******************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "cave.hpp"
#include "room.hpp"

using namespace std;

int main(int argc, char** argv){

  if(argc!=3){
    cout << "Incorrect usage. Try:" << endl;
    cout << "./wumpus <length> <cheat_mode>" << endl;
    return 1;
  }
  int length = atoi(argv[1]);
  string is_cheater = argv[2];
  cout << "You are using cheat mode..." << endl;



  if(length<4){
    cout << "Invalid length entered." << endl;
    return 1;
  }


  srand(0);
  Cave c(length);
  c.set_board();
  while(c.get_is_player_alive()){
    if(c.get_num_arrows()<1){
      cout << "You run out of arrows! You die!" << endl;
      break;
    }

    if(c.get_has_player_won()){
      cout << "You won!" << endl;
      break;
    }
    c.cave_encounter();
    c.perception_check();
    c.print_board_for_cheaters();
    c.player_action();
    c.cave_encounter();
    c.check_for_win();
  }
 return 0;
}
