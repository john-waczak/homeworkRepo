/*********************************************************************
 ** Program Filename: wizard_catalog.cpp
 ** Author: John Waczak
 ** Date:  4-14-2019
 ** Description: implementation file for wizard catalog functions
 *********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "wizard_catalog.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;



/*************functions to deal with files************************/


/*********************************************************************
 ** Function: enough_args_given
 ** Description: check if enough command line args have been given
 ** Parameters: argc (the number of command line args)
 *********************************************************************/
bool enough_args_given(int argc){
  if(argc!=3){
    cout<<"Incorrect usage!"<<endl;
    cout<<"./wizard_catalog <wizards.txt> <spellbooks.txt>" << endl;
    return false;
  }
  else{
    return true;
  }
}


/*********************************************************************
 ** Function: files_opened_succesfully
 ** Description: check whether or not files have been opened
 ** Parameters: array of fstream objects and the number of files
 *********************************************************************/
bool files_opened_succesfully(fstream* files, int num_files){
  bool success = true;
  for(int i=0; i<num_files; i++){
    if(!files[i].is_open()){
      cout<<"Error: failed to open file " << i+1 << endl ;
      success = false;
    }
  }
  return success;
}


/*********************************************************************
 ** Function: open_files
 ** Description: open each of the files fromthe command line
 ** Parameters: array of file names
 *********************************************************************/
fstream* open_files(char** argv){
  fstream* files = new fstream[2];
  files[0].open(argv[1], ios::in);
  files[1].open(argv[2], ios::in);
  return files;
}


/*********************************************************************
 ** Function: close_files
 ** Description: close all opened files
 ** Parameters: array of fstream objects
 *********************************************************************/
void close_files(fstream* files){
  files->close();
  delete[] files;
}







/***********functions to deal with structs**********************************/

/*********************************************************************
 ** Function: create_spellbooks
 ** Description: dynamically allocate array of spellbooks
 ** Parameters: number of spellbooks
 *********************************************************************/
spellbook* create_spellbooks(int num_books){
  spellbook* spellbooks = new spellbook[num_books];
  return spellbooks;
}


/*********************************************************************
 ** Function: create_wizard_list
 ** Description: dynamically allocate array of wizards
 ** Parameters: number of wizards
 *********************************************************************/
wizard* create_wizard_list(int num_wizards){
  wizard* wizards = new wizard[num_wizards];
  return wizards;
}


/*********************************************************************
 ** Function: get_wizard_data
 ** Description: populate wizard list with data from file
 ** Parameters:  wizard array, number of wizards, wizard data file
 *********************************************************************/
void get_wizard_data(wizard* wizards, int num_wizards, fstream& wizard_file){
  for(int i=0; i<num_wizards;  i++){
    if(wizard_file.eof()) break; // make sure we don't go past the e.o.f.
    wizard_file >> wizards[i].name;
    wizard_file >> wizards[i].id;
    wizard_file >> wizards[i].password;
    wizard_file >> wizards[i].position_title;
    wizard_file >> wizards[i].beard_length;
  }
}



/*********************************************************************
 ** Function: get_spellbook_data
 ** Description: populate spellbook array with data from file
 ** Parameters: spellbook array, number of books, spellbook file
 *********************************************************************/
void get_spellbook_data(spellbook* spellbooks, int num_spellbooks, fstream& spellbooks_file){
  for (int i=0; i<num_spellbooks; i++){
    if(spellbooks_file.eof())break;
    // fill out initial info
    spellbooks_file >> spellbooks[i].title;
    spellbooks_file >> spellbooks[i].author;
    spellbooks_file >> spellbooks[i].num_pages;
    spellbooks_file >> spellbooks[i].edition;
    spellbooks_file >> spellbooks[i].num_spells;

    // create struct for spells
    spell* spells = create_spells(spellbooks[i].num_spells);
    get_spell_data(spells, spellbooks[i].num_spells, spellbooks_file);
    spellbooks[i].s =spells;

    // calculate avg success rate
    float avg_success_rate = 0.0;
    for(int j=0; j<spellbooks[i].num_spells; j++){
      avg_success_rate += spellbooks[i].s[j].success_rate;
    }
    avg_success_rate = avg_success_rate/((float)spellbooks[i].num_spells);
    spellbooks[i].avg_success_rate = avg_success_rate; 
  }
}


/*********************************************************************
 ** Function: create_spells
 ** Description: dynamically allocate array of spells
 ** Parameters: number of spells
 *********************************************************************/
spell* create_spells(int num_spells){
  spell* spells = new spell[num_spells];
  return spells;
}


/*********************************************************************
 ** Function: get_spell_data
 ** Description: populate spell array with data from file
 ** Parameters: spell array, number of spells, spell file
 *********************************************************************/
void get_spell_data(spell* spells, int num_spells, fstream& spellbooks_file){
  for(int i=0; i<num_spells;  i++){
    if(spellbooks_file.eof())break;
    spellbooks_file >> spells[i].name;
    spellbooks_file >> spells[i].success_rate;
    spellbooks_file >> spells[i].effect;
  }
}


/*********************************************************************
 ** Function: delete_info
 ** Description: delete all dynamically allocated memory
 ** Parameters: wizards array, number of wizards, spellbook array,
 **             number of spells
 *********************************************************************/
void delete_info(wizard **wizards, int num_wizards, spellbook **spellbooks, int num_spellbooks){
  // delete wizard stuff


  delete[] *wizards;
  for(int i=0; i<num_spellbooks; i++){
    delete_spells((*spellbooks)[i].s);
    // why cant I do delete_spells(spellbooks[i]->s);
  }

  delete[] *spellbooks;
}


/*********************************************************************
 ** Function: delete_spells
 ** Description: delete dynamically allocated spell array
 ** Parameters: spell array
 *********************************************************************/
void delete_spells(spell* spells){
  delete[] spells;
}





/********** functions to deal with login*******************************/

/*********************************************************************
 ** Function: login
 ** Description: prompt user to login and return index of wizard in
 **              wizard array
 ** Parameters: wizard array, number of wizards
 *********************************************************************/
int login(wizard* wizards, int num_wizards){
  int attempts =0;
  bool has_logged_in = false;
  int index;
  while(!has_logged_in){
    attempts ++;
    if(attempts>3){
      return -1; // too many attempts
    }

    index = attempt_login(wizards, num_wizards);
    if(index >= 0){
      has_logged_in = true;
    }
    else{
      cout << "Incorrect id or password. Please try again"<<endl;
    }
  }
  return index;
}


/*********************************************************************
 ** Function: attempt_login
 ** Description: try to find index of wizard based on usr input
 ** Parameters: wizard array, number of wizards
 *********************************************************************/
int attempt_login(wizard* wizards, int num_wizards){
  int usr_id;
  string usr_pass;

  cout << "Enter your id: ";
  cin >> usr_id;
  while(cin.fail()){
    cin.clear(); // reset cin.fail()
    cin.ignore(); // clear out the stream of any pesky newline characters
    cout << "Error: enter a valid (integer) id: ";
    cin >> usr_id;
  }


  // if all goes well, return the index of the correct wizard
  int login = get_wizard_id_index(wizards, num_wizards, usr_id);
  if (login == -1){
    return -1;
  }

  cout << "Enter your password: ";
  cin >> usr_pass;
  return check_password(wizards, login, usr_pass);
}


/*********************************************************************
 ** Function: get_wizard_index
 ** Description: get index of wizard based off of usr_id
 ** Parameters: wizard array, number of wizards, usr_id
 *********************************************************************/
int get_wizard_id_index(wizard* wizards, int num_wizards, int usr_id){
  int index = -1;
  for(int i=0; i<num_wizards; i++){
    if(usr_id == wizards[i].id){
      index = i;
    }
  }
  return index;
}



/*********************************************************************
 ** Function: check_password
 ** Description: check if password matches user id
 ** Parameters: wizard array, wizard index, password
 *********************************************************************/
int check_password(wizard* wizards, int index, string usr_pass){
  if(wizards[index].password == usr_pass){
    return index;
  }
  return -1;
}





/*********functions for prompting sort choice**************************/

/*********************************************************************
 ** Function: print_wizard_info
 ** Description: print out wizard information
 ** Parameters: wizard array, wizard index
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void print_wizard_info(wizard* wizards, int index){
  wizard wiz = wizards[index];
  cout << "\nWelcome " << wiz.name << endl;
  cout << "id: " << wiz.id << endl;
  cout << "Status: " << wiz.position_title << endl;
  cout << "Beard Length: " << wiz.beard_length << endl;
  cout << "\n";
}


/*********************************************************************
 ** Function: prompt_for_sort
 ** Description: ask user how they want to sort data
 ** Parameters: none
 *********************************************************************/
int prompt_for_sort(){
  int choice;
  cout << "Which option would you like to choose?"  << endl;
  cout << "Sort spellbooks by number of pages. (1)" << endl;
  cout << "Sort spells by effect. (2)" << endl;
  cout << "Sort by average success rate of spells. (3)" << endl;
  cout << "Quit. (4)" << endl;
  cin >> choice;
  while(choice <1 or choice >4){
    cout << "Error: please choose a valid option." << endl;
    cin.clear();
    cin.ignore();
    cin >> choice;
  }
  return choice;
}


/*********************************************************************
 ** Function: screen_or_file
 ** Description: ask user how they want to print spells
 *********************************************************************/
int screen_or_file(){
  int choice;
  cout << "How would you like the information displayed?" << endl;
  cout << "Print to screen. (1)" << endl;
  cout << "Print to file (2)" << endl;
  cin >> choice;
  while(choice <1 or choice >2){
    cout << "Error: please choose a valid option." << endl;
    cin.clear();
    cin.ignore();
    cin >> choice;
  }
  return choice;

}






/********** sort functions ***************************/

/*********************************************************************
 ** Function: sort_num_pages
 ** Description: sort spellbooks by number of pages
 ** Parameters: spellbooks, number of spells
 *********************************************************************/
void sort_num_pages(spellbook* spellbooks, int num_spellbooks){
  spellbook temp;
  for(int i=0; i<num_spellbooks; i++){
    for(int j=0; j<num_spellbooks; j++){
      // exchange values
      if(spellbooks[i].num_pages < spellbooks[j].num_pages){
        temp = spellbooks[i];
        spellbooks[i] = spellbooks[j];
        spellbooks[j] = temp;
      }
    }
  }
}


/*********************************************************************
 ** Function: sort_average_success
 ** Description: sort spellbooks by avg success rate
 ** Parameters: spellbooks, num spells
 *********************************************************************/
void sort_average_success(spellbook* spellbooks, int num_spellbooks){
  spellbook temp;
  for(int i=0; i<num_spellbooks; i++){
    for(int j=0; j<num_spellbooks; j++){
      // exchange values
      if(spellbooks[i].avg_success_rate < spellbooks[j].avg_success_rate){
        temp = spellbooks[i];
        spellbooks[i] = spellbooks[j];
        spellbooks[j] = temp;
      }
    }
  }
}




/*********** printing functions **********************/

/*********************************************************************
 ** Function: print_spellbooks_by_num_pages
 ** Description: print out spellbooks by number of pages
 ** Parameters: spellbooks, number of spellbooks, position_title,
 **             choice, output_file
 *********************************************************************/
void print_spellbooks_by_num_pages(spellbook* spellbooks,
                      int num_spellbooks,
                      string position_title,
                      int print_choice,
                      string output_file ){
  if(print_choice==1){
    for(int i=0; i<num_spellbooks; i++){
      // check for evil spell
      bool has_evil_spell = false;
      for(int j=0; j<spellbooks[i].num_spells; j++){
        if(spellbooks[i].s[j].effect == "poison" or
           spellbooks[i].s[j].effect == "death" ){
          has_evil_spell = true;
        }
      }
      if(position_title!="Student"){
        cout << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
      }
      else{
        if (has_evil_spell == false){
          cout << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
        }
      }
    }
  }
  else{ // print to file
    fstream outf;
    outf.open(output_file, ios::app);

    for(int i=0; i<num_spellbooks; i++){
      // check for evil spell
      bool has_evil_spell = false;
      for(int j=0; j<spellbooks[i].num_spells; j++){
        if(spellbooks[i].s[j].effect == "poison" or
           spellbooks[i].s[j].effect == "death" ){
          has_evil_spell = true;
        }
      }
      if(position_title!="Student"){
        outf << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
      }
      else{
        if (has_evil_spell == false){
          outf << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
        }
      }
    }
    outf.close();
  }
}


/*********************************************************************
 ** Function: print_spellbooks_by_avg_success_rate
 ** Description: print out spellbooks by average success rate
 ** Parameters: spellbooks, number of books, position, choice,
 **             output file
 *********************************************************************/
void print_spellbooks_by_avg_success_rate(spellbook* spellbooks,
                      int num_spellbooks,
                      string position_title,
                      int print_choice,
                      string output_file ){
  if(print_choice==1){
    for(int i=0; i<num_spellbooks; i++){
      // check for evil spell
      bool has_evil_spell = false;
      for(int j=0; j<spellbooks[i].num_spells; j++){
        if(spellbooks[i].s[j].effect == "poison" or
           spellbooks[i].s[j].effect == "death" ){
          has_evil_spell = true;
        }
      }
      if(position_title!="Student"){
        cout << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
      }
      else{
        if (has_evil_spell == false){
          cout << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
        }
      }
    }
  }
  else{ // print to file
    fstream outf;
    outf.open(output_file, ios::app);

    for(int i=0; i<num_spellbooks; i++){
      // check for evil spell
      bool has_evil_spell = false;
      for(int j=0; j<spellbooks[i].num_spells; j++){
        if(spellbooks[i].s[j].effect == "poison" or
           spellbooks[i].s[j].effect == "death" ){
          has_evil_spell = true;
        }
      }
      if(position_title!="Student"){
        outf << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
      }
      else{
        if (has_evil_spell == false){
          outf << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
        }
      }
    }
    outf.close();
  }
}



/*********************************************************************
 ** Function: print_spells_by_effect
 ** Description: print spells grouped by their effect
 ** Parameters: spellbooks, num books, position title, choice,
 **             output file
 *********************************************************************/
void print_spells_by_effect(spellbook* spellbooks,
                            int num_spellbooks,
                            string position_title,
                            int print_choice,
                            string output_file ){
   if(print_choice==1){
     for(int i=0; i<5; i++){
       for(int j=0; j<num_spellbooks; j++){
         for(int k=0; k<spellbooks[j].num_spells; k++){
           if(i==0 and spellbooks[j].s[k].effect == "fire"){
             cout << "fire  " << spellbooks[j].s[k].name << endl;
           }
           else if(i==1 and spellbooks[j].s[k].effect == "bubble"){
             cout << "bubble " << spellbooks[j].s[k].name << endl;
           }
           else if(i==2 and spellbooks[j].s[k].effect == "memory_loss"){
             cout << "memory_loss " << spellbooks[j].s[k].name << endl;
           }
           else if(i==3 and spellbooks[j].s[k].effect == "death"
                   and position_title!="Student"){
             cout << "death " << spellbooks[j].s[k].name << endl;
           }
           else if(i==4 and spellbooks[j].s[k].effect == "poison"
                   and position_title!="Student"){
             cout << "poison " << spellbooks[j].s[k].name << endl;
           }
         }
       }
     }
   }
   else{ // print to file
    fstream outf;
    outf.open(output_file, ios::app);
    for(int i=0; i<5; i++){
      for(int j=0; j<num_spellbooks; j++){
        for(int k=0; k<spellbooks[j].num_spells; k++){
          if(i==0 and spellbooks[j].s[k].effect == "fire"){
            outf << "fire  " << spellbooks[j].s[k].name << endl;
          }
          else if(i==1 and spellbooks[j].s[k].effect == "bubble"){
            outf << "bubble " << spellbooks[j].s[k].name << endl;
          }
          else if(i==2 and spellbooks[j].s[k].effect == "memory_loss"){
            outf << "memory_loss " << spellbooks[j].s[k].name << endl;
          }
          else if(i==3 and spellbooks[j].s[k].effect == "death"
                  and position_title!="Student"){
            outf << "death " << spellbooks[j].s[k].name << endl;
          }
          else if(i==4 and spellbooks[j].s[k].effect == "poison"
                  and position_title!="Student"){
            outf << "poison " << spellbooks[j].s[k].name << endl;
          }
        }
      }
    }
    outf.close();
   }
}

























