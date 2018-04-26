#include<iostream>
using std::cout;
using std::cin;
using std::endl;


/*********************************************************************
** Author: John Waczak
** Date: 4/5/2018
** Description: A program to determine how to represent value in cents
** from 0 to 99 in least number of coins.
*********************************************************************/

int main()
{
  int cents, pennies, nickels, dimes, quarters; // for money
  int q, r; // q for quotient and r for remainder

  cout << "Please enter an amount in cents less than a dollar." << endl;
  cin >> cents;

  // figure out number of quarters
  q = cents/25;
  r = cents%25;
  quarters = q;

  // figure out number of dimes
  q = r/10;
  dimes = q;
  r = r%10;

  // figure out number of nickels
  q = r/5;
  nickels = q;
  r = r%5;

  // the rest should be in pennies
  pennies = r;

  // Display the results:
  cout << "Your change will be" << endl;
  cout << "Q: " << quarters << endl;
  cout << "D: " << dimes << endl;
  cout << "N: " << nickels << endl;
  cout << "P: " << pennies << endl;

  return 0;
}
