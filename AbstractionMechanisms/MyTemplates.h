#pragma once

#include <stdexcept> // std::out_of_range exception
#include <iterator> // std::begin(Container c) and std::end(Container c)

namespace st1 { // use namespace for templates
  // Exception class
  class Negative_size {};

  template<typename T>
  class Vector {
  private:
    T *elem; // elem points to an array of "sz" elements of type "T"
    int sz;

  public:
    Vector(int s); // constructor : establish invariant, acquire resources
    ~Vector() { delete[] elem; } // destructor : release resources

    // copy and move operations

    T& operator[](int i);
    const T& operator[](int i) const;
    int size() const { return sz; }
    T* begin();
    T* end();

    Vector(const Vector<T>&); // copy constructor
    Vector<T>& operator=(const Vector<T>&); // copy assignment

  }; // end class Vector

  template<typename T>
  Vector<T>::Vector(int s)
  {
    if (s < 0) throw Negative_size{};
    elem = new T[s];
    sz = s;
  }

  template<typename T>
  const T& Vector<T>::operator[](int i) const
  {
    if (i < 0 || size() <= i)
      throw std::out_of_range{ "Vector::operator[]" };
    return elem[i];
  }

  template<typename T>
  T& Vector<T>::operator[](int i)
  {
    return elem[i];
  }

  // To support the range-for loop for our Vector<T> we must
  // define begin() and end() operations
  template<typename T>
  T* Vector<T>::begin()
  {
    return &elem[0]; // pointer to first element
  }

  template<typename T>
  T* Vector<T>::end()
  {
    return begin() + size(); // pointer to one-past-last element
  }

  // Vector(const Vector<T>&); // copy constructor
  template<typename T>
  Vector<T>::Vector(const Vector<T>& v)
    : elem{ new T[v.size()] }, sz{ v.size() }
  {
    for (int i = 0; i < sz; ++i)
    {
      elem[i] = v[i];
    }
  }


  // Vector<T>& operator=(const Vector<T>&); // copy assignment
  template<typename T>
  Vector<T>& Vector<T>::operator=(const Vector<T>& v)
  {
    T* p = new T[v.size()];

    for (int i = 0; i < v.size(); ++i)
    {
      p[i] = v[i];
    }

    delete[] elem;
    elem = p;
    sz = v.size();
    return *this;
  }

template<typename T>
T* begin(Vector<T>& x)
{
  return &x[0]; // pointer to first element
}

template<typename T>
T* end(Vector<T>& x)
{
  return x.begin() + x.size(); // pointer to one past last element
}



// Function Templates
template<typename Container, typename Value>
Value sum( Container& c, Value v)
{
  for (auto& x : c)
  {
    v += x;
  }
   
  return v;
}


} // end of namespace st1

