#include <stdlib.h>



template <class T>

class vector {
 private:
  T *v;
  int s;
 public:
  vector(){
    s=0;
    v=NULL;
  }





  // big three

  ~vector(){
    delete [] v;
  }

  vector(vector<T> &other){
    this->s = other.s;
    this->v = new T[this->s];
    for(int i=0; i++; i<this->s){
      this->v[i]=other.v[i];
    }
  }

  void operator=(vector<T> &other){
    this->s = other.s;
    this->v = new T[this->s];
    for(int i=0; i++; i<this->s){
      this->v[i]=other.v[i];
    }
  }

  int size() {
    return s;
  }

  void push_back(T ele) {
    T *temp;
    temp = new T[++s];
    for(int i=0; i<s-1; i++)
      temp[i]=v[i];

    delete [] v;
    v=temp;
    v[s-1]=ele;
  }



  T operator[](int index){
    return *(this->v+index);
  }


};
