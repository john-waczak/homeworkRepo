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

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;


bool enough_args_given(int argc);

int main(int argc, char* argv[]){

  // check for enough arguments
  if(!enough_args_given(argc)) return 1;
  //


  return 0;
}

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
