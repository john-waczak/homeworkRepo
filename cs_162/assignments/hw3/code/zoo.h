/*********************************************************************
 ** Program Filename: zoo.h
 ** Author: John Waczak
 ** Date: 05/12/2019
 ** Description: Header file for zoo class
 *********************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include "animal.h"


class Zoo{
 private:
  int budget;
  int num_monkeys;
  int num_sea_otters;
  int num_meerkats;

  Monkey* monkeys;
  Sea_otter* sea_otters;
  Meerkat* meerkats;

 public:
  // default constructor
  Zoo();

  // destructor
  ~Zoo();


  // accessors
  int get_budget() const;
  int get_num_monkeys() const;
  int get_num_sea_otters() const;
  int get_num_meerkats() const;

  Monkey get_monkey(int index) const;
  Sea_otter get_sea_otter(int index) const;
  Meerkat get_meerkat(int index) const;

  // mutators
  void set_budget(int new_budget);
  void set_num_monkeys(int new_num_monkeys);
  void set_num_sea_otters(int new_num_sea_otters);
  void set_num_meerkats(int new_num_meerkats);

  void set_monkey(int index, Monkey m);
  void set_sea_otter(int index, Sea_otter s);
  void set_meerkat(int index, Meerkat mk);


  // add to lists
  // NOTE: assuming that new animals are added with age 0
  void add_monkey(bool is_adult);
  void add_sea_otter(bool is_adult);
  void add_meerkat(bool is_adult);

  // remove from lists
  void remove_monkey(int index);
  void remove_sea_otter(int index);
  void remove_meerkat(int index);

  int get_number_of_adults();


  void age_all_animals();
  void make_animal_give_birth();
  void make_animal_sick();
  void attendance_boom();
  void get_revenue();
  bool buy_new_animals();
  void buy_food_for_animals();
};


int get_random_int(int max_num);





#endif
