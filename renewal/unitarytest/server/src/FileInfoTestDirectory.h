#ifndef __FILEINFOTESTDIRECTORY_H__
# define __FILEINFOTESTDIRECTORY_H__

# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>
# include "FileInfo.h"

class	FileInfoTestDirectory : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(FileInfoTestDirectory);
  CPPUNIT_TEST(testGetType);
  CPPUNIT_TEST(testGetListDir);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testGetType();
  void	testGetListDir();
private:
  FileInfo*	_info;
};

#endif // !__FILEINFOTESTDIRECTORY_H__
