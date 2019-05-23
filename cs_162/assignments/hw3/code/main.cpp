/******************************************************
 ** Program: main.cpp
 ** Author: John Waczak
 ** Date: 05/12/2019
 ** Description:  main simulation
 ******************************************************/

#include <iostream>
#include <string>

#include <stdlib.h> // for rand() and srand() 

#include "animal.h"
#include "zoo.h"

using namespace std;


int main(){


  srand(0); // see random number sequence
  Zoo z = Zoo();
  int week = 0;
  cout << "Beginning simulation..." << endl;
  cout << "You are starting with $" << z.get_budget() << endl;
  while(z.get_budget() > 0){
    cout << "\n-----------------------------------------\n" << endl;
    cout << "Week: " << week << endl;
    cout << endl;
    cout << "Aging all animals" << endl;
    // (1) Age all of the animals
    z.age_all_animals();

    // (2) Random event
    if(week>0){
      int rand_event = get_random_int(4);
      if(rand_event==0){
        z.make_animal_sick();
      }
      else if(rand_event==1){
        z.make_animal_give_birth();
      }
      else if(rand_event==2){
        cout << "You're having an attendance boom!" << endl;
        z.attendance_boom();
      }
      else{
        cout << "Nothing interesting happens this week." << endl;
      }


      // (3) Receive weekly revenue
      z.get_revenue();


      // (4) buy animals
      bool bought_animals;
      bought_animals = z.buy_new_animals();
      if(bought_animals == false){
        cout << "You buy no animals." << endl;
      }
      cout << endl;

      // (5) purchase food for the week
      z.buy_food_for_animals();
    }
    else{
      // first time through just buy animals.
      bool bought_animals = z.buy_new_animals();
      if(bought_animals==false){
        cout << "You must buy some animals to start the simulation" << endl;
        return 1;
      }
    }
    week++;
  }


  return 0;
}







