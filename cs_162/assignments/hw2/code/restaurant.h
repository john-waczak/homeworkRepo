#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <fstream>

#include "pizza.h"
#include "menu.h"

using std::string;
using std::ifstream;
using std::ofstream;

struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours {
  string day;
  string open_hour;
  string close_hour;
};


class Restaurant {
 private:
    Menu menu;
    int num_employees;
    employee* employees;
    hours* week;
    string name;
    string phone;
    string address;
  public:

    Restaurant();
    ~Restaurant();

    void load_data();
    void load_menu_info();
    void load_employees_info();
    void load_restaurant_info();



    bool login(string id, string password);

    void view_menu();

    void view_hours();

    void view_address();

    void view_phone();

    void search_menu_by_price();

    void search_by_ingredients();



    void place_order(Pizza* selection, int num_orders);

    void change_hours();

    void add_to_menu();

    void remove_from_menu();

    void view_orders();

    void remove_orders();

};


int get_num_lines_in_file(ifstream &file);



#endif
