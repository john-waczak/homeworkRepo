#ifndef TAXICAB_HPP
#define TAXICAB_HPP


class Taxicab{

private:
  int x;
  int y;
  int dist; 
public:
  Taxicab(); 
  Taxicab(int, int);

  int getX();
  int getY();
  int getDistanceTraveled();

  void moveX(int);
  void moveY(int); 

};


#endif
