#pragma once
#include "MyVector.h"
#include <list>



// Abstract class - A class with a pure virtual function - it MUST be defined 
// by some class derived from the Abstract class
class Container {
public:
  virtual double& operator[](int i) = 0; // pure virtual function ( " = 0; " syntax )
  virtual int size() const = 0; // const member function, pure virtual function
  virtual ~Container() {}; // destructor
};


class Vector_container :public Container { // Vector_container implements Container
  Vector v; // include "MyVector.h"
public:
  Vector_container(int s) : v(s) {} // Vector of s elements
  Vector_container(std::initializer_list<double>); // initialize with a list
  ~Vector_container() {}

  double& operator[](int i) { return v[i]; }
  int size() const { return v.size(); }

};

class List_container : public Container { // list_container implements Container
  std::list<double> ld; // include <list>
public:
  List_container() {} // empty list
  List_container(std::initializer_list<double>);
  double& operator[](int i);
  int size() const { return ld.size(); }
};