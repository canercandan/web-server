#ifndef __FILEINFOTEST_H__
# define __FILEINFOTEST_H__

# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>
# include "FileInfo.h"

class	FileInfoTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(FileInfoTest);
  CPPUNIT_TEST(testIsGood);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testIsGood();
private:
  FileInfo*	_info;
};

#endif // !__FILEINFOTEST_H__
