#include<iostream>
#include<stdio.h>
using namespace std;


int main()
{
  double cost = 14.95;
  double sellFor;
  double profit;
  double profitPercent = 0.35;

  profit = cost * profitPercent;
  sellFor = cost + profit;

  printf("Circuit board price to make 35 percent profit is: %.2f\n", sellFor);
  return 0;
}
