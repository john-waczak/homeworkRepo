/******************************************************
 ** Program: linked_list.hpp
 ** Author: John Waczak
 ** Date: 06/09/2019
 ** Description: header / implementation file for list
 ******************************************************/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include "linked_list_node.hpp"

using std::cout;
using std::endl;
using std::cin;


template <class T>



class Linked_List{
private:
  unsigned int length;
  Linked_List_Node<T> *first;
  Linked_List_Node<T> *last; // I am including this to make push_back easier.

public:
  /*********************************************************************
   ** Function: Linked_List
   ** Description: Constructor
   *********************************************************************/
  Linked_List(){
    this->length = 0;
    this->first = NULL;
    this->last = NULL;
  }



  /*********************************************************************
   ** Function: ~Linked_List
   ** Description: Destructor
   *********************************************************************/
  ~Linked_List(){
    for(unsigned int i=0; i<this->length; i++){
      Linked_List_Node<T> *temp;
      temp = this->first;
      this->first = this->first->next;
      delete temp;
    }
  }


  /*********************************************************************
   ** Function: get_length(0)
   ** Description: returns length of linked list
   *********************************************************************/
  int get_length(){
    return this->length;
  }


  /*********************************************************************
   ** Function: print
   ** Description: prints out the linked list
   *********************************************************************/
   void print(){
    Linked_List_Node<T> *temp;
    temp = this->first;
    while(temp!=NULL){
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }




  /*********************************************************************
   ** Function: clear
   ** Description: deletes contents of list and sets size to zero
   *********************************************************************/
  void clear(){
    for(unsigned int i=0; i<this->length; i++){
      Linked_List_Node<T> *temp;
      temp = this->first;
      this->first = this->first->next;
      delete temp;
    }
    this->first = NULL;
    this->last = NULL;
    this->length=0;
  }



  /*********************************************************************
   ** Function: push_front
   ** Description: add value to the front of linked list
   ** Parameters: val
   *********************************************************************/
  unsigned int push_front(T val){
    Linked_List_Node<T> *temp = new Linked_List_Node<T>;
    temp->val = val;
    temp->next = this->first;
    if(this->first == NULL){
      this->first = temp;
      this->last = temp;
    }
    else{
      this->first = temp;
    }
    this->length++;
    return this->length;
  }


  /*********************************************************************
   ** Function: push_back
   ** Description: add value to back of linked list
   ** Parameters: val
   *********************************************************************/
  unsigned int push_back(T val){
    Linked_List_Node<T> *temp = new Linked_List_Node<T>;
    temp->val = val;
    temp->next = NULL;
    if(this->first == NULL){
      this->first = temp;
      this->last = temp;
      //temp = NULL;
    }
    else{
      this->last->next = temp; // update tail with address to new tail
      this->last = temp;
    }
    this->length ++; // increase the length by 1
    return this->length;
  }


  /*********************************************************************
   ** Function: insert
   ** Description: add value at index
   ** Parameters: val, index
   *********************************************************************/
  unsigned int insert(T val, unsigned int index){
    Linked_List_Node<T> *left;
    Linked_List_Node<T> *new_node = new Linked_List_Node<T>;

    new_node->val = val;
    left = this->first;

    for(unsigned int i=0; i< index-1; i++){
      left = left->next;
    }
    new_node->next = left->next;
    left->next = new_node;

    this->length++;
    return this->length;
  }




  /*********************************************************************
   ** Function: swap
   ** Description: swap position of two nodes by exchanging pointers
   ** Parameters: index1, index2
   *********************************************************************/
  void swap(unsigned int index1, unsigned int index2){
    if(index1 != index2 && this->length >= 2){
      Linked_List_Node<T> *n1 = NULL;
      Linked_List_Node<T> *prev1 = NULL;
      Linked_List_Node<T> *n2 = NULL;
      Linked_List_Node<T> *prev2 = NULL;
      Linked_List_Node<T> *temp = this->first;


      // collect necessary pointers
      for(unsigned int i=0; i<this->length; i++){
        if(i == index1-1){
          prev1 = temp;
        }
        if(i == index1){
          n1 = temp;
        }
        if(i == index2-1){
          prev2 = temp;
        }
        if(i == index2){
          n2 = temp;
        }

        if(i != this->length-1){
          temp = temp->next;
        }
      }


      // swap values
      if(n1 != NULL && n2 != NULL){
        if(prev1 != NULL){
          prev1->next = n2;
        }
        if(prev2 != NULL){
          prev2->next = n1;
        }

        temp = n1->next;
        n1->next = n2->next;
        n2->next = temp;

        if(prev1 == NULL){
          this->first = n2;
        }

        if(prev2 == NULL){
          this->first = n1;
        }
      }


      // update last
      if(n1->next == NULL){
        this->last = n1;
      }

      if(n2->next == NULL){
        this->last = n2;
      }
    }
  }



  /*********************************************************************
   ** Function: getLength
   ** Description: returns length of a sub list starting at node
   ** Parameters: node
   *********************************************************************/
  unsigned int getLength(Linked_List_Node<T>* node){
    unsigned int i=0;
    while(node!=NULL){
      i++;
      node=node->next;
    }
    return i;
  }



  /*********************************************************************
   ** Function: merge
   ** Description: used for merge sort algorithm. Combine two lists.
   ** Parameters: head1, head2
   *********************************************************************/
  Linked_List_Node<T>* merge(Linked_List_Node<T> *&head1, Linked_List_Node<T> *&head2){

    Linked_List_Node<T> *newHead;
    // if one is null, return the other e.g. base case
    if(head1 == NULL){
      return head2;
    }
    else if(head2 == NULL){
      return head1;
    }

    // check the values
    if(head1->val < head2->val){
      newHead = head1;
      newHead->next = merge(head1->next, head2);
    }
    else{
      newHead = head2;
      newHead->next = merge(head1, head2->next);
    }
    return newHead;
  }



  /*********************************************************************
   ** Function: mergeSort
   ** Description: sort a linked list
   ** Parameters: pointer to a node reference called head
   *********************************************************************/
  void mergeSort(Linked_List_Node<T> *&head){
    if(head->next != NULL){
      Linked_List_Node<T> *head1;
      Linked_List_Node<T> *head2 = head;

      unsigned int len = getLength(head);
      // set head2 to the middle of the middle of list
      for(unsigned int i=0; i<len/2; i++){
        head1 = head2;
        head2 = head2->next;
      }
      head1->next = NULL; // reset head1;
      head1 = head; //make the half-way point null for head1
      mergeSort(head1);
      mergeSort(head2);
      head = merge(head1, head2);
    }
  }


  /*********************************************************************
   ** Function: sort_ascending
   *********************************************************************/
  void sort_ascending(){
    mergeSort(this->first);
  }



  /*********************************************************************
   ** Function: findMaxIndex
   ** Description: return index of maximum value for linked list
   ** Parameters: node pointer 
   *********************************************************************/
  unsigned int findMaxIndex(Linked_List_Node<T> *head){
    unsigned int maxIndex=0;
    T max = head->val;
    unsigned int len = getLength(head);
    for(unsigned int i=0; i<len; i++){
      if(head->val>max){
        maxIndex = i;
      }
      head = head->next;
    }
    return maxIndex;
  }



  /*********************************************************************
   ** Function: selectionSort
   ** Description: sort the linked list starting at index
   ** Parameters: index
   *********************************************************************/
  void selectionSort(unsigned int index){
    if(index == this->length){
      return;
    }
    Linked_List_Node<T> *temp = this->first;
    // set temp to start at index
    for(unsigned int i=0; i<index; i++){
      temp = temp->next;
    }
    unsigned int swapIndex = findMaxIndex(temp);
    if(swapIndex+index != index){
      this->swap(index, swapIndex+index);
    }
    selectionSort(index+1);
  }


  /*********************************************************************
   ** Function: sort_descending
   ********************************************************************/
  void sort_descending(){
    selectionSort(0);
  }


  /*********************************************************************
   ** Function: isPrime
   ** Description: check if a value is prime
   ** Parameters: val
   *********************************************************************/
  bool isPrime(T val){
    if(val <= 1){
      return false;
    }

    for(T i=2; i<val; i++){
      if(val%i==0){
        return false;
      }
    }
    return true;
  }



  /*********************************************************************
   ** Function: get_num_primes
   ** Description: compute number of primes in linked list
   *********************************************************************/
  unsigned int get_num_primes(){
    unsigned int numPrimes = 0;
    Linked_List_Node<T> *temp = this->first;
    while(temp != NULL){
      if(isPrime(temp->val)){
        numPrimes++;
      }
      temp = temp->next;
    }
    return numPrimes;
  }



  /*********************************************************************
   ** Function: getUserInput
   ** Description: ask user to add number to linked list
   *********************************************************************/
  void getUserInput(){
    cout << "Please enter a number: ";
    T input;
    cin >> input;
    while(cin.fail()){
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Error! Invalid input." << endl;
      cout << "Please enter a new number: ";
      cin >> input;
    }
    this->push_front(input);
  }




  /*********************************************************************
   ** Function: demoLinkedList
   *********************************************************************/
  void demoLinkedList(){
    this->getUserInput();
    bool getAnotherNumber = true;
    while(getAnotherNumber){
      char choice;
      cout << "Do you want another num (y or n): ";
      cin >> choice;
      if(choice == 'y'){
        this->getUserInput();
      }
      else if(choice == 'n'){
        getAnotherNumber = false;
      }
      else{
        cout << "Error! Invalid input." << endl;
        cin.clear();
        cin.ignore(256, '\n');
      }
    }

    char choice;
    cout << "Sort ascending or descending (a or d)? ";
    cin >> choice;
    if(choice == 'a'){
      this->sort_ascending();
      this->print();
      cout << "You have " << this->get_num_primes() << " prime number(s) in your list." << endl;;
    }
    else if(choice == 'd'){
      this->sort_descending();
      this->print();
      cout << "You have " << this->get_num_primes() << " prime number(s) in your list." << endl;;
    }
    else{
      cout << "Error! Invalid input" << endl;
      cin.clear();
      cin.ignore(256, '\n');
    }
  }



};

#endif
