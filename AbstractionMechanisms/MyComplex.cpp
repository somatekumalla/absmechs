#include "stdafx.h" // Pre-compiled headers
#include "MyComplex.h"

complex & complex::operator*=(complex z)
{  
  // formula for complex multiplication -
  // (a + ib) * (c + id) = ac + iad + ibc + i*i*bd


  double t_re = re*z.real() - im*z.imag();
  double t_im = re*z.imag() + im*z.real();
  re = t_re, im = t_im;

  return *this;
}

complex & complex::operator/=(complex z)
{
  // (a + ib)(c - id) / (c + id)(c - id)
  // (ac + bd + i(-ad + bc)) / c*c + d*d

  double t_div = (z.real()*z.real() + z.imag()*z.imag());
  double t_re = (re*z.real() + im*z.imag()) / t_div;
  double t_im = (im*z.real() - re*z.imag()) / t_div;
  re = t_re, im = t_im;

  return *this;
}


complex operator+(complex a, complex b) { return a += b; }

complex operator-(complex a, complex b) { return a -= b; }

// unary minus
complex operator-(complex a) { return{ -a.real(), -a.imag() }; }

complex operator*(complex a, complex b) { return a *= b; }

complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) // equal
{
  return a.real() == b.real() && a.imag() == b.imag();
}


bool operator!=(complex a, complex b) // not equal
{
  return !(a == b);
}