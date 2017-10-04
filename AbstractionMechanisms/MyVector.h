#pragma once
#include <initializer_list> // std::initializer_list
#include <algorithm> // std::copy(..)
#include <utility> // std::move(..)

class Vector
{
private:
  double* elem; // elem points to an array of sz doubles
  int sz;

public:
  // constructor : acquire resources
  Vector(int s) : elem{ new double[s] }, sz{ s }
  {
    for (int i = 0; i != s; ++i) elem[i] = 0; // initialize elements
  }

  Vector(std::initializer_list<double>); // initialize with a list

  Vector(const Vector& a);  // copy constructor

  Vector& operator=(const Vector& a); // copy assignment

  void push_back(double); // add element at end increasing the size by one

  Vector(Vector&& a); // Move constructor

  Vector& operator=(Vector&& a); // Move assignment

  ~Vector() {
    delete[] elem;  // destructor : release resources
  }

  double& operator[](int i) { return elem[i]; }
  int size() const;
};