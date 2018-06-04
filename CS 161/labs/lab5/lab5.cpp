#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;




double presentValue(double F, double r, double n){
  return F/pow((1+r), n); 
}


int main(){
 
  double goal = 10000.00;
  double baseRate =  0.01;

  for (int i=0; i<9; i++){
    cout << i << endl; 
    double rate = baseRate+0.005*i;
    cout << "Goal: " <<goal<< "\tRate: "<< rate << "\tPresent value: " << presentValue(goal, rate, 10) << endl; 
  }


  return 0;
}
