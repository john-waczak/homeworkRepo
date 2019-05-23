#ifndef PIZZA_PORTAL_H
#define PIZZA_PORTAL_H

#include <iostream>
using std::string;
using std::ifstream;
using std::ofstream;


class Pizza{
 private:
  string name;
  int small_cost;
  int medium_cost;
  int large_cost;
  int num_ingredients;
  string* ingredients;
 public:

  // constructor
  Pizza();

  // big three
  ~Pizza(); //destructor
  Pizza(const Pizza &old_pizza); // copy constructor
  Pizza& operator=(const Pizza& old_pizza); //assignment
  // accessors
  string get_name() const;
  int get_small_cost() const;
  int get_medium_cost() const;
  int get_large_cost() const;
  int get_num_ingredients() const;
  string* get_ingredients() const;

  // mutators
  void set_name(string name);
  void set_small_cost(int small_cost);
  void set_medium_cost(int medium_cost);
  void set_large_cost(int large_cost);
  void set_num_ingredients(int num_ingredients);
  void set_ingredients(string* ingredients);

};




/**** non-class functions *********/

Pizza* create_menu(int num_pizzas);
void set_menu_from_file(Pizza* menu, int num_pizzas, ifstream &menu_file);
int get_num_lines(ifstream &file);
#endif
