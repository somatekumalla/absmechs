// AbstractionMechanisms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include "MyComplex.h"

#define  BOOST_TEST_MODULE MyTest
#include <boost\test\unit_test.hpp>


// BOOST_AUTO_TEST_SUITE( AbsMechBoostTests)
BOOST_AUTO_TEST_SUITE( abs_mech_ts)

//void pr(std::string msg);
//void prc() { std::cout << std::string(25, '-') << std::endl; }
//void pr_complex(complex z);
//
//
//void run_tests();

//int main()
//{
//  run_tests();
//  return 0;
//}

int add(int i, int j) { return i + j; }

BOOST_AUTO_TEST_CASE(my_test)
{
  BOOST_CHECK(add(2, 2) == 4);

}

BOOST_AUTO_TEST_CASE(my_test_01)
{
  complex a{ 2.3 }; // construct {2.3,0.0} from 2.3
  // BOOST_CHECK( a.real() == 2.3);
  BOOST_CHECK_EQUAL(a.real(), 2.3);

}

BOOST_AUTO_TEST_CASE(my_test_02)
{
  complex a{ 1.0,2.0 };

  BOOST_CHECK_EQUAL(a.real(), 1.0);
  BOOST_CHECK_EQUAL(a.imag(), 2.0);

}

BOOST_AUTO_TEST_CASE(my_test_03)
{
  complex a;
  BOOST_CHECK_EQUAL(a.real(), 0.0);
  BOOST_CHECK_EQUAL(a.imag(), 0.0);

}

BOOST_AUTO_TEST_CASE(my_test_04)
{
  complex b{ 1.2,3.4 };
  complex c{ 5.6, 7.8 };
  c += b;
  BOOST_CHECK_EQUAL(c.real(), 6.8);
  BOOST_CHECK_EQUAL(c.imag(), 11.2);

}


//void run_tests_01();
//void run_tests_02();
//void run_tests_03();
//void run_tests_04();
//void run_tests_05();
//void run_tests_06();
//void run_tests_07();

//void run_tests() {
//  std::cout << "complex class -\n"; prc();
//  run_tests_01(); prc();
//  run_tests_02(); prc();
//  run_tests_03(); prc();
//  run_tests_04(); prc();
//  run_tests_05(); prc();
//  run_tests_06(); prc();
//  run_tests_07(); prc();
//}

//void run_tests_01() {
//
//  complex a{ 2.3 }; // construct {2.3,0.0} from 2.3
//  pr("complex a {2.3}; - ");
//  pr_complex(a);
//}
//
//void run_tests_02() {
//  complex a{ 1.0,2.0 };
//  pr("complex a {1.0,2.0}; - ");
//  pr_complex(a);
//}
//
//void run_tests_03() {
//  complex a;
//  pr("complex a; - ");
//  pr_complex(a);
//}
//
//void run_tests_04() {
//  complex b{ 1.2,3.4 };
//  complex c{ 5.6, 7.8 };
//  pr("b - "); pr_complex(b); pr("c - "); pr_complex(c);
//  c += b;
//  pr("c += b :"); pr_complex(c);
//}

BOOST_AUTO_TEST_CASE(my_test_05) {

  complex b{ 1.2,3.4 };
  complex c{ 5.6, 7.8 };

  c -= b;

  BOOST_CHECK(c.real() - 4.4 < 0.00001);
  BOOST_CHECK(c.imag() - 4.4 < 0.00001);
}

BOOST_AUTO_TEST_CASE(my_test_06) {
  complex a{ 1.0, 2.0 }, b{ 3.0, 4.0 };
  a *= b;
  BOOST_CHECK(a.real() - 5.0 < 0.00001);
  BOOST_CHECK(a.imag() - 10.0 < 0.00001);
}

BOOST_AUTO_TEST_CASE(my_test_07) {
  complex a{ 1.0, 2.0 }, b{ 3.0, 4.0 };
  a /= b;
  BOOST_CHECK(a.real() - 0.44 < 0.00001);
  BOOST_CHECK(a.imag() - 0.08 < 0.00001);
}

BOOST_AUTO_TEST_SUITE_END()

// Tools for this program
//void pr_complex(complex z) {
//  std::cout << "[re,img] : [" << z.real() << "," << z.imag() << "]\n";
//}

//void pr(std::string msg) { std::cout << msg; }