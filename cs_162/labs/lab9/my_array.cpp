#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include "my_array.hpp"
using std::cout;
using std::endl;

Myarray::Myarray(){
  this->length=0;
  this->arry = NULL;
}

Myarray::Myarray(int size){
  if(size > 20){
    throw std::invalid_argument("You have entered an invalid array size");
  }


  else{
    this->length = size;
    this->arry = new int[size];
    for(int i=0; i<size; i++){
      int val = rand()%50;
      this->arry[i]=val;
    }
  }
}


Myarray::~Myarray(){
  this->length = 0;
  if(this->arry != NULL){
    delete [] this->arry;
  }
}

Myarray::Myarray(const Myarray &old_array){
  if(this != &old_array){
    this->length = old_array.length;
    this->arry = new int[old_array.length];
    for(int i=0; i<this->length; i++){
      this->arry[i] = old_array.arry[i];
    }
  }
}

Myarray& Myarray::operator=(const Myarray& other_array){
  if(this!= &other_array){
    this->length = other_array.length;
    this->arry = new int[other_array.length];
    for(int i=0; i<other_array.length; i++){
      this->arry[i] = other_array.arry[i];
    }
  }
  else{
    return *this;
  }
  return *this;
}


int& Myarray::operator[](int index){
  return this->arry[index];
}


int Myarray::size(){
  return this->length; 
}


void mergeSort(Myarray &A){
  mergeSort(A, 0, A.size()-1);
}

void mergeSort(Myarray &A, int low, int high){
  if(low >= high){
    return;
  }
  else{
    int mid = (low+high)/2;
    mergeSort(A, low, mid);
    mergeSort(A, mid+1, high);
    merge(A, low, mid, mid+1, high);
  }
}



void merge(Myarray &A, int left_low, int left_high, int right_low, int right_high){
  // sort the two sub arrays
  int length = A.size();
  Myarray temp(length);
  inf left = left_low;
  int right = right_low;
}



