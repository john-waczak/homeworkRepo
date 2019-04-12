#include <iostream>
#include <string>
#include <fstream>

#include "wizard_catalog.h"



// function prototypes
spellbook* create_spellbooks(int);
void get_spellbook_data(spellbook*, int, std::ifstream&);
spell* create_spells(int);
void get_spell_data(spell*, int, std::ifstream&);
void delete_info(wizard **, int, spellbook **, int);
