#ifndef WIZARD_CATALOG_H
#define WIZARD_CATALOG_H

#include<iostream>
#include<string>
#include<fstream>
using std::string;

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


// function prototypes
spellbook* create_spellbooks(int);
void get_spellbook_data(spellbook*, int, std::ifstream&);
spell* create_spells(int);
void get_spell_data(spell*, int, std::ifstream&);
void delete_info(wizard **, int, spellbook **, int);


#endif
