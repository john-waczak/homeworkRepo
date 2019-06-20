#include <iostream>
#include <string>
#include <vector>
#include "cave.h"
#include "room.h"
#include "event.h"

Cave::Cave(int nrows, int ncols){
  this->nrows = nrows;
  this->ncols = ncols;

  // loop through and resize
  this->rooms.resize(ncols);
  for(int i=0; i < ncols; i++){
    this->rooms[i].resize(nrows);
  }
}


Cave::~Cave(){
}


// void Cave::print_caves(int player_row, int player_col){
//   for(int i=0; i < this->nrows; i++){
//     for(int j=0; j < this->ncols; j++){
//       if(this->rooms[i][j].get_event() != NULL){
//         cout << " " << this->rooms[i][j].get_event()->get_mark() << " "; 
//       }
//     }
//     cout << endl;
//   }
// }


void Cave::print_horizontal_line(){
  cout << "+";
  for(int i=0; i<this->ncols; i++){
    cout << "---+";
  }
  cout << endl;
}

void Cave::print_empty_row(){
  cout << "|";
  for(int i=0; i<this->ncols; i++){
    cout << "   |";
  }
  cout << endl;
}


// +---+---+---+---+
// |   |   |   |   |
// |   |   |   |   |
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// |   |   |   |   |
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// |   |   | * |   |
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// |   |   |   |   |
// |   |   |   |   |
// +---+---+---+---+
