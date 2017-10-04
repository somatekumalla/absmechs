#pragma once

#include <vector>


class Point {
public:
Point(double xx, double yy) : x {xx}, y {yy} {}

// copy constructor
Point(const Point& p) : x {p.getx()}, y {p.gety()} {}

// default constructor
Point() : Point(0,0) {}


double getx() const { return x;}
double gety() const { return y;}

~Point() {}

// copy assignment operator
Point operator=(Point p) { x = p.getx(), y = p.gety(); return *this; }
private:
double x, y;
};


class Shape {

public:
  virtual Point center() const = 0; // pure virtual function
  virtual void move(Point to) = 0;
  virtual void draw() const = 0;
  virtual void rotate(int angle) = 0;
  virtual ~Shape() {} // destructor

  //Shape(const Shape& ) = delete; // no copy operations
  //Shape& operator=(const Shape& ) = delete;

  //Shape(Shape&& ) = delete; // no move operations
  //Shape& operator=(Shape&& ) = delete;

};


class Circle : public Shape {
public:
  Circle(Point p, int rr); // constructor

  // Point center() const { return Point(x.getx(), x.gety()); }
  Point center() const { return x; }
  void move(Point to) { x = to; }
  void draw() const;
  void rotate(int) {} // nice simple algorithm

int get_radius() const { return r;}
~Circle() {}

private:
  Point x; // center
  int r; // radius

};


class Smiley : public Circle { // use the circle as the base for a face

public:
Smiley(Point p, int r) : Circle(p,r), mouth(nullptr) {}

~Smiley()
{
  delete mouth;
  for ( auto p : eyes) delete p;
}


void move(Point to);
void draw() const;
void rotate(int);

void add_eye(Shape* s) {eyes.push_back(s); }
void set_mouth(Shape* s);
virtual void wink(int i); // wink eye number

private:
std::vector<Shape*> eyes; // usually two eyes
Shape* mouth;

};