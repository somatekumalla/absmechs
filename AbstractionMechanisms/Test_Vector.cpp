#include "stdafx.h"
#include "MyVector.h"
#include <boost\test\unit_test.hpp>


BOOST_AUTO_TEST_SUITE(abs_mech_ts)

BOOST_AUTO_TEST_CASE(vector_constructors)
{
  
  Vector v {5}; // Note : uses Vector(std::initializer_list<double>) as constructor

  BOOST_CHECK( v.size() == 1);
  BOOST_CHECK( v[0] == 5);
  BOOST_CHECK( v[v.size() - 1] == 5);  
  
}

BOOST_AUTO_TEST_CASE(vector_constructors2)
{

  Vector v (5); // Note : uses Vector(int s) as constructor

  BOOST_CHECK(v.size() == 5);
  BOOST_CHECK(v[0] == 0);
  BOOST_CHECK(v[v.size() - 1] == 0);

}


BOOST_AUTO_TEST_CASE(vector_initializer_list)
{
  Vector v  {1,2,3,4,5}; // v has five elements
  Vector v2  {1.23, 3.45, 6.7, 8};

BOOST_CHECK(v[0] == 1);
BOOST_CHECK(v[4] == 5);
BOOST_CHECK_EQUAL(v.size(), 5);

BOOST_CHECK(v2[1] == 3.45);
BOOST_CHECK_EQUAL(v2[0], 1.23);
}

BOOST_AUTO_TEST_SUITE_END()
