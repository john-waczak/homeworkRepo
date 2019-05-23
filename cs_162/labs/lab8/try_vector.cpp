#include "./vector.h"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't
//be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;








int main (){
  vector<int> v;   //Our vector class
  std::vector<int> stdv; //Standard vector

  //Compare operation of our vector to std
  v.push_back(23);
  stdv.push_back(23);

  vector<int> u = v;
  vector<int> w;
  w=u;

  cout << "Our vector size: " << v.size() << endl;
  cout << "STL vector size: " << stdv.size() << endl;
  cout << "Copy constructor vector size: " << u.size() << endl;
  cout << "Assignment operator overload size: " << w.size() << endl;

  cout << v[0] << endl;
  cout << u[0] << endl;
  cout << w[0] << endl;

  return 0;
}
