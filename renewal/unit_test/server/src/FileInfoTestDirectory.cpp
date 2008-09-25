#include <cppunit/TestAssert.h>
#include "FileInfoTestDirectory.h"

void	FileInfoTestDirectory::setUp()
{
  _info = new FileInfo(".");
}

void	FileInfoTestDirectory::tearDown()
{
  delete _info;
}

void	FileInfoTestDirectory::testGetType()
{
  CPPUNIT_ASSERT(_info->getType() == FileInfo::DIR);
}

void	FileInfoTestDirectory::testGetListDir()
{
  bool	res(false);

  FileInfo::listDir&	list = _info->getListDir();

  for (FileInfo::listDir::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      res |= true;
      CPPUNIT_ASSERT(!it->empty());
    }

  CPPUNIT_ASSERT(res);
}
