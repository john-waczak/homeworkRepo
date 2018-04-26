#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

  int numNums;
  cout << "Please enter the number of values you would like to average" << endl;
  cin >> numNums;

  double sum = 0; 
  for(int i=0; i<numNums; i++){
    double num;
    cout << "Please enter a number" << endl;
    cin >> num;
    sum += num; 
  }

  cout << "The average is: " << sum/(static_cast<double>(numNums)) << endl; 
  return 0; 
}
