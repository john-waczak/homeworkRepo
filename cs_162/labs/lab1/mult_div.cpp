#include <iostream>
#include <string>
#include "mult_div.h"

using std::cout;
using std::cin;
using std::endl;


void were_dimensions_specified(int num_args){
  if (num_args != 3){
    cout << "Could not find row and column numbers" << endl;
    cout << "Expected usage: ./lab1 <num rows> <num columns>"<< endl;
    exit(1);
  }
}


struct mult_div_values{
  int mult;
  float div;
};


bool is_valid_dimensions(char* m, char* n){
  int rows = atoi(m);
  int cols = atoi(n);
  if (rows>=1 && cols>=1){
    return true;
  }
  else if (rows<1){
    cout << "You did not input a valid row." << endl;
    cout << "Please enter an integer greater than 0 for a row: ";
    cin >> *m;
    return is_valid_dimensions(m , n);
  }
  else if (cols<1){
    cout << "You did not input a valid column." << endl;
    cout << "Please enter an integer greater than 0 for a column: ";
    cin >> *n;
    return is_valid_dimensions(m, n);
  }
  else{
    return false;
  }
}


mult_div_values** create_table(int m, int n){
  mult_div_values** table = new mult_div_values*[m];
  for(int i=0; i<m; i++){
    table[i] = new mult_div_values[n];
  }
  return table;
}



void set_mult_values(mult_div_values** table, int m, int n){
  for (int i = 0; i<m; i++){
    for (int j=0; j<n; j++){
      table[i][j].mult = (i+1)*(j+1);
    }
  }
}


void set_div_values(mult_div_values** table, int m, int n){
  for (int i = 0; i<m; i++){
    for (int j=0; j<n; j++){
      table[i][j].div = float(i+1)/float(j+1);
    }
  }
}

void delete_table(mult_div_values** table, int m){
  for (int i=0; i<m; i++){
    delete [] table[i];
  }
  delete [] table;
}

void print_table(mult_div_values** table, int m, int n){
  cout << "Multiplication Table: " << endl;
  for (int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("   %i   ", table[i][j].mult);
    }
    cout << endl;
  }
  cout << "Division Table: " << endl;
  for (int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("   %.3f   ", table[i][j].div);
    }
    cout << endl;
  }
}




