#include <iostream>
#include <string>
#include <fstream>

#include "pizza_portal.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, char** argv){


  ifstream menu_file;
  menu_file.open("menu.txt");
  if(!menu_file.is_open()){
    cout << "Coulden't open file" << endl;
    menu_file.close();
    return 1;
  }

  int num_pizzas = get_num_lines(menu_file);
  Pizza* menu = create_menu(num_pizzas);
  set_menu_from_file(menu, num_pizzas, menu_file);

  for(int i=0; i<num_pizzas; i++){
    cout << menu[i].get_name() << "  " << menu[i].get_num_ingredients()  << "  " << menu[i].get_ingredients()[0]<< endl;
  }




  // demo big three
  string name = "pizza";
  int small_cost = 12;
  int medium_cost = 13;
  int large_cost = 14;
  int num_ingredients = 2;
  string ingredients[2] = {"pep", "cheese"}; 

  Pizza pizza1;
  pizza1.set_name(name);
  pizza1.set_small_cost(small_cost);
  pizza1.set_medium_cost(medium_cost);
  pizza1.set_large_cost(large_cost);
  pizza1.set_num_ingredients(num_ingredients);
  pizza1.set_ingredients(ingredients);

  Pizza pizza2 = Pizza(pizza1);
  Pizza pizza3;
  pizza3 = pizza1; 


  cout << pizza2.get_name() << endl;
  cout << pizza3.get_name() << endl;


  delete [] menu;
  menu_file.close();
  return 0;
}
