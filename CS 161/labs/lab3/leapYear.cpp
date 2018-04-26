#include <iostream>

using namespace std;

bool isLeap(int year);

int main()
{
  int year;
  cout << "What year is it?" << endl;
  cin >> year;
  bool leap = isLeap(year);
  if (leap == true)
    cout << "Leap year --- 29 days in February" << endl;
  else
    cout << "Not a leap year --- 28 days in February" << endl;


  return 0;
}



bool isLeap(int year)
{
  if (year%4 == 0)
    {
      if (year%100 == 0 and year%400 !=0)
	return false;
      else if (year%100 == 0 and year%400 ==0)
	return true;
      else
	return true;
    }
  else
    return false;
}
