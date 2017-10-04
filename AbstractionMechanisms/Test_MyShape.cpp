#include "stdafx.h"

#include "MyShape.h"
#include "boost\test\unit_test.hpp"
#include <memory> // needed for std::unique_ptr

BOOST_AUTO_TEST_SUITE(abs_mech_ts)

BOOST_AUTO_TEST_CASE(mycircle_01)
{
Point p {2,3};
Circle c {p, 4};

BOOST_CHECK(p.getx() == 2 && p.gety() == 3);

c.draw();

BOOST_CHECK(c.get_radius() == 4);
}

BOOST_AUTO_TEST_CASE(mysmiley_01)
{
Point smiley_ctr {100,100};
//Smiley sm { smiley_ctr, 50};
//Smiley sm{ {100,100}, 50 };
Smiley *ps = new Smiley {smiley_ctr, 50};

// Circle mouth { Point {50,25}, 10 };
//Circle mouth { {50,25}, 10 };
Circle *m = new Circle { {50,25}, 10};

//sm.set_mouth( &mouth );
ps->set_mouth(m);

//Circle eye01 { {40,20}, 15};
//Circle eye02 { {60, 20}, 15};

Circle *e1 = new Circle{ { 40,20 }, 15 };
Circle *e2 = new Circle { {60,20}, 15 };

ps->add_eye( e1); 
ps->add_eye( e2 );

ps->draw();

delete ps, e1, e2, m;

// BOOST_CHECK(1 == 1); // dummy check
}

BOOST_AUTO_TEST_CASE(mysmiley_02_smartptr)
{
std::unique_ptr<Circle> m( new Circle {{50,25}, 10});
auto p = m.get();

BOOST_CHECK( p->get_radius() == 10);
BOOST_CHECK( p->center().getx() == 50);
BOOST_CHECK(p->center().gety() == 25);
}




BOOST_AUTO_TEST_SUITE_END()