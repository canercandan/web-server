#include <cppunit/TestAssert.h>
#include "FileInfoTest.h"

void	FileInfoTest::setUp()
{
  _info = new FileInfo("../server.xml");
}

void	FileInfoTest::tearDown()
{
  delete _info;
}

void	FileInfoTest::testIsGood()
{
  CPPUNIT_ASSERT(_info->isGood());
}
