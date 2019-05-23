#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <fstream>
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
  Pizza(int num_ingredients);

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
  string get_ingredient(int index) const;

  // mutators
  void set_name(string name);
  void set_small_cost(int small_cost);
  void set_medium_cost(int medium_cost);
  void set_large_cost(int large_cost);
  void set_num_ingredients(int num_ingredients);
  void set_ingredient(int index, string ingredient);

  bool does_pizza_have_ingredient(string ingredient);

};

#endif

