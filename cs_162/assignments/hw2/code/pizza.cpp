/******************************************************
 ** Program: pizza.cpp
 ** Author: John Waczak
 ** Description:  Function definitions for pizza class
 ******************************************************/
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

// default constructors
Pizza::Pizza(){
  this->ingredients = NULL;
};

Pizza::Pizza(int num_ingredients){
  this->num_ingredients = num_ingredients;
  this->ingredients = new string[num_ingredients];
};

/*******Big Three*****************/

// destructor
Pizza::~Pizza(){
  if(this->ingredients != NULL){
    delete [] this->ingredients;
  }
}

// copy constructor
Pizza::Pizza(const Pizza &old_pizza){
  this->name = old_pizza.name;
  this->small_cost = old_pizza.small_cost;
  this->medium_cost = old_pizza.medium_cost;
  this->large_cost = old_pizza.large_cost;
  this->num_ingredients = old_pizza.num_ingredients;
  this->ingredients = new string[this->num_ingredients];

  for(int i=0; i<old_pizza.num_ingredients; i++){
    this->ingredients[i] = old_pizza.ingredients[i];
  }
}

// assignment operator
Pizza& Pizza::operator=(const Pizza &old_pizza){
  if(this != &old_pizza){
    delete [] this->ingredients;
    this->name = old_pizza.name;
    this->small_cost = old_pizza.small_cost;
    this->medium_cost = old_pizza.medium_cost;
    this->large_cost = old_pizza.large_cost;
    this->num_ingredients = old_pizza.num_ingredients;
    // deep copy
    this->ingredients = new string[this->num_ingredients];
    for(int i=0; i<old_pizza.num_ingredients; i++){
      this->ingredients[i] = old_pizza.ingredients[i];
    }

  }

  return *this;
}





/*********getters***************/
string Pizza::get_name() const{
  return this->name;
}
int Pizza::get_small_cost() const{
  return this->small_cost;
}
int Pizza::get_medium_cost() const{
  return this->medium_cost;
}
int Pizza::get_large_cost() const{
  return this->large_cost;
}
int Pizza::get_num_ingredients() const{
  return this->num_ingredients;
}

string Pizza::get_ingredient(int index) const{
  return this->ingredients[index];
}



/***********setters****************/
void Pizza::set_name(string name){
  this->name = name;
}

void Pizza::set_small_cost(int small_cost){
  this->small_cost = small_cost;
}

void Pizza::set_medium_cost(int medium_cost){
  this->medium_cost = medium_cost;
}
void Pizza::set_large_cost(int large_cost){
  this->large_cost = large_cost;
}
void Pizza::set_num_ingredients(int num_ingredients){
  this->num_ingredients = num_ingredients;
  this->ingredients = new string[num_ingredients];
}

void Pizza::set_ingredient(int index, string ingredient){
  this->ingredients[index]=ingredient;
}



/*********************************************************************
 ** Function: does_pizza_have_ingredient
 ** Description: returns true is the pizza has a specified ingredient
 ** Parameters: string (ingredient)
 *********************************************************************/ 
bool Pizza::does_pizza_have_ingredient(string ingredient){
  for(int i=0; i< this->num_ingredients; i++){
    if(this->ingredients[i] == ingredient){
      return true;
    }
  }
  return false;
}




