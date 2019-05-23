/******************************************************
 ** Program: main.cpp
 ** Author: John Waczak
 ** Description:  Main program for pizza portal
 ******************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "pizza.h"
#include "menu.h"
#include "restaurant.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;



int main(int argc, char** argv){

  Restaurant rest;
  rest.load_data();

  string input;
  cout << "Welcome to Bytes Pizza!" << endl;
  cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";
  cin >> input;
  if(!(input == "C" || input == "E" || input == "Q" )){
    cout << "FAILED: Invalid choice.";
    exit(1);
  }
  int customer_or_employee;
  if( input == "C"){
    customer_or_employee = 1;
  }
  else if(input == "E"){
    customer_or_employee = 2;
    bool has_logged_in = false;
    while(!has_logged_in){
      cout << endl;
      string id;
      string password;
      cout << "Please enter your ID number: ";
      cin >> id;
      cout << "Please enter your password: ";
      cin >> password;
      has_logged_in = rest.login(id, password);
      cin.clear(); //clear bad input flag
      cin.ignore(256, '\n');
    }
  }
  else{
    customer_or_employee = -1;
    return 0;
  }

  cout << customer_or_employee;

  rest.view_menu();
  rest.view_address();
  rest.view_hours();
  rest.view_phone();


  rest.change_hours();
  rest.view_hours();

  rest.search_menu_by_price();
  rest.search_by_ingredients();

  rest.add_to_menu();

  rest.remove_from_menu();


  rest.view_orders();
  rest.remove_orders();
  rest.view_orders();
  return 0;
}












