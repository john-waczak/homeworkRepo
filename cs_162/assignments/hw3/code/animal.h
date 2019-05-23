/*********************************************************************
 ** Program Filename: animal.h
 ** Author: John Waczak
 ** Date: 05/12/2019
 ** Description: Header file for animal class
 *********************************************************************/


#ifndef ANIMAL_H
#define ANIMAL_H


#include <iostream>
#include <string>
using std::string;

class Animal{

 private:
  string species;
  int age_in_weeks;
  bool is_baby;
  bool is_adult;
  int cost;
  int litter_size;
  int food_cost_multiplier;
  int revenue;

 public:
  // constructors
  Animal();
  Animal( string species,
          int age_in_weeks,
          int cost,
          int litter_size,
          int food_cost_multiplier,
          int revenue
          );


  // big three
  ~Animal(); //destructor
  Animal(const Animal &old_animal); // copy constructor
  Animal& operator=(const Animal& old_animal);


  // accessors
  string get_species() const;
  int get_age_in_weeks() const;
  bool get_is_baby() const;
  int get_cost() const;
  int get_litter_size() const;
  int get_food_cost_multiplier() const;
  int get_revenue() const;
  bool get_is_adult() const;

  // mutators
  void set_species(string new_species);
  void set_age_in_weeks(int new_age_in_weeks);
  void set_is_baby(bool new_is_baby);
  void set_cost(int new_cost);
  void set_litter_size(int new_litter_size);
  void set_food_cost_multiplier(int new_food_cost_multiplier);
  void set_revenue(int new_revenue);
  void set_is_adult(bool new_is_adult);
};



class Monkey : public Animal{
 public:
  Monkey();
  Monkey(int age);
};

class Sea_otter : public Animal{
 public:
  Sea_otter();
  Sea_otter(int  age);
};

class Meerkat : public Animal{
 public:
  Meerkat();
  Meerkat(int  age);
};

#endif
