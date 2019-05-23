/******************************************************
 ** Program: animal.cpp
 ** Author: John Waczak
 ** Date: 05/12/2019
 ** Description: Implementation of animal class and
 **              derived classes. 
 ******************************************************/

#include <iostream>
#include <string>

#include "animal.h"


using namespace std;


// constructors

Animal::Animal(){
  this->species = "";
  this->age_in_weeks = 0;
  this->is_baby = true;
  this->is_adult = false;
  this->cost = 0;
  this->litter_size = 0;
  this->food_cost_multiplier = 0;
  this->revenue = 0;
}



Animal::Animal( string species,
                int age_in_weeks,
                int cost,
                int litter_size,
                int food_cost_multiplier,
                int revenue){
  this->species = species;
  this->age_in_weeks = age_in_weeks;
  
  if(age_in_weeks < 5){
    this->is_baby = true;
    this->is_adult = false;
  }
  else if (age_in_weeks >= 52*2){
    this->is_baby = false;
    this->is_adult = true;
  }
  else{
    this->is_baby = false;
    this->is_adult = false;
  }


  this->cost = cost;
  this->litter_size = litter_size;
  this->food_cost_multiplier = food_cost_multiplier;
  this->revenue = revenue;
}



// big three
Animal::~Animal(){
}




Animal::Animal(const Animal &old_animal){
  cout << "copy constructor called" << endl;
  this->species = old_animal.species;
  this->age_in_weeks = old_animal.age_in_weeks;
  this->is_baby = old_animal.is_baby;
  this->cost = old_animal.cost;
  this->litter_size = old_animal.litter_size;
  this->food_cost_multiplier = old_animal.food_cost_multiplier;
  this->revenue = old_animal.revenue;
}



Animal& Animal::operator=(const Animal& old_animal){
  this->species = old_animal.species;
  this->age_in_weeks = old_animal.age_in_weeks;
  this->is_baby = old_animal.is_baby;
  this->is_adult = old_animal.is_adult;
  this->cost = old_animal.cost;
  this->litter_size = old_animal.litter_size;
  this->food_cost_multiplier = old_animal.food_cost_multiplier;
  this->revenue = old_animal.revenue;
  return *this;
}




// accessors
string Animal::get_species() const{
  return this->species;
}
int Animal::get_age_in_weeks() const{
  return this->age_in_weeks;
}
bool Animal::get_is_baby() const{
  return this->is_baby;
}

int Animal::get_cost() const{
  return this->cost;
}
int Animal::get_litter_size() const{
  return this->litter_size;
}
int Animal::get_food_cost_multiplier() const{
  return this->food_cost_multiplier;
}
int Animal::get_revenue() const{
  return this->revenue;
}
bool Animal::get_is_adult() const{
  return this->is_adult;
}

// mutators
void Animal::set_species(string new_species){
  this->species = new_species;
}
void Animal::set_age_in_weeks(int new_age_in_weeks){
  this->age_in_weeks = new_age_in_weeks;
  if(new_age_in_weeks < 5){
    this->is_baby = true;
    this->is_adult = false;
  }
  else if (new_age_in_weeks>2*52){
    this->is_baby = false;
    this->is_adult = true;
  }
  else{
    this->is_baby = false;
    this->is_adult = false;
  }
}
void Animal::set_is_baby(bool new_is_baby){
  this->is_baby = new_is_baby;
}
void Animal::set_cost(int new_cost){
  this->cost = new_cost;
}
void Animal::set_litter_size(int new_litter_size){
  this->litter_size = new_litter_size;
}
void Animal::set_food_cost_multiplier(int new_food_cost_multiplier){
  this->food_cost_multiplier = new_food_cost_multiplier;
}
void Animal::set_revenue(int new_revenue){
  this->revenue = new_revenue;
}
void Animal::set_is_adult(bool new_is_adult){
  this->is_adult = new_is_adult;
}

// derived class constructors

Monkey::Monkey() : Animal( "Monkey",
                           0,
                           15000,
                           1,
                           4,
                           int(0.1*15000)){
}


Monkey::Monkey(int age) : Animal( "Monkey",
                                  age,
                                  15000,
                                  1,
                                  4,
                                  int(0.1*15000)){
}



Sea_otter::Sea_otter() : Animal( "Sea Otter",
                                 0,
                                 5000,
                                 2,
                                 2,
                                 int(0.05*5000)){
}
Sea_otter::Sea_otter(int  age) : Animal( "Sea Otter",
                                         age,
                                         5000,
                                         2,
                                         2,
                                         int(0.05*5000)){
}


Meerkat::Meerkat() : Animal( "Meerkat",
                             0,
                             500,
                             5,
                             1,
                             int(0.05*500)){
}

Meerkat::Meerkat(int  age) : Animal( "Meerkat",
                                     age,
                                     500,
                                     5,
                                     1,
                                     int(0.05*500)){
}








