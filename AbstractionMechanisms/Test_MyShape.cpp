#include "stdafx.h"

#include "MyShape.h"
#include "boost\test\unit_test.hpp"

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
Smiley sm{ {100,100}, 50 };

// Circle mouth { Point {50,25}, 10 };
Circle mouth { {50,25}, 10 };
sm.set_mouth( &mouth );

Circle eye01 { {40,20}, 15};
Circle eye02 { {60, 20}, 15};

sm.add_eye( &eye01 ); 
sm.add_eye( &eye02 );

sm.draw();

BOOST_CHECK(1 == 1); // dummy check
}

BOOST_AUTO_TEST_SUITE_END()