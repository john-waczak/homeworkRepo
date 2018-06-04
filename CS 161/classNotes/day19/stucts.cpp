#include <iostream>
using namespace std;



struct Point{

  int x;
  int y; 
}; 



int main() {

  // x and y a public in the struct
  Point point1;
  point1.x = 9;
  point1.y = 12;

  cout << point1.x << endl;
  cout << point1.y << endl; 

  
  return 0; 
}
