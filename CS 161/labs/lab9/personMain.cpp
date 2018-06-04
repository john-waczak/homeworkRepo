#include <iostream>
#include <string>
#include <cmath> 
#include "person.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::sqrt;
using std::pow; 


double stdDev(Person*[], int); 

int main(){

  Person person1 = Person("Steve", 32.0);
  Person person2 = Person("Marty", 25.0);
  Person person3 = Person("Christine", 53.0);
  Person person4 = Person("John", 21.0); 

  Person* peopleArr[4] = {&person1, &person2, &person3, &person4};
  double Standard_Dev = stdDev(peopleArr, 4);
  cout << Standard_Dev << endl; 
  return 0; 
}


double stdDev(Person* people[], int numPeople){
  double stdDev;

  double N = double(numPeople);

  double x_bar =0.0;
  double xMinusX_bar2 = 0.0;

  for (int i = 0; i<numPeople; i++){
    double x_current = people[i]->getAge();
    x_bar += x_current; 
  }
  x_bar = x_bar/N; 

  for (int i = 0; i < numPeople; i++){
    xMinusX_bar2 += pow(people[i]->getAge()-x_bar, 2); 
  }
  stdDev = sqrt(xMinusX_bar2/N); 
  return stdDev; 
}
