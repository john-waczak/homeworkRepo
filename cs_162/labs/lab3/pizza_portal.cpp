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
using std::ios;




// default constructor
Pizza::Pizza(){}



// big three
Pizza::~Pizza(){
  // there isn't any dynamic memory to delete here...
}


Pizza::Pizza(const Pizza &old_pizza){
  cout << "Copy constructor called" << endl;
  this->name = old_pizza.name;
  this->small_cost = old_pizza.small_cost;
  this->medium_cost = old_pizza.medium_cost;
  this->large_cost = old_pizza.large_cost;

  string new_ingredients[old_pizza.num_ingredients];
  for(int i=0; i<old_pizza.num_ingredients; i++){
    new_ingredients[i] = old_pizza.ingredients[i];
  }
  this->ingredients = new_ingredients;
}



Pizza& Pizza::operator=(const Pizza &old_pizza){
  if(this != &old_pizza){
    this->name = old_pizza.name;
    this->small_cost = old_pizza.small_cost;
    this->medium_cost = old_pizza.medium_cost;
    this->large_cost = old_pizza.large_cost;

    string new_ingredients[old_pizza.num_ingredients];
    for(int i=0; i<old_pizza.num_ingredients; i++){
      new_ingredients[i] = old_pizza.ingredients[i];
    }
    this->ingredients = new_ingredients;
  }
  return *this;
}


 // accessors
string Pizza::get_name() const{
  return this-> name;
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

string* Pizza::get_ingredients() const{
  return this->ingredients;
}


// mutators
void Pizza::set_name(string new_name){
  this->name = new_name;
}

void Pizza::set_small_cost(int new_small_cost){
  this->small_cost = new_small_cost;
}

void Pizza::set_medium_cost(int new_medium_cost){
  this->medium_cost = new_medium_cost;
}

void Pizza::set_large_cost(int new_large_cost){
  this->large_cost = new_large_cost;
}

void Pizza::set_num_ingredients(int new_num_ingredients){
  this->num_ingredients = new_num_ingredients;
}

void Pizza::set_ingredients(string* new_ingredients){
  this->ingredients = new_ingredients;
}


// functions for other stuff
Pizza* create_menu(int num_pizzas){
  Pizza* menu = new Pizza[num_pizzas];
  return menu;
}
 

void set_menu_from_file(Pizza* menu, int num_pizzas, ifstream &menu_file){
  for(int i=0; i<num_pizzas; i++){
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;

    menu_file >> name;
    menu_file >> small_cost;
    menu_file >> medium_cost;
    menu_file >> large_cost;
    menu_file >> num_ingredients;

    menu[i].set_name(name);
    menu[i].set_small_cost(small_cost);
    menu[i].set_medium_cost(medium_cost);
    menu[i].set_large_cost(large_cost);
    menu[i].set_num_ingredients(num_ingredients);

    string ingredients[num_ingredients];
    for(int j=0; j<num_ingredients; j++){
      menu_file >> ingredients[j];
    }

    menu[i].set_ingredients(ingredients);
  }

}


int get_num_lines(ifstream &file){
  int num_lines = 0;
  string line;
  while(!file.eof()){
    getline(file, line, '\n');
    if(line!=""){
      num_lines ++;
    }
  }
  file.clear();
  file.seekg(0, ios::beg);
  return num_lines;
}


















