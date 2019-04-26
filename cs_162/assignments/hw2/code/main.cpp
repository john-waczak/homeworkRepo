#include <iostream>
#include <string>
#include <fstream>

#include "pizza.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


int main(int argc, char** argv){


  // demo big three
  string name = "pizza_test";
  int small_cost = 12;
  int medium_cost = 13;
  int large_cost = 14;
  string ingredients[2] = {"pep", "cheese"};

  Pizza pizza1(2);
  pizza1.set_name(name);
  pizza1.set_small_cost(small_cost);
  pizza1.set_medium_cost(medium_cost);
  pizza1.set_large_cost(large_cost);
  for(int i=0; i<pizza1.get_num_ingredients(); i++){
    pizza1.set_ingredient(i, ingredients[i]);
  }

  cout  << pizza1.get_name() << endl;
  Pizza pizza2 = pizza1;
  cout  << pizza2.get_name() << endl;
  Pizza pizza3;
  pizza3 = pizza1;
  return 0;
}
