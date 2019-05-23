/******************************************************
 ** Program: zoo.cpp
 ** Author: John Waczak
 ** Date: 05/12/2019
 ** Description:  Implementation file for zoo class
 ******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> // for rand() and srand()

#include "zoo.h"

using namespace std;

// constructor
Zoo::Zoo(){
  this->budget = 100000;
  this->num_monkeys = 0;
  this->num_sea_otters = 0;
  this->num_meerkats = 0;

  this->monkeys = new Monkey[0];
  this->sea_otters = new Sea_otter[0];
  this->meerkats = new Meerkat[0];
}


// destructor
Zoo::~Zoo(){
  delete [] this->monkeys;
  delete [] this->sea_otters;
  delete [] this->meerkats;
}



// accessors
int Zoo::get_budget() const{
  return this->budget;
}
int Zoo::get_num_monkeys() const{
  return this->num_monkeys;
}
int Zoo::get_num_sea_otters() const{
  return this->num_sea_otters;
}

int Zoo::get_num_meerkats() const{
  return this->num_meerkats;
}

Monkey Zoo::get_monkey(int index) const{
  return this->monkeys[index];
}
Sea_otter Zoo::get_sea_otter(int index) const{
  return this->sea_otters[index];
}
Meerkat Zoo::get_meerkat(int index) const{
  return this->meerkats[index];
}

// mutators
void Zoo::set_budget(int new_budget){
  this->budget = new_budget;
}
void Zoo::set_num_monkeys(int new_num_monkeys){
  this->num_monkeys = new_num_monkeys;
}
void Zoo::set_num_sea_otters(int new_num_sea_otters){
  this->num_sea_otters = new_num_sea_otters;
}
void Zoo::set_num_meerkats(int new_num_meerkats){
  this->num_meerkats = new_num_meerkats;
}

void Zoo::set_monkey(int index, Monkey m){
  this->monkeys[index] = m;
}
void Zoo::set_sea_otter(int index, Sea_otter s){
  this->sea_otters[index] = s;
}
void Zoo::set_meerkat(int index, Meerkat mk){
  this->meerkats[index] = mk;
}




// add to lists


/*********************************************************************
 ** Function: add_monkey
 ** Description: adds monkey to the zoo
 ** Parameters: whether or not baby is an adult
 *********************************************************************/
void Zoo::add_monkey(bool is_adult=false){
  Monkey* temp = this->monkeys;
  this->num_monkeys++;
  this->monkeys = new Monkey[this->num_monkeys];
  for(int i=0; i<this->num_monkeys-1; i++){
    this->monkeys[i] = temp[i];
  }
  if(is_adult==true){
    this->monkeys[this->num_monkeys-1] = Monkey(2*52);
  }
  else{
    this->monkeys[this->num_monkeys-1] = Monkey();
  }
  delete [] temp;
}


/*********************************************************************
 ** Function: add_sea_otter
 ** Description: adds a sea otter to the zoo
 ** Parameters: whether or not baby is an adult
 *********************************************************************/
void Zoo::add_sea_otter(bool is_adult=false){
  Sea_otter* temp = this->sea_otters;
  this->num_sea_otters++;
  this->sea_otters = new Sea_otter[this->num_sea_otters];
  for(int i=0; i<this->num_sea_otters-1; i++){
    this->sea_otters[i] = temp[i];
  }
  if(is_adult==true){
    this->sea_otters[this->num_sea_otters-1] = Sea_otter(2*52);
  }
  else{
    this->sea_otters[this->num_sea_otters-1] = Sea_otter();
  }
  delete [] temp;
}

/*********************************************************************
 ** Function: add_meerkat
 ** Description: adds meerkat to the zoo
 ** Parameters: whether or not baby is an adult
 *********************************************************************/
void Zoo::add_meerkat(bool is_adult=false){
  Meerkat* temp = this->meerkats;
  this->num_meerkats++;
  this->meerkats = new Meerkat[this->num_meerkats];
  for(int i=0; i<this->num_meerkats-1; i++){
    this->meerkats[i] = temp[i];
  }
  if(is_adult==true){
    this->meerkats[this->num_meerkats-1] = Meerkat(2*52);
  }
  else{
    this->meerkats[this->num_meerkats-1] = Meerkat();
  }
  delete [] temp;
}



// remove from lists

/*********************************************************************
 ** Function: remove_monkey
 ** Description: removes monkey from the zoo
 ** Parameters: index of monkey to remove
 *********************************************************************/
void Zoo::remove_monkey(int index){
  Monkey* temp = this->monkeys;
  for(int i=index; i<this->num_monkeys-1; i++){
    temp[i] = this->monkeys[i+1];
  }
  this->num_monkeys--;
  this->monkeys = new Monkey[this->num_monkeys];
  for(int i=0; i<this->num_monkeys; i++){
    this->monkeys[i] = temp[i];
  }
  delete [] temp;
}



/*********************************************************************
 ** Function: remove_sea_otter
 ** Description: removes sea_otter from the zoo
 ** Parameters: index of sea_otter to remove
 *********************************************************************/
void Zoo::remove_sea_otter(int index){
  Sea_otter* temp = this->sea_otters;
  for(int i=index; i<this->num_sea_otters-1; i++){
    temp[i] = this->sea_otters[i+1];
  }
  this->num_sea_otters--;
  this->sea_otters = new Sea_otter[this->num_sea_otters];
  for(int i=0; i<this->num_sea_otters; i++){
    this->sea_otters[i] = temp[i];
  }
  delete [] temp;
}



/*********************************************************************
 ** Function: remove_meerkat
 ** Description: removes meerkat from the zoo
 ** Parameters: index of meerkat to remove
 *********************************************************************/
void Zoo::remove_meerkat(int index){
  Meerkat* temp = this->meerkats;
  for(int i=index; i<this->num_meerkats-1; i++){
    temp[i] = this->meerkats[i+1];
  }
  this->num_meerkats--;
  this->meerkats= new Meerkat[this->num_meerkats];
  for(int i=0; i<this->num_meerkats; i++){
    this->meerkats[i] = temp[i];
  }
  delete [] temp;
}



/*********************************************************************
 ** Function: get_number_of_adults
 ** Description: counts number of adult animals in zoo
 *********************************************************************/
int Zoo::get_number_of_adults(){
  int adults = 0;
  for(int i=0; i<this->num_monkeys; i++){
    if(this->monkeys[i].get_is_adult()==true){
      adults ++;
    }
  }
  for(int i=0; i<this->num_sea_otters; i++){
    if(this->sea_otters[i].get_is_adult()==true){
      adults ++;
    }
  }
  for(int i=0; i<this->num_meerkats; i++){
    if(this->meerkats[i].get_is_adult()==true){
      adults ++;
    }
  }
  return adults;
}



/*********************************************************************
 ** Function: age_all_animals
 ** Description: increases age of all zoo animals by one week
 ** Parameters: None
 *********************************************************************/
void Zoo::age_all_animals(){
  // monkeys
  for(int i=0; i<this->num_monkeys; i++){
    int age = this->monkeys[i].get_age_in_weeks();
    this->monkeys[i].set_age_in_weeks(age+1);
  }
  // sea_otters
  for(int i=0; i<this->num_sea_otters; i++){
    int age = this->sea_otters[i].get_age_in_weeks();
    this->sea_otters[i].set_age_in_weeks(age+1);
  }
  //meerkats
  for(int i=0; i<this->num_meerkats; i++){
    int age = this->meerkats[i].get_age_in_weeks();
    this->meerkats[i].set_age_in_weeks(age+1);
  }
}


/*********************************************************************
 ** Function: make_animal_give_birth
 ** Description: randomly select an adult to give birth
 ** Parameters: none
 *********************************************************************/
void Zoo::make_animal_give_birth(){
  // get total number of adult animals
  if(this->num_monkeys==0 && this->num_sea_otters==0 && this->num_meerkats==0){
    cout << "The Zoo is empty. Nothing happens..." << endl;
  }
  else{
    cout << "An animal is giving birth!"<<endl;
    int num_adult_monkeys = 0;
    int num_adult_sea_otters = 0;
    int num_adult_meerkats = 0;

    for(int i=0; i<this->num_monkeys; i++){
      if(this->monkeys[i].get_is_adult() == true){
        num_adult_monkeys++;
      }
    }
    for(int i=0; i<this->num_sea_otters; i++){
      if(this->sea_otters[i].get_is_adult()==true){
        num_adult_sea_otters++;
      }
    }
    for(int i=0; i<this->num_meerkats; i++){
      if(this->meerkats[i].get_is_adult()==true){
        num_adult_meerkats++;
      }
    }

    if(num_adult_monkeys==0 && num_adult_sea_otters==0 && num_adult_meerkats==0){
      cout << "There are no adult animals. Nothing happens..." << endl;
    }
    else{
      int total_adults = num_adult_monkeys+num_adult_sea_otters+num_adult_meerkats;
      int N = get_random_int(total_adults);
      if(this->num_monkeys>0 && N <= num_monkeys){
        cout << "  A monkey gave birth!" << endl;
        Monkey m = Monkey();
        for(int j=0; j<m.get_litter_size(); j++){
          this->add_monkey();
        }
      }
      else if(this->num_sea_otters>0 && N > num_monkeys && N <= (num_monkeys+num_sea_otters)){
        cout << "  A sea otter gave birth!" << endl;
        Sea_otter s = Sea_otter();
        for(int j=0; j<s.get_litter_size(); j++){
          this->add_sea_otter();
        }
      }
      else if(this->num_meerkats>0 && N>this->num_monkeys+this->num_sea_otters){
        cout << "  A meerkat gave birth!" << endl;
        Meerkat m = Meerkat();
        for(int j=0; j<m.get_litter_size(); j++){
          this->add_meerkat();
        }
      }
      else{
        cout << "No animals are able to give birth" << endl;
      }
    }
  }
}


/*********************************************************************
 ** Function: make_animal_sick
 ** Description: randomly select an animal to become sick
 ** Parameters: none
 *********************************************************************/
void Zoo::make_animal_sick(){
  int Total = this->num_monkeys+this->num_sea_otters+this->num_meerkats;
  int N = get_random_int(Total);
  if(this->num_monkeys>0 && N<= this->num_monkeys){
      Monkey m = Monkey();
      cout << "A monkey got sick!"<<endl;
      if(this->budget < int(m.get_cost()/2)){
        cout << "  You don't have enough money to save it. It dies :(" <<endl;
        this->remove_monkey(N);
      }
      else{
        cout << "  You pay to treat the monkey." << endl;
        this->budget -= int(m.get_cost()/2);
      }
  }
  else if(this->num_sea_otters>0 && N>this->num_monkeys && N<=this->num_monkeys+this->num_sea_otters ){
    Sea_otter s = Sea_otter();
    cout << "A sea otter got sick!" << endl;
    if(this->budget < int(s.get_cost()/2)){
      cout << "  You don't have enough money to save it. It dies :(" << endl;
      this->remove_sea_otter(N-this->num_monkeys);
    }
    else{
      cout << "  You pay to treat the sea otter" <<endl;
      this->budget -= int(s.get_cost()/2);
    }
  }
  else if(this->num_meerkats>0 && N > this->num_monkeys+this->num_sea_otters){
    Meerkat m = Meerkat();
    cout << "A meerkat got sick!" << endl;
    if(this->budget < int(m.get_cost()/2)){
      cout << "  You don't have enough money to save it. It dies :(" << endl;
      this->remove_meerkat(N-this->num_monkeys-this->num_sea_otters);
    }
    else{
      cout << "  You pay to treat the meerkat." << endl; 
      this->budget -= int(m.get_cost()/2);
    }
  }
  else{
    cout << "You got lucky... no one got sick!" << endl; 
  }
} 







/*********************************************************************
 ** Function: attendance_boom
 ** Description: apply extra revenue for each monkey
 ** Parameters: none
 *********************************************************************/
void Zoo::attendance_boom(){
  for(int i=0; i<this->num_monkeys; i++){
    this->budget += get_random_int(401)+300; // generate random number between 300, and 700
  }
}


/*********************************************************************
 ** Function: get_revenue
 ** Description: apply revenue to budget for each animal in the zoo
 ** Parameters: 
 *********************************************************************/
void Zoo::get_revenue(){
  cout << endl;
  cout << "Adding revenue for the week to the budget" << endl;
  for(int i=0; i<this->num_monkeys; i++){
    if(this->monkeys[i].get_is_baby() == true){
      this->budget += 2*(this->monkeys[i].get_revenue());
    }
    else{
      this->budget += this->monkeys[i].get_revenue();
    }
  }
  for(int i=0; i<this->num_sea_otters; i++){
    if(this->sea_otters[i].get_is_baby() == true){
      this->budget += 2*(this->sea_otters[i].get_revenue());
    }
    else{
      this->budget += this->sea_otters[i].get_revenue();
    }
  }
  for(int i=0; i<this->num_meerkats; i++){
    if(this->meerkats[i].get_is_baby() == true){
      this->budget += 2*(this->meerkats[i].get_revenue());
    }
    else{
      this->budget += this->meerkats[i].get_revenue();
    }
  }
  cout << "New total: $" << this->budget << endl;
}



/*********************************************************************
 ** Function: buy_new_animals()
 ** Description: give user ability to purchase two new animals
 ** Parameters: none
 *********************************************************************/
bool Zoo::buy_new_animals(){
  cout << endl;
  bool yes_no;
  cout << "Would you like to purchase two new animals?" << endl;
  cout << "You have " << this->num_monkeys << " monkeys, "
       << this->num_sea_otters << " sea otters "
       << "and " << this->num_meerkats << " meerkats" << endl;
  cout << "(0) for no, (1) for yes" << endl;
  cin >> yes_no;
  if(yes_no==true){
    cout << "Would you like to purchase (0) Monkeys, (1) Sea Otters, or (2) Meerkats?";
    int choice;
    cin >> choice;
    if(choice == 0){
      Monkey m = Monkey();
      this->add_monkey(true);
      this->add_monkey(true);
      this->budget -= 2*m.get_cost();
      cout << "You purchased two monkeys" << endl;
    }
    else if(choice ==1){
      Sea_otter s = Sea_otter();
      this->add_sea_otter(true);
      this->add_sea_otter(true);
      this->budget -= 2*s.get_cost();
      cout << "You purchased two sea otters" << endl;
    }
    else if(choice ==2){
      Meerkat mk = Meerkat();
      this->add_meerkat(true);
      this->add_meerkat(true);
      this->budget -= 2*mk.get_cost();
      cout << "You purchased two meerkats" << endl;
    }
    else{
      cout << "Invalid selection " << endl;
      // this is just here as a placeholder
    }
  }

  return yes_no;
}




/*********************************************************************
 ** Function: buy_food_for_animals()
 ** Description: purchase food for each animal according to weekly price
 ** Parameters: none
 *********************************************************************/
void Zoo::buy_food_for_animals(){
  cout <<endl;
  cout << "Purchasing food for the week" << endl;
  float percentage = float(get_random_int(51)+75)/100.0;
  int base_cost = 40;
  int cost = int(percentage*(float)base_cost); // this will truncate but I think that's fine...

  for(int i =0; i<this->num_monkeys; i++){
    this->budget -= cost*this->monkeys[i].get_food_cost_multiplier();
  }
  for(int i =0; i<this->num_sea_otters; i++){
    this->budget -= cost*this->sea_otters[i].get_food_cost_multiplier();
  }
  for(int i =0; i<this->num_meerkats; i++){
    this->budget -= cost*this->meerkats[i].get_food_cost_multiplier();
  }

  cout << "Your new total is: $" << this->budget << endl;
  cout << endl;

}



/*********************************************************************
 ** Function: get_random_int
 ** Description: return random integer in interval [0, max_num]
 ** Parameters: max_num (int)
 *********************************************************************/
int get_random_int(int max_num){
  // generate random integer in interval [0, max_num]
  return rand() % max_num;
}






