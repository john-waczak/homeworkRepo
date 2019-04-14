/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: John Waczak
 ** Date: 4/11/2017
 ** Description: Main program file for the Wizard Spellbook Catalog
 ** Input: wizards.txt spellbooks.txt
 ** Output: Sorted spells printed to stdout or file.
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

int main(int argc, char** argv){

  // check for enough arguments
  if(!enough_args_given(argc)) return 1;
  int num_files = argc-1;

  // open files and check that open was successful
  fstream*  files = open_files(argv);
  if(!files_opened_succesfully(files, num_files)) return 1;

  // get number of wizards and spellbooks
  int num_wizards;
  int num_spellbooks;
  files[0] >> num_wizards;
  files[1] >> num_spellbooks;

  // create wizards and spellbooks structs from files
  wizard* wizards = create_wizard_list(num_wizards);
  spellbook* spellbooks = create_spellbooks(num_spellbooks);

  // populate wizards and spellbooks with info from files
  get_wizard_data(wizards, num_wizards, files[0]);
  get_spellbook_data(spellbooks, num_spellbooks, files[1]);

  // prompt for password
  int wizard_index  = login(wizards, num_wizards);
  if (wizard_index == -1){
    cout << "Error: exceeded allowed attemtps." << endl;
    return 1;
  }

  // print wizard info
  print_wizard_info(wizards, wizard_index);


  // sort and  print/write to file
  int choice = 0;
  while(true){
    choice = prompt_for_sort();
    if(choice == 4) break; // deal with quit case before asking how to print
    int print_choice = screen_or_file();
    string output_file = "";
    if(print_choice == 2){
      cout << "Please provide desired filename: " << endl;
      cin >> output_file;
    }


    switch (choice){
      case 1:
        cout << "\n";
        sort_num_pages(spellbooks, num_spellbooks);
        print_spellbooks_by_num_pages(spellbooks,
                         num_spellbooks,
                         wizards[wizard_index].position_title,
                         print_choice,
                         output_file);
        cout << "\n";
        break;
      case 2:
        cout << "\n";
        print_spells_by_effect(spellbooks,
                              num_spellbooks,
                              wizards[wizard_index].position_title,
                              print_choice,
                              output_file );
        cout << "\n";
        break;
      case 3:
        cout << "\n";
        sort_average_success(spellbooks, num_spellbooks);
        print_spellbooks_by_avg_success_rate(spellbooks,
                                      num_spellbooks,
                                      wizards[wizard_index].position_title,
                                      print_choice,
                                      output_file);
        cout << "\n";
        break;
     }
  }


  // close files and deallocate memory
  delete_info(&wizards, num_wizards, &spellbooks, num_spellbooks);
  close_files(files);
  return 0;
}




