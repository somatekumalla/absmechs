#include "stdafx.h"

#include "MyTemplates.h"
#include <boost\test\unit_test.hpp>
#include <string> // needed for std::string
#include <iostream> // needed for std::cout


BOOST_AUTO_TEST_SUITE(abs_mech_ts)


BOOST_AUTO_TEST_CASE(tmpl_vec_01)
{
  st1::Vector<std::string> vs {5};

  /*for (int i = 0; i < vs.size(); ++i) {
    vs[i] = "string-" + i;
  }*/

  /*for (int i = 0; i < vs.size(); ++i) {
    std::cout << i << " = " << vs[i] << ", ";
  }*/

  BOOST_CHECK(vs[0] == "");
}


BOOST_AUTO_TEST_CASE(tmpl_vec_cpa_02)
{
  st1::Vector<int> vi {5};
  int init = 0;

  for (int i=0; i < vi.size(); ++i ) vi[i] = init++; // copy assignment

  // for (auto x : vi) std::cout << x << std::endl;

  BOOST_CHECK(vi[3] == 3);
}

// Test the Copy Assignment feature of Vector<T>
BOOST_AUTO_TEST_CASE(tmpl_vec_cpa_03)
{
  st1::Vector<std::string> vs {5};

  std::string mystr[] = { "zero", "one", "two", "three", "four", "five", "six" };

  for (int i = 0; i < vs.size(); ++i)
  {
    vs[i] = mystr[i]; // copy assignment feature being tested
  }

  // for (auto x : vs) std::cout << x << std::endl;

  BOOST_CHECK(vs[2] == "two");
}

// Test copy constructor
BOOST_AUTO_TEST_CASE(tmpl_vec_cc_04)
{
  st1::Vector<std::string> vs{ 5 };

  std::string mystr[] = { "zero", "one", "two", "three", "four", "five", "six" };

  for (int i = 0; i < vs.size(); ++i)
  {
    vs[i] = mystr[i]; // copy assignment feature being tested
  }

  // use copy constructor
  st1::Vector<std::string> vs2 {vs};

  BOOST_CHECK(vs2[2] == "two");
  BOOST_CHECK(vs2[3] == "three");
  BOOST_CHECK(vs2[4] == "four");
}


// Test Function Templates
BOOST_AUTO_TEST_CASE(tmpl_vec_fntmpl_04)
{
  int ii = 0;
  st1::Vector<int> vi {5};
  for (int i=0; i<vi.size(); ++i) vi[i] = 0;

  vi[1] = 100; vi[2] = 200;

   int si = st1::sum(vi, ii);

   BOOST_CHECK(si == 300);
}



BOOST_AUTO_TEST_SUITE_END()
