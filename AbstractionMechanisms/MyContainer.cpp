#include "stdafx.h"
#include "MyContainer.h"
#include <stdexcept>

Vector_container::Vector_container(std::initializer_list<double> lst)
  : v{lst}
{
}

List_container::List_container(std::initializer_list<double> lst) : ld {lst}
{
}

double& List_container::operator[](int i)
{
  for (auto x : ld) {
    if ( i == 0 ) return x;
    --i;
  }
  throw std::out_of_range("List container"); // include <stdexcept> for out_of_range
}
