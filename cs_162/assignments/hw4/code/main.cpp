#include <iostream>
#include <string>
#include <vector>

#include "cave.h"
#include "room.h"
#include "event.h"
#include "wumpus.h"




using namespace std;





int main(){

  Wumpus w = Wumpus();
  Event *ev = &w;
  Cave c(12,12);

  c.print_horizontal_line();
  c.print_empty_row();
  c.print_empty_row();
  c.print_empty_row();
  c.print_horizontal_line();
  return 0;
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
