#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{

  double cost, profitPercent, sellFor;
  cout << "Please enter cost per circuit board." << endl;
  cin >> cost;
  cout << "Please enter desired profit percentage." << endl;
  cin >> profitPercent;

  double profit = cost * profitPercent;
  sellFor = cost + profit;

  printf("Circuit board price for %.2f %% profit is $%.2f \n", profitPercent*100, sellFor );

  return 0;
}
