#ifndef CAVE_H
#define CAVE_H

#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include "room.h"


using std::vector;
using std::cout;
using std::endl;


class Cave{

 private:
  int nrows;
  int ncols;
  vector<vector<Room>> rooms;
 public:
  Cave(int nrows, int ncols);
  ~Cave();



  void update_room();


  void print_horizontal_line();
  void print_empty_row();
  void print_row_with_mark(int row_num);

};


#endif
