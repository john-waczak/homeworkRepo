/******************************************************
 ** Program: menu.cpp
 ** Author: John Waczak
 ** Description:  Function definitions for menu class
 ******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "pizza.h"
#include "menu.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::fixed;
using std::left;


// constructors
Menu::Menu(){
  this->num_pizzas=0;
  this->pizzas = NULL;
}

Menu::Menu(int num_pizzas){
  this->num_pizzas = num_pizzas;
  this->pizzas = new Pizza[num_pizzas];
};

// Big three
Menu::~Menu(){
  if(this->pizzas!=NULL){
    delete [] pizzas;
  }
}

Menu::Menu(const Menu &old_menu){
  num_pizzas = old_menu.num_pizzas;
  pizzas = new Pizza[num_pizzas];
  for(int i=0; i<num_pizzas; i++){
    pizzas[i] = old_menu.pizzas[i];
  }
}


Menu& Menu::operator=(const Menu &old_menu){
  if(this != &old_menu){
    delete [] this->pizzas;
    this->num_pizzas = old_menu.num_pizzas;
    this->pizzas = new Pizza[this->num_pizzas];

    for(int i = 0; i < this->num_pizzas; i++ ){
      this->pizzas[i] = old_menu.pizzas[i];
    }
  }

  return *this;
}



// getters
int Menu::get_num_pizzas() const{
  return this->num_pizzas;
}

Pizza Menu::get_pizza(int index) const{
  return this->pizzas[index];
}


// setter
void Menu::set_num_pizzas(int new_num_pizzas){
  this->num_pizzas = new_num_pizzas;
  this->pizzas = new Pizza[new_num_pizzas];
}

void Menu::set_pizza(int index, Pizza new_pizza){
  this->pizzas[index] = new_pizza;
}



/*********************************************************************
 ** Function: search_pizza_by_cost
 ** Description: return a new menu with pizza prices marked by cost
 ** Parameters: maximum price allowed
 *********************************************************************/
Menu Menu::search_pizza_by_cost(int upper_bound){
  // sort through pizzas and set cost to -1 for ineligible
  Menu temp = *this;
  for(int i = 0; i < temp.get_num_pizzas(); i++){
    if(this->pizzas[i].get_large_cost() > upper_bound){
      temp.pizzas[i].set_large_cost(-1);
    }
    if(this->pizzas[i].get_medium_cost() > upper_bound){
      temp.pizzas[i].set_medium_cost(-1);
    }
    if(this->pizzas[i].get_small_cost() > upper_bound){
      temp.pizzas[i].set_small_cost(-1);
    }
  }
  return temp;
}



/*********************************************************************
 ** Function: search_pizza_by_ingredients_to_include
 ** Description: return a menu with pizzas that have all ingredients
 ** Parameters: ingredients list, number of ingredients
 *********************************************************************/ 
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients){

  int N = this->num_pizzas;
  Menu searched_menu;


  for(int i=0; i<N; i++){
    bool has_all_ingredients = true;
    for(int j=0; j<num_ingredients; j++){
      if(!this->get_pizza(i).does_pizza_have_ingredient(ingredients[0])){
        has_all_ingredients = false;
      }
    }

    if(has_all_ingredients == true){
      searched_menu.add_to_menu(this->get_pizza(i));
    }
  }

  return searched_menu;
}





/*********************************************************************
 ** Function: search_pizza_by_ingredients_to_exclude
 ** Description: return a menu with all pizzas excluding specified ingredients
 ** Parameters: ingredients list, number of ingredients
 *********************************************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients){
  Menu new_menu;

  for(int i=0; i < this->num_pizzas; i++){
    bool has_bad_ingredient = false;

    for(int j=0; j < num_ingredients; j++){
      if(this->get_pizza(i).does_pizza_have_ingredient(ingredients[j])){
        has_bad_ingredient = true;
      }
    }

    if(has_bad_ingredient == false){
      new_menu.add_to_menu(this->get_pizza(i));
    }
  }
  return new_menu;
}



/*********************************************************************
 ** Function: add_to_menu
 ** Description: adds a pizza to the menu
 ** Parameters: new pizza to add to menu
 *********************************************************************/
void Menu::add_to_menu(Pizza pizza_to_add){
  int N = this->get_num_pizzas()+1;
  Menu new_menu = Menu(N);
  for(int i=0; i<N-1; i++){
    new_menu.set_pizza(i, this->get_pizza(i));
  }
  new_menu.set_pizza(N-1, pizza_to_add);

  *this = new_menu;
}


/*********************************************************************
 ** Function: remove_from_menu
 ** Description: removes a pizza from the menu
 ** Parameters: new pizza to remove from menu
 *********************************************************************/
void Menu::remove_from_menu(int index){
  int N = num_pizzas;
  if(index > N-1){
    cout << "FAILED: Invalid index" << endl;
  }
  else{
    Pizza* temp = pizzas;
    for(int i=index; i<N-1; i++){
      temp[i] = pizzas[i+1];
    }
    for(int i=0; i<N; i++){
      cout << temp[i].get_name() << endl;
    }

    num_pizzas = N-1;
    for(int i=0; i<num_pizzas; i++){
      pizzas[i] = temp[i];
    }
  }
}



/*********************************************************************
 ** Function: print_menu
 ** Description: displays menu information
 ** Parameters: none
 *********************************************************************/
void Menu::print_menu(){
  cout << endl;
  for(int i=0; i<this->num_pizzas; i++){
    cout << setw(18) << left << this->pizzas[i].get_name();
    if(this->pizzas[i].get_small_cost() == -1) {
      cout << "S:"<< setw(2) << left << "N/A" << " ";
    }
    else{
      cout << "S:"<< setw(2) << left << this->pizzas[i].get_small_cost() << " ";
    }
    if(this->pizzas[i].get_medium_cost() == -1) {
      cout << "S:"<< setw(2) << left << "N/A" << " ";
    }
    else{
      cout << "M:"<< setw(2) << left << this->pizzas[i].get_medium_cost() << " ";
    }
    if(this->pizzas[i].get_large_cost() == -1) {
      cout << "S:"<< setw(2) << left << "N/A" << " ";
    }
    else{
      cout << "S:"<< setw(2) << left << this->pizzas[i].get_large_cost() << " ";
    }
    cout << "  Ingred:  ";
    for(int j=0; j<this->pizzas[i].get_num_ingredients(); j++){
      cout << this->pizzas[i].get_ingredient(j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}



