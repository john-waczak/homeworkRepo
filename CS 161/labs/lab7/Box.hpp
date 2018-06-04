#ifndef BOX_HPP
#define BOX_HPP

class Box{

private:
  double height;
  double width;
  double length; 
public:
  Box();
  Box(double, double, double);
  void set_height(double);
  void set_width(double);
  void set_length(double);
  double get_height();
  double get_width();
  double get_length(); 
  double get_volume();
  double get_SurfArea();  

};



#endif
