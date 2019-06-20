/******************************************************
 ** Program: main.cpp
 ** Author: John Waczak
 ** Date: 06/09/2019
 ** Description: driver file
 ******************************************************/

#include <iostream>
#include <string>

#include "linked_list_node.hpp"
#include "linked_list.hpp"

using namespace std;



int main(){
  /********* testing stuff **********/
  // Linked_List<int> test = Linked_List<int>();
  // test.push_front(2);
  // test.push_back(12);
  // test.push_front(3);
  // test.push_back(13);
  // test.insert(22, 1);
  // test.insert(-1, 2);
  // test.print();
  // test.swap(1,3);
  // test.print();
  // cout << "\n\n";
  // test.sort_ascending();
  // test.print();
  // test.sort_descending();
  // test.print();

  // cout << test.get_num_primes() << endl;
  char typeOfInt;
  cout << "Do you want to use ints or unsigned ints? (i or u): ";
  cin >> typeOfInt;
  if((typeOfInt != 'i' && typeOfInt != 'u') ||  cin.fail()){
    cout << "Error! Invalid input." << endl;
    exit(1);
  }

  if(typeOfInt == 'i'){
    Linked_List<int> l1 = Linked_List<int>();
    l1.demoLinkedList();
  }
  else{
    Linked_List<unsigned int> l1 = Linked_List<unsigned int>();
    l1.demoLinkedList();
  }

  return 0;
}
