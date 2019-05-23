#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>

#include "pizza.h"


using std::string;
using std::ifstream;
using std::ofstream;



class Menu {
 private:
  int num_pizzas;
  Pizza* pizzas;
 public:

  // constructor
  Menu();
  Menu(int num_pizzas);

  // big three
  ~Menu(); // destructor
  Menu(const Menu &old_menu); //copy constructor
  Menu& operator=(const Menu &old_menu); //assignment overload

  // getters
  int get_num_pizzas() const;
  Pizza get_pizza(int index) const;

  // setters
  void set_num_pizzas(int new_num_pizzas);
  void set_pizza(int index, Pizza new_pizza);


  // other funcions
  Menu search_pizza_by_cost(int upper_bound);
  Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
  Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
  void add_to_menu(Pizza pizza_to_add);
  void remove_from_menu(int index_of_pizza_on_menu);

  void print_menu();

};




#endif
