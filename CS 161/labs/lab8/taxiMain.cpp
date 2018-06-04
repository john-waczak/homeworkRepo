#include <iostream>
#include <algorithm> 
#include "Taxicab.hpp"
using namespace std; 


double findMean(int arr[], int arrLength){
  std::sort(arr, arr+arrLength);
  double median; 
  if (arrLength%2==0){
    double a = arr[arrLength/2-1];
    double b = arr[arrLength/2]; 
    median = (a+b)/2.0;
  }
  else{
    median = double(arr[arrLength/2]); // using integer division gives middle index
  }
  return median; 
}



int main(){

  Taxicab cab = Taxicab(1, 1);
  cab.moveX(12);
  cout << cab.getX() << endl;
  cout << cab.getY() << endl; 


  int arr1[5] = {1,2,3,4,5};
  int arr2[6] = {1,2,3,4,5,6};

  cout << findMean(arr1, 5) << endl;
  cout << findMean(arr2, 6) << endl;  
  return 0; 
}
