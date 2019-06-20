/******************************************************
 ** Program: cave.cpp
 ** Author: John Waczak
 ** Date: 05/15/2019
 ** Description: functions for cave class
 ******************************************************/
#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h> // rand, srand
#include <stdio.h> // getchar();


#include "event.hpp"
#include "room.hpp"
#include "cave.hpp"

#include "wumpus.hpp"
#include "gold.hpp"
#include "bat.hpp"
#include "pit.hpp"
#include "empty.hpp"


using std::vector;
using std::cout;
using std::endl;
using std::cin;


// constructor
Cave::Cave(int size){
  this->is_player_alive = true;
  this->has_player_won = false;
  this->has_gold = false;
  this->num_arrows = 3;

  this->size = size;
  // make each room a new room
  for(int i = 0; i < size; i ++){
    vector<Room*> row;
    for(int j=0; j < size; j++){
      // add a new room to the row
      row.push_back(new Room);
    }
    this->cave.push_back(row);
  }
}


// hokey destructor
Cave::~Cave(){
  // really hokey way to deallocate the memory
  for(int i=0; i<this->size; i++){
    while(!this->cave[i].empty()){
      delete this->cave[i].back();
      this->cave[i].pop_back();
    }
  }
  this->cave.clear(); // we still have a vector left, this should set it to size zero 
}



// getters
int Cave::get_num_arrows(){
  return this->num_arrows;
}

bool Cave::get_is_player_alive(){
  return this->is_player_alive;
}

bool Cave::get_has_player_won(){
  return this->has_player_won;
}


// initialize the game board and randomly place events
void Cave::set_board(){
  // set wumpus, gold, 2 bats, 2 pits
  this->set_room('W');
  this->set_room('G');
  this->set_room('B');
  this->set_room('B');
  this->set_room('P');
  this->set_room('P');

  // set player initial position / escape rope
  this->set_room('U');

}



// randomly select position for a room. Treat player separately
void Cave::set_room(char type){
  int x, y;
  bool picked = false;
  while(!picked){
    // select random position. NOTE we must mod out by cave size
    x = rand()%this->size;
    y = rand()%this->size;
    if(this->cave[y][x]->get_type()==' '){
      picked = true;
    }
  }

  //NOTE always set the player's postion last because we don't have a class for escape rope
  cout << y << " " << x << endl;
  if (type=='U'){
    this->start_x = x;
    this->start_y = y;
    this->player_x = x;
    this->player_y = y;
  }
  else{
    this->cave[y][x]->set_event(type);
  }

}



// check for nearby rooms with events in them 
void Cave::perception_check(){
  // we must check for 4 boundaries

  // NOTE: do not use else ifs because all could happen at once if you're surrounded
  if((this->player_x+1)<this->size && (this->cave[this->player_y][this->player_x+1]->get_type()!=' ')){
    this->cave[this->player_y][this->player_x+1]->percept();
  }

  if((this->player_y+1)<this->size && (this->cave[this->player_y+1][this->player_x]->get_type()!=' ')){
    this->cave[this->player_y+1][this->player_x]->percept();
  }

  if((this->player_x-1)>0 && (this->cave[this->player_y][this->player_x-1]->get_type()!=' ')){
    this->cave[this->player_y][this->player_x-1]->percept();
  }

  if((this->player_y-1) > 0 && (this->cave[this->player_y-1][this->player_x]->get_type()!=' ')){
    this->cave[this->player_y-1][this->player_x]->percept();
  }
}



// print top line of map
void Cave::print_line(){
  cout << "+";
  for(int i=0; i<this->size; i++){
    cout << "---+"; 
  }
  cout << endl;
}

// print empty row in map
void Cave::print_empty_row(){
  cout << "|";
  for(int i=0; i<this->size; i++){
    cout << "   |";
  }
  cout << endl;
}


// print row with markers
void Cave::print_row(int i){
  cout << "|";
  for(int j=0; j<this->size; j++){
    if(i==this->player_y && j== this->player_x){
      cout <<  " * |";
    }
    else if(i==this->start_y && j== this->start_x){
      cout <<  " ~ |";
    }
    else{
      cout << " " << this->cave[i][j]->get_type() << " |";
    }
  }
  cout << endl;
}



// print the entire boards with markers for events and positions
void Cave::print_board_for_cheaters(){
  print_line();
  for(int i=0; i<this->size; i++){
    print_empty_row();
    print_row(i);
    print_empty_row();
    print_line();
  }
}


// allow player to move or shoot arrow 
void Cave::player_action(){
  char in;
  bool valid_input = false;
  while(!valid_input){
    in = getchar();
    if((in == 'w' && (this->player_y>0)) ||
       (in =='a' && (this->player_x>0)) ||
       (in=='s'&& (this->player_y<this->size-1)) ||
       (in=='d' && (this->player_x < this->size-1)) ||
       in==' '){
      valid_input = true;
    }
    else{
      cout << "Invalid input! Try again: w (north), a (west), s (south), d (east, space (shoot arrow)" << endl;
    }
    getchar();
  }

  switch(in){
  case 'w':
    this->player_y-- ;
    break;
  case 'a':
    this->player_x--;
    break;
  case 's':
    this->player_y++;
    break;
  case 'd':
    this->player_x++;
    break;
  case ' ':
    this->shoot_arrow();
    break;
  }
}



// have player shoot arrow
void Cave::shoot_arrow(){
  cout << "Pick a direction" << endl;
  char in;
  bool valid_input = false;
  while(!valid_input){
    in = getchar();
    if((in == 'w' && (this->player_y>0)) ||
       (in =='a' && (this->player_x>0)) ||
       (in=='s'&& (this->player_y<this->size-1)) ||
       (in=='d' && (this->player_x < this->size-1))){
      valid_input = true;
    }
    else{
      cout << "Invalid input! Try again: w (north), a (west), s (south), d (east, space (shoot arrow)" << endl;
    }
    getchar();
  }

  bool hit = false;

  switch(in){
  case 'w':
    for(int i=this->player_y; i >= this->player_y-3; i--){
      if(i>0){
        if(this->cave[i][this->player_x]->get_type() == 'W'){
          hit = true;
          cout << "You hear a \"Yaaaaarggggg\" followed by silence." << endl;
          this->cave[i][this->player_x]->set_event(' ');
        }
      }
    }
    break;

  case 'a':
    for(int i=this->player_x; i >= this->player_x-3; i--){
      if(i>0){
        if(this->cave[this->player_y][i]->get_type() == 'W'){
          hit = true;
          cout << "You hear a \"Yaaaaarggggg\" followed by silence." << endl;
          this->cave[this->player_y][i]->set_event(' ');
        }
      }
    }
    break;
  case 's':
    for(int i=this->player_y; i<= this->player_y+3; i++){
      if(i<this->size){
        if(this->cave[i][this->player_x]->get_type() == 'W'){
          hit = true;
          cout << "You hear a \"Yaaaaarggggg\" followed by silence." << endl;
          this->cave[i][this->player_x]->set_event(' ');
        }
      }
    }
    break;
  case 'd':
    for(int i=this->player_x; i<= this->player_x+3; i++){
      if(i<this->size){
        if(this->cave[this->player_y][i]->get_type()=='W'){
          hit = true;
          cout << "You hear a \"Yaaaaarggggg\" followed by silence." << endl;
          this->cave[this->player_y][i]->set_event(' ');
        }
      }
    }
    break;
  }


  if(!hit){
    int x = rand()%100+1;
    bool awake_wumpus = (x<75);
    if(awake_wumpus){
      for(int i=0; i<this->size; i++){
        for(int j=0; j<this->size; j++){
          if(this->cave[i][j]->get_type()=='W'){
            this->cave[i][j]->set_event(' ');
            // move the wumpus
            bool has_moved = false;
            int new_x;
            int new_y;
            while(!has_moved){
              new_x = rand()%this->size;
              new_y = rand()%this->size;
              if(this->cave[new_y][new_x]->get_type()==' '){
                has_moved = true;
              }
            }
            this->cave[new_y][new_x]->set_event('W');
          }
        }
      }
    }
  }

  this->num_arrows --;
}



// player encoutners for non emepty room
// NOTE: I didn't end up using the encoutner function for the event class.
void Cave::cave_encounter(){
  char type = this->cave[this->player_y][this->player_x]->get_type();
  switch(type){
  case 'W':
    cout << "The wumpus awakens. It eats you!!!" << endl;
    this->is_player_alive = false;
    break;
  case 'G':
    cout << "You find the treasure!.. If only you could remember how you got here." <<endl;
    this->has_gold = true;
    this->cave[this->player_y][this->player_x]->set_event(' ');
    break;
  case 'P':
    cout << "You slip and fall into a bottomless pit. You die."<<endl;
      this->is_player_alive = false;
    break;
  case 'B':
    cout << "You stumble into the nest of a Super bat. It picks you up and flies you off to another room." << endl;
    this->player_x = rand()%this->size;
    this->player_y = rand()%this->size;
    break;
  case ' ':
    break;
  }

}



// check if the win condition has been meet
void Cave::check_for_win(){
  if(this->player_x == this->start_x &&
     this->player_y == this->start_y){
    if(this->has_gold == true){
      this->has_player_won = true;
    }
  }
}
