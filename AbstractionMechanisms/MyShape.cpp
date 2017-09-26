#include "stdafx.h";

#include "MyShape.h";
#include <iostream>

Circle::Circle(Point p, int rr) : x {p}, r {rr} {}

void Circle::draw() const {
std::cout << "Circle::Draw() = " 
  << "Point : [" << x.getx() << ", " << x.gety() << "], Radius : ["
  << r << "]" << std::endl;
}


void Smiley::move(Point to) {
 Circle::move(to);
}

void Smiley::draw() const {
  Circle::draw();
  for (auto p : eyes) {
    p->draw();
  }
  mouth->draw();
}

void Smiley::rotate(int)
{
}

void Smiley::set_mouth(Shape * s)
{
  mouth = s;
}

void Smiley::wink(int i)
{
}
