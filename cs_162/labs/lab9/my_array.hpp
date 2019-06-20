#ifndef MY_ARRAY_H
#define MY_ARRAY_H


class Myarray{
private:
  int *arry;
  int length;
public:
  Myarray();
  Myarray(int size);

  ~Myarray();
  Myarray(const Myarray &old_array);
  Myarray& operator=(const Myarray& other_array);
  int& operator[](int index);


  int size();

};


void mergeSort(Myarray &A);
void mergeSort(Myarray &A, int low, int high);
void merge(Myarray &A, int left_low, int left_high, int right_low, int right_high);

#endif
