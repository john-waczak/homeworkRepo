/******************************************************
 ** Program: linked_list_node.hpp
 ** Author: John Waczak
 ** Date: 06/09/2019
 ** Description: header file for node
 ******************************************************/
#ifndef LINKED_LIST_NODE_HPP
#define LINKED_LIST_NODE_HPP

#include<iostream>

template <class T>

class Linked_List_Node{
public:
  T val;
  Linked_List_Node *next;
};



#endif
