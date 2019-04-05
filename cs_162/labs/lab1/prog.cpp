#include <iostream>
#include <string>
#include <stdio.h>
#include "mult_div.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char** argv){
  bool see_table = true;

  were_dimensions_specified(argc);
  char* rows_char = argv[1];
  char* cols_char = argv[2];

  while(see_table){
    bool valid_dimensions = is_valid_dimensions(rows_char, cols_char);
    int rows = atoi(rows_char);
    int cols = atoi(cols_char);

    mult_div_values**  table = create_table(rows, cols);
    set_mult_values(table, rows, cols);
    set_div_values(table, rows, cols);
    print_table(table, rows, cols);
    delete_table(table, rows);

    cout << "Would you like to see a different size matrix (0-no, 1-yes)?"<<endl;
    bool yesNo;
    cin >> yesNo;
    if(yesNo == false){
      see_table = false;
    }
    else{
      cout << "Please enter the number of rows: ";
      cin >> rows_char;
      cout << "Please enter the number of columnds: ";
      cin >> cols_char;
    }

  }
 return 0;
}




