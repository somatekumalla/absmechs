#include "stdafx.h"
#include "MyVector.h"

// initialize with a list
Vector::Vector(std::initializer_list<double> lst)
  : elem{ new double[lst.size()] },
  sz{ (int)/* cast required, size_t */ lst.size() }
{
  std::copy(lst.begin(), lst.end(), elem); // std::copy needs <algorithm> header
  // Error, C4996 : std::copy::_Unchecked_iterators::..call to 
  // std::copy with parameters that may be unsage ..to disable 
  // use -D_SCL_SECURE_NO_WARNINGS.See doc on how to use 
  // VC++ 'Checked Iterators'
  /**********************************************************
  In solution explorer, right click the project, select "properties".
  The project property page will open. Expand the ">C/C++" entry in
  the tree on the left and select "Preprocessor" under that. The top
  entry in the right pane should be "Preprocessor Definitions". In
  that edit box, add _SCL_SECURE_NO_WARNINGS,
  **********************************************************/
}

void Vector::push_back(double)
{
  // implementation in 13.6.4.3
}

int Vector::size() const
{
  return sz;
}

// copy constructor
Vector::Vector(const Vector& a)
  : sz{ a.sz }, elem{ new double[sz] } {
  for (int i = 0; i < a.size(); ++i)
  {
    elem[i] = a.elem[i];
  }
}

// copy assignment operator - returns a reference to an instance
// of Vector and takes a const reference to a Vector as parameter
// and the symbol is "="
Vector& Vector::operator=(const Vector& a)
{
  /*sz = a.size();
  elem = new double[a.size()];
  return *this;*/
  // allocated memory and initialize the array of doubles
  double *p = new double[a.size()];
  for (int i = 0; i < a.size(); ++i)
  {
    p[i] = a.elem[i];
  }
  // delete old elements
  delete[] elem;
  // assign "elem" to new array
  elem = p;
  sz = a.size();
  return *this;

}

// move constructor - copy contents of "a" to newly created Vector
// and remove "elem" and set "sz" 
Vector::Vector(Vector&& a) 
  : elem {a.elem}, sz {a.sz}
{
  a.elem = nullptr;
  a.sz = 0;
}


// move assignment
Vector& Vector::operator=(Vector&& a)   
{
  double *p = new double[a.sz];
  for (int i = 0; i < a.sz; ++i)
  {
    p[i] = a.elem[i];
  }
  delete[] elem;
  elem = p;
  sz = a.sz;

  delete[] a.elem;
  a.elem = nullptr;
  a.sz = 0;

  return *this;
}