#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Author: John Waczak
** Date:  4/5/2018
** Description: A simple program to calculate and display the average
** of five numbers.
*********************************************************************/
int main()
{
  double num1, num2, num3, num4, num5, average;
  cout << "Please enter five numbers." << endl; //ask user for numbers

  cin >> num1;
  cin >> num2;
  cin >> num3;
  cin >> num4;
  cin >> num5;

  average = (num1 + num2 + num3 + num4 + num5 )/5; //calculate average
  cout << "The average of those numbers is:" <<endl; //display result
  cout << average << endl;

  return 0;
}
