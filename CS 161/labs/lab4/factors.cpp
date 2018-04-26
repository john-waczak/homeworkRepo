#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  int num;
  int sum = 0;

  cout << "Please enter a positive integer." << endl; 
  cin >> num;
  cout << endl; 
  cout << num << " has the following factors other than 1 and itself:" << endl; 

  for (int i = 2; i<num; i++){
    if (num %i == 0){
      cout<<"\t"<<i << endl;
      sum += i; 
    }
  }

  if(sum == 0)
    cout <<"\tNone" << endl;

  return 0; 
}
