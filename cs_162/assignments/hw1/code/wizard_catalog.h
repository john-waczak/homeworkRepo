#ifndef WIZARD_CATALOG_H
#define WIZARD_CATALOG_H
#include <iostream>
#include <string>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;



// struct definitions

struct wizard{
  string name;
  int id;
  string password;
  string position_title;
  float beard_length;
};

struct spellbook{
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};

struct spell{
  string name;
  float success_rate;
  string effect;
};


// functions to deal with files
bool enough_args_given(int argc);
fstream* open_files(char** argv);
bool files_opened_succesfully(fstream* files, int num_files);
void close_files(fstream* files);


// functions to deal with structs
spellbook* create_spellbooks(int num_spellbooks);
wizard* create_wizard_list(int num_wizards);
void get_wizard_data(wizard* wizards, int num_wizards, fstream& wizard_file);
void get_spellbook_data(spellbook* spellbooks, int num_spellbooks, fstream& spellbooks_file);
spell* create_spells(int num_spells);
void get_spell_data(spell* spells, int num_spells, fstream& spellbook_file);
void delete_info(wizard** wizards, int num_wizards, spellbook** spellbooks, int num_spellbooks);
void delete_spells(spell* spells);


// functions to deal with login
int login(wizard* wizards, int num_wizards);
int attempt_login(wizard* wizards, int num_wizards);
int get_wizard_id_index(wizard* wizards, int num_wizards, int usr_id);
int check_password(wizard* wizards, int index, string usr_pass);


// functions for printing
void print_wizard_info(wizard* wizards, int index);
int prompt_for_sort();
int screen_or_file();

// sorting functions
void sort_num_pages(spellbook* spellbooks, int num_spellbooks);
void sort_average_success(spellbook* spellbooks, int num_spellbooks);

// printing/writing to file
void print_spellbooks_by_num_pages(spellbook* spellbooks,
                      int num_spellbooks,
                      string position_title,
                      int print_choice,
                      string output_file );


void print_spellbooks_by_avg_success_rate(spellbook* spellbooks,
                                          int num_spellbooks,
                                          string position_title,
                                          int print_choice,
                                          string output_file );



void print_spells_by_effect(spellbook* spellbooks,
                            int num_spellbooks,
                            string position_title,
                            int print_choice,
                            string output_file );


#endif
