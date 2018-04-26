#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  // produce two random integers in range 10 to 50
  srand(time(NULL));
  int x = rand()%40 + 11;
  int y = rand()%40 + 11;
  double ans;

  cout << "What is " << x << " + " << y << "?" << endl;
  cin >> ans;

  if (ans == x+y)
    cout << "Congratulations!" << endl;
  else
    cout << "Incorrect, " << x << " + " << y << "= " << x+y << endl;

  return 0;
}
