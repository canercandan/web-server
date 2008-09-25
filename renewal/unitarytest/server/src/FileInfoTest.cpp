#include <cppunit/TestAssert.h>
#include "FileInfoTestFile.h"

void	FileInfoTestFile::setUp()
{
  _path = "../server.xml";
  _info = new FileInfo(_path);
}

void	FileInfoTestFile::tearDown()
{
  delete _info;
}

void	FileInfoTestFile::testIsGood()
{
  CPPUNIT_ASSERT(_info->isGood());
}

void	FileInfoTestFile::testGetPath()
{
  CPPUNIT_ASSERT(_info->getPath() == _path);
}

void	FileInfoTestFile::testGetType()
{
  CPPUNIT_ASSERT(_info->getType() == FileInfo::FILE);
}

void	FileInfoTestFile::testGetSize()
{
  CPPUNIT_ASSERT(_info->getSize() > 0);
}

void	FileInfoTestFile::testGetContent()
{
  CPPUNIT_ASSERT(!_info->getContent().empty());
}
