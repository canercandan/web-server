#include <cppunit/TestAssert.h>
#include "FluxStringTest.h"

void	FluxStringTest::setUp()
{
  _message = "aaaaa";
  _flux = new FluxString(_message);
}

void	FluxStringTest::tearDown()
{}

void	FluxStringTest::testNextString()
{
  CPPUNIT_ASSERT(_flux->nextString() == _message);
}
