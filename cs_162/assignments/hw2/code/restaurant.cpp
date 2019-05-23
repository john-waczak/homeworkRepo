/******************************************************
 ** Program: restaurant.cpp
 ** Author: John Waczak
 ** Description:  Function definitions for restaurant
 **               Class
 ******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
using std::setw;
using std::fixed;
using std::left;

Restaurant::Restaurant(){
  this->menu = Menu(0);
  this->employees = NULL;
  this->week = NULL;
  this->name = "";
  this->phone = "";
  this->address = "";

}

Restaurant::~Restaurant(){
  if(this->employees!=NULL){
    delete [] this->employees;
  }
  if(this->week!=NULL){
    delete [] this->week;
  }
}


/*********************************************************************
 ** Function: load_data
 ** Description: builds restaurant by loading in all data from external files
 ** Parameters: none
 *********************************************************************/
void Restaurant::load_data(){

  // load menu info
  load_menu_info();
  // load employee info
  load_employees_info();
  // load restaurant info;
  load_restaurant_info();
}



/*********************************************************************
 ** Function: load_menu_info
 ** Description: loads info into restaurant class from menu.txt
 ** Parameters: none
 *********************************************************************/
void Restaurant::load_menu_info(){
  string menu_file_name = "menu.txt";
  ifstream menu_file;
  menu_file.open(menu_file_name);
  if(!menu_file.is_open()){
    cout << "Could not open menu.txt. Exiting program." << endl;
    menu_file.close();
    exit(1);
  }

  // get the number of pizzas
  int num_pizzas = get_num_lines_in_file(menu_file);
  Menu load_menu = Menu(num_pizzas);

  for(int i=0; i<num_pizzas; i++){
    if(menu_file.eof()) break;

    // get first pieces of info from file
    string name;
    string small_cost;
    string medium_cost;
    string large_cost;
    string num_ingredients;

    getline(menu_file, name, ' ');
    getline(menu_file, small_cost, ' ');
    getline(menu_file, medium_cost, ' ');
    getline(menu_file, large_cost, ' ');
    getline(menu_file, num_ingredients, ' ');

    // if name is empty, exit
    if(name == "" or name == "\n") break;

    Pizza new_pizza(stoi(num_ingredients));
    new_pizza.set_name(name);
    new_pizza.set_small_cost(stoi(small_cost));
    new_pizza.set_medium_cost(stoi(medium_cost));
    new_pizza.set_large_cost(stoi(large_cost));

    // read for the rest of the ingredients
    for (int i=0; i<stoi(num_ingredients); i++){
      string ingred;
      if(i==stoi(num_ingredients)-1){
        getline(menu_file, ingred, '\n');
      }
      else{
        getline(menu_file, ingred, ' ');
      }
      new_pizza.set_ingredient(i, ingred);
    }

    // add the new pizza to the menu

    load_menu.set_pizza(i, new_pizza);
  }


  this->menu = load_menu;

  // for(int i=0; i<this->menu.get_num_pizzas(); i++){
  //   cout << this->menu.get_pizza(i).get_name() << endl;
  // }
  menu_file.close();
}


/*********************************************************************
 ** Function: load_employees_info
 ** Description: loads info into restaurant class from employee.txt
 ** Parameters: none
 *********************************************************************/
void Restaurant::load_employees_info(){
  string employee_file_name = "employee.txt";
  ifstream employee_file;
  employee_file.open(employee_file_name);
  if(!employee_file.is_open()){
    cout << "Could not open employee.txt. Exiting program." << endl;
    employee_file.close(); exit(1);
  }

  this->num_employees = get_num_lines_in_file(employee_file);
  this->employees = new employee[this->num_employees];
  for (int i=0; i<num_employees; i++){
    // break if at the end of the file
    if(employee_file.eof()) break;
    string id;
    string password;
    string first_name;
    string last_name;

    getline(employee_file, id, ' ');
    getline(employee_file, password, ' ');
    getline(employee_file, first_name, ' ');
    getline(employee_file, last_name, '\n');

    this->employees[i].id = stoi(id);
    this->employees[i].password = password;
    this->employees[i].first_name = first_name;
    this->employees[i].last_name = last_name;
  }
  employee_file.close();
}




/*********************************************************************
 ** Function: load_restaurant_info
 ** Description: loads information from restaurant.txt into class
 ** Parameters: none
 *********************************************************************/
void Restaurant::load_restaurant_info(){
  string restaurant_file_name = "restaurant_info.txt";
  ifstream restaurant_file;
  restaurant_file.open(restaurant_file_name);
  if(!restaurant_file.is_open()){
    cout << "Could not open employee.txt. Exiting program." << endl;
    restaurant_file.close();
    exit(1);
  }

  this->week = new hours[7];
  getline(restaurant_file, this->name, '\n');
  getline(restaurant_file, this->phone, '\n');
  getline(restaurant_file, this->address, '\n');

  for (int i=0; i<7; i++){
    if(restaurant_file.eof())break;
    getline(restaurant_file, this->week[i].day, ' ');
    getline(restaurant_file, this->week[i].open_hour, ' ');
    getline(restaurant_file, this->week[i].close_hour, '\n');
  }

  restaurant_file.close();
}





/*********************************************************************
 ** Function: get_num_lines_in_file
 ** Description: gets the number of lines in a file
 ** Parameters: reference to filestream
 *********************************************************************/
int get_num_lines_in_file(ifstream &file){
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





/*********************************************************************
 ** Function: login
 ** Description: returns true of user provides correct login info
 ** Parameters: id, password
 *********************************************************************/
bool Restaurant::login(string id, string password){

  bool successful_login = false;
  for(int i=0; i<this->num_employees; i++){
    if(this->employees[i].id == stoi(id)){
      if(this->employees[i].password == password){
        successful_login=true;
      }
    }
  }
  return successful_login;
}







/*********************************************************************
 ** Function: view_menu
 ** Description: prints menu and overwrites menu.txt with any updated info
 ** Parameters: none
 *********************************************************************/
void Restaurant::view_menu(){
  this->menu.print_menu();

  // update menu.txt file
  string file_name = "menu.txt";
  ofstream menu_file;
  menu_file.open(file_name, ios::trunc);

  for(int i=0; i<this->menu.get_num_pizzas(); i++){
    menu_file << this->menu.get_pizza(i).get_name() << " "
              << this->menu.get_pizza(i).get_small_cost() << " "
              << this->menu.get_pizza(i).get_medium_cost() << " "
              << this->menu.get_pizza(i).get_large_cost() << " "
              << this->menu.get_pizza(i).get_num_ingredients() << " ";
    for(int j=0; j<this->menu.get_pizza(i).get_num_ingredients()-1; j++){
      menu_file << this->menu.get_pizza(i).get_ingredient(j) << " ";
    }
    menu_file << this->menu.get_pizza(i).get_ingredient(this->menu.get_pizza(i).get_num_ingredients()-1) << endl;
  }

}



/*********************************************************************
 ** Function: view_hours
 ** Description: prints out hours of operation
 ** Parameters: none
 *********************************************************************/
void Restaurant::view_hours(){
  cout << endl;
  for(int i=0; i<7; i++){
    cout << setw(11) << left << this->week[i].day
         << this->week[i].open_hour + "--"
         << this->week[i].close_hour << endl;
  }
  cout << endl;
}



/*********************************************************************
 ** Function: view_address
 ** Description: print out restaurant address
 ** Parameters: none
 *********************************************************************/
void Restaurant::view_address(){
  cout << endl;
  cout << "Address: " << this->address << endl;
  cout << endl;
}



/*********************************************************************
 ** Function: view_phone
 ** Description: print out restaurant phone number
 ** Parameters: none
 *********************************************************************/
void Restaurant::view_phone(){
  cout << endl;
  cout << "Address: " << this->phone << endl;
  cout << endl;
}




/*********************************************************************
 ** Function: search_menu_by_price
 ** Description: guide user through searching the menu by price
 ** Parameters: none
 *********************************************************************/
void Restaurant::search_menu_by_price(){
  cout << endl;
  int max;
  cout << "Please enter a maximum price: ";
  cin >> max;
  if(cin.good()){
    Menu searched = this->menu.search_pizza_by_cost(max);
    searched.print_menu();

    cout << endl;
    string choice;
    cout << "Would you like to place an order off this search result (y/n)? ";
    cin >> choice; 
    if(choice == "y"){
      Pizza *selection = new Pizza[searched.get_num_pizzas()];
      for(int i=0; i<searched.get_num_pizzas(); i++){
        selection[i] = searched.get_pizza(i); 
      }
      this->place_order(selection, searched.get_num_pizzas());
      delete [] selection;
    }
  }
  else{
    cout << "FAILED: Invalid price" << endl;
  }
}




/*********************************************************************
 ** Function: search_by_ingredients
 ** Description: guide user through searching menu by ingredients
 ** Parameters: none
 *********************************************************************/
void Restaurant::search_by_ingredients(){
  int choice;
  bool has_chosen_filter = false;
  while(!has_chosen_filter){
    cout << endl;
    cout << "How would you like to filter your search?" << endl;
    cout << "Ingredients to include (1)" << endl;
    cout << "Ingredients to exclude (2)" << endl;
    cin >> choice;
    if(cin.good()){
      if(!(choice == 1 || choice == 2)){
        cout << "Failed: Invalid input" << endl;
        cin.clear(); //clear bad input flag
        cin.ignore(256, '\n');
      }
      else{
        break;
      }
    }
    else{
      cout << "FAILED: Invalid input" << endl;
      cin.clear(); //clear bad input flag
      cin.ignore(256, '\n');
    }
  }
  cout << endl;


  // add items to search list
  int n = 1;
  string *search_list = new string[n];
  cout << "Please enter an ingredient for the search (case sensitive): ";
  cin >> search_list[0];
  cout << endl;
  cout << "Search list: " << search_list[0]  << endl;
  cout << endl;

  bool begin_search = false;
  cout << "Would you like add more items to search list (0) or perform the search (1)? ";
  cin >> begin_search;
  cout << endl;

  while(!begin_search){
    n++;
    string *temp = new string[n];
    for(int i=0; i<n-1; i++){
      temp[i] = search_list[i];
    }
    cout << "Please enter an ingredient for the search (case sensitive): ";
    cin >> temp[n-1];
    cout << endl;


    cout << "New search list: ";
    for(int i=0; i<n; i++){
      cout << " " << temp[i];
    }
    cout << endl;
    cout << endl;

    delete [] search_list;
    search_list = temp;

    cout << "Would you like add more items to search list (0) or perform the search (1)? ";
    cin >> begin_search;
    cout << endl;

  }

  Menu search_results;
  if(choice == 1){
    search_results = this->menu.search_pizza_by_ingredients_to_include(search_list, n);
  }
  else{
    search_results = this->menu.search_pizza_by_ingredients_to_exclude(search_list, n);
  }

  cout << endl;
  cout << "Search results:"<< endl;
  cout << endl;
  search_results.print_menu();

  cout << endl;
  string choice2;
  cout << "Would you like to place an order off this search result (y/n)? ";
  cin >> choice2;
  if(choice2 == "y"){
    Pizza *selection = new Pizza[search_results.get_num_pizzas()];
    for(int i=0; i<search_results.get_num_pizzas(); i++){
      selection[i] = search_results.get_pizza(i);
    }
    this->place_order(selection, search_results.get_num_pizzas());
    delete [] selection;
  }

  delete [] search_list;


}







/*********************************************************************
 ** Function: place_order
 ** Description: places an order for a pizza based off of a selection
 ** Parameters: selection, number of orders
 *********************************************************************/
void Restaurant::place_order(Pizza* selection, int num_orders){
  string file_name = "orders.txt";

  // get order number
  ifstream ord_file;
  ord_file.open(file_name);
  int order_num = get_num_lines_in_file(ord_file)+1;
  ord_file.close();


  // place order
  ofstream orders_file;
  orders_file.open(file_name, ios::app);

  string cust_name;
  string cust_cc;
  string cust_phone;
  cout << endl;
  cout << "Please provide the following information:" << endl;
  cout << "Customer name (No spaces): ";
  cin >> cust_name;
  cout << "Credit Card Number: ";
  cin >> cust_cc;
  cout << "Phone number: ";
  cin >> cust_phone;

  cout << "Here is what you entered:" << endl;
  cout << cust_name << " " << cust_cc << " " << cust_phone << endl;

  for(int i=0; i<num_orders; i++){
    cout << i << " " << selection[i].get_name() << " ";
    if(selection[i].get_small_cost()!=-1){
      cout << "$" << selection[i].get_small_cost() << " ";
    }
    if(selection[i].get_medium_cost()!=-1){
      cout << "$" << selection[i].get_medium_cost() << " ";
    }
    if(selection[i].get_large_cost()!=-1){
      cout << "$" << selection[i].get_large_cost() << " ";
    }
    cout << endl;
  }

  int option;
  int how_many;
  string size_of_order;

  cin.clear();
  cin.ignore(256, '\n');

  cout << "Please select an option from the list above: ";
  cin >> option;
  cout << "Your selection: " << option << endl;

  cout << "How many " << selection[option].get_name() << " would you like?" << endl;
  cin >> how_many;
  cout << "Which size would you like? (S, M, L)?" << endl;
  cin >> size_of_order;

  orders_file << order_num << " "
              << cust_cc << " "
              << cust_phone << " "
              << selection[option].get_name() << " "
              << size_of_order << " "
              << how_many << endl;

  cout << "Thank you! Your order number is: " << order_num << endl; 

  orders_file.close();
}




/*********************************************************************
 ** Function: change_hours
 ** Description: changes the weekly hours of operation
 ** Parameters: none
 *********************************************************************/
void Restaurant::change_hours(){
  string day;
  string open_hour;
  string close_hour;
  cout << "Which day would you like to change the hours for? ";
  cin >> day;

  // check to make sure the day exists
  int index;
  bool day_exists = false;
  for(int i=0; i<7; i++){
    if(this->week[i].day == day){
      day_exists = true;
      index = i;
    }
  }

  if (day_exists){
    cout << "What should the opening time be? ";
    cin >> open_hour;
    cout << "What should the closing time be? ";
    cin >> close_hour;
    this->week[index].open_hour = open_hour;
    this->week[index].close_hour = close_hour;


    // write to restaurant_info.txt file
    string file_name = "restaurant_info.txt";
    ofstream rest_file;
    rest_file.open(file_name, ios::trunc);
    rest_file << this->name << endl;
    rest_file << this->phone << endl;
    rest_file << this->address << endl;
    for(int i=0; i<7; i++){
      rest_file << this->week[i].day << " "
                << this->week[i].open_hour << " "
                << this->week[i].close_hour << endl;
    }
    rest_file.close();
  }


  else{
    cout << "FAILED: Could not find the day you specified" << endl;
  }
}



/*********************************************************************
 ** Function: add_to_menu
 ** Description: add a pizza to the restaurant menu
 ** Parameters: none
 *********************************************************************/
void Restaurant::add_to_menu(){
  Pizza new_pizza;

  string name;
  int small_cost;
  int medium_cost;
  int large_cost;
  int num_ingredients;


  cout << "Please enter a name for the pizza (No spaces): ";
  cin >> name;
  cout << "Please enter the cost for a small pizza: ";
  cin >> small_cost;
  cout << "Please enter the cost for a medium pizza: ";
  cin >> medium_cost;
  cout << "Please enter the cost for a large pizza: ";
  cin >> large_cost;
  cout << "How many ingredients does it have? ";
  cin >> num_ingredients;

  new_pizza.set_name(name);
  new_pizza.set_small_cost(small_cost);
  new_pizza.set_medium_cost(medium_cost);
  new_pizza.set_large_cost(large_cost);
  new_pizza.set_num_ingredients(num_ingredients);
  for(int i=0; i<num_ingredients; i++){
    cout << "Enter the " << i+1 << "th ingredient ";
    string ingred;
    cin >> ingred;
    new_pizza.set_ingredient(i, ingred);
    cout << endl;
  }

  this->menu.add_to_menu(new_pizza);

  view_menu();

}




/*********************************************************************
 ** Function: remove_from_menu
 ** Description: remove pizza from restaurant menu
 ** Parameters: none
 *********************************************************************/
void Restaurant::remove_from_menu(){
  string pizza_to_remove;
  cout << "Please enter the name of the pizza you wish to remove: ";
  cin >> pizza_to_remove;

  int index = -1;
  for(int i=0; i<this->menu.get_num_pizzas(); i++){
    if(this->menu.get_pizza(i).get_name() == pizza_to_remove){
      index = i;
    }
  }

  if(index != -1){
    cout << "\n\n";
    cout << "Removing " << this->menu.get_pizza(index).get_name() << " from the menu"<< endl;

    this->menu.remove_from_menu(index);
  }
  else{
    cout << "FAILED: Could not find pizza" << endl;
  }

  view_menu();
}



/*********************************************************************
 ** Function: view_orders
 ** Description: prints current orders list
 ** Parameters: none
 *********************************************************************/
void Restaurant::view_orders(){
  string file_name = "orders.txt";
  ifstream orders_file;
  orders_file.open(file_name);

  cout << "\n\n";
  cout<<"Showing the current orders \n";
  while(!orders_file.eof()){
    string line;
    getline(orders_file, line, '\n');
    cout << line << endl;
  }

  orders_file.close();

}




/*********************************************************************
 ** Function: remove_orders
 ** Description: removes an order from the orders list
 ** Parameters: none
 *********************************************************************/
void Restaurant::remove_orders(){
  view_orders();

  string file_name = "orders.txt";
  ifstream orders_file;
  orders_file.open(file_name);

  int num_orders = get_num_lines_in_file(orders_file);
  string orders[num_orders];
  for(int i=0; i<num_orders; i++){
    if(orders_file.eof()) break;
    getline(orders_file, orders[i], '\n');
  }
  orders_file.close();


  int order_to_remove;
  cout << "Please enter the order number you wish to remove: ";
  cin >> order_to_remove;

  string of_name = "orders.txt";
  ofstream of;
  of.open(file_name, ios::trunc);
  for(int i=0; i<num_orders; i++){
    if(!(atoi(&orders[i].c_str()[0])==order_to_remove)){
      of << orders[i] << endl;
    }
  }

  of.close();

}








