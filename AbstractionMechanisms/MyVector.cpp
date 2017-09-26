#include "stdafx.h"
#include "MyVector.h"

// initialize with a list
Vector::Vector(std::initializer_list<double> lst)
  : elem {new double[lst.size()]}, 
  sz {(int)/* cast required, size_t */ lst.size()}
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
