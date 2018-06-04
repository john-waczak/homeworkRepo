#ifndef PERSON_HPP
#define PERSON_HPP
#include <string> 

class Person{


private:
  std::string name;
  double age; 


public:
  Person(std::string, double);
  std::string getName();
  double getAge(); 


}; 






#endif
