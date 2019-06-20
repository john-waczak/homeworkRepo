#include <iostream>
#include "my_array.hpp"

using namespace std;







int main(){

  int size;
  cout << "Enter a value for the size of your random array: " << endl;
  cin >> size;
  bool valid_pick = false;
  Myarray A;
  while(!valid_pick){
    try{
      Myarray B(size);
      valid_pick = true;
      A = B;
    }
    catch(std::invalid_argument &e){
      cout << e.what() << endl;
      cout << "Please enter a new size: " << endl;
      cin >>size;
    }
  }

  Myarray B = A;
  mergeSort(A, B);
  for(int i=0; i<A.size(); i++){
    cout << A[i] << " " << B[i] << endl;
  }

  return 0;
}
