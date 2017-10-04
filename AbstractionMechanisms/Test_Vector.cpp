#include "stdafx.h"
#include "MyVector.h"
#include <boost\test\unit_test.hpp>


BOOST_AUTO_TEST_SUITE(abs_mech_ts)

BOOST_AUTO_TEST_CASE(vector_constructors)
{

  Vector v{ 5 }; // Note : uses Vector(std::initializer_list<double>) as constructor

  BOOST_CHECK(v.size() == 1);
  BOOST_CHECK(v[0] == 5);
  BOOST_CHECK(v[v.size() - 1] == 5);

}

BOOST_AUTO_TEST_CASE(vector_constructors2)
{

  Vector v(5); // Note : uses Vector(int s) as constructor

  BOOST_CHECK(v.size() == 5);
  BOOST_CHECK(v[0] == 0);
  BOOST_CHECK(v[v.size() - 1] == 0);

}


BOOST_AUTO_TEST_CASE(vector_initializer_list)
{
  Vector v{ 1,2,3,4,5 }; // v has five elements
  Vector v2{ 1.23, 3.45, 6.7, 8 };

  BOOST_CHECK(v[0] == 1);
  BOOST_CHECK(v[4] == 5);
  BOOST_CHECK_EQUAL(v.size(), 5);

  BOOST_CHECK(v2[1] == 3.45);
  BOOST_CHECK_EQUAL(v2[0], 1.23);
}


BOOST_AUTO_TEST_CASE(vec_copy_const)
{
  Vector x = Vector(10);
  Vector z = Vector(10);

  for (int i = 0; i < x.size(); ++i)
  {
    x[i] = 100 + 2 * i * i;
  }

  z = x;

  BOOST_CHECK(x[1] == 102);
  BOOST_CHECK(x.size() == 10);
  BOOST_CHECK(z.size() == 10);
  BOOST_CHECK(z[2] == 108);
  BOOST_CHECK(z[3] == 118);
  BOOST_CHECK(z[5] == 150);
}


BOOST_AUTO_TEST_CASE(vec_move_assignment)
{
  Vector x = Vector(10);
  Vector y = Vector(10);

  for (int i = 0; i < x.size(); ++i)
  {
    x[i] = 100 + 2 * i * i;
  }

  y = std::move(x);

  BOOST_CHECK(y[1] == 102);
  BOOST_CHECK(y.size() == 10);
  BOOST_CHECK(x.size() == 0);

}

BOOST_AUTO_TEST_CASE(vec_move_const)
{
  Vector x = Vector(10);

  for (int i = 0; i < x.size(); ++i)
  {
    x[i] = 100 + 3 * i * i;
  }

  Vector y = Vector(std::move(x));

  BOOST_CHECK(y[1] == 103);
  BOOST_CHECK(y[3] == 127);
  BOOST_CHECK(x.size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
