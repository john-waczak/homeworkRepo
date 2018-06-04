#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle{
private:
  double radius;
public:
  Circle();
  Circle(double);
  double calcArea();
  double calcPerimiter(); 
};
#endif  


#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car{

private:
  int year;
  std::string make;
  int speed;

public:
  Car();
  Car(int, std::string, int); 
  void accelerate(); 
  void deccelerate(); // by 5 mph each time 
  int get_speed(); 
  void set_speed(int); 
};

#endif 
 
