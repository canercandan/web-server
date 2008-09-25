#ifndef __FILEINFOTESTFILE_H__
# define __FILEINFOTESTFILE_H__

# include <string>
# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>
# include "FileInfo.h"

class	FileInfoTestFile : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(FileInfoTestFile);
  CPPUNIT_TEST(testIsGood);
  CPPUNIT_TEST(testGetPath);
  CPPUNIT_TEST(testGetType);
  CPPUNIT_TEST(testGetSize);
  CPPUNIT_TEST(testGetContent);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testIsGood();
  void	testGetPath();
  void	testGetType();
  void	testGetSize();
  void	testGetContent();
private:
  std::string	_path;
  FileInfo*	_info;
};

#endif // !__FILEINFOTESTFILE_H__
