#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "MyContainer.h"
#include <boost\test\unit_test.hpp>

BOOST_AUTO_TEST_SUITE(abs_mech_ts)

BOOST_AUTO_TEST_CASE(Vector_container_01)
{
  Vector_container vc{ 1,2,3,4,5 };

  BOOST_CHECK_EQUAL(vc[0], 1);
  BOOST_CHECK_EQUAL(vc[2], 3);
  BOOST_CHECK_EQUAL(vc[4], 5);
}


BOOST_AUTO_TEST_CASE(List_container_01)
{
  List_container lc{ 1.0, 2.0, 3.0, 4.0, 5.0 };

  // std::cout << "lc[0] : " << lc[0] << ", lc[2] : " << lc[2] << std::endl; // include <iostream>


  BOOST_CHECK(std::abs(lc[0] - 1.0) < 0.00001); // include <cstdlib> and <cmath>
  BOOST_CHECK(std::abs(lc[2] - 3) < 0.00001);
  BOOST_CHECK(std::abs(lc[4] - 5) < 0.0001);
}

void use(Container& c)
{
  const int sz = c.size();

  for (int i = 0; i != sz; ++i)
  {
    std::cout << c[i] << " ";
  }
  std::cout << std::endl;
}

BOOST_AUTO_TEST_CASE(use_01)
{
  Vector_container vc{ 1,3,5,7,9 };
  List_container lc{ 2,4,6,8,10 };

  std::cout << "--- Begin, Test Case : use_01 ---\n";
  use(vc);
  BOOST_CHECK(vc[2] == 5);

  use(lc);
  BOOST_CHECK(std::abs(lc[2] - 6) < 0.00001);
  
  std::cout << "--- End, Test Case : use_01 ---\n";
}

  BOOST_AUTO_TEST_SUITE_END()


