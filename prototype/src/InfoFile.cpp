//
// InfoFile.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Mon Aug 11 22:36:09 2008 florent hochwelker
// Last update Tue Aug 12 09:39:35 2008 florent hochwelker
// Last update Wed Aug 13 22:10:02 2008 caner candan
//

#include <sys/types.h>
#ifdef WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif
#include "InfoFile.h"

InfoFile::InfoFile(const std::string& file)
  : _file(file)
{
#ifdef WIN32
  ::WIN32_FIND_DATA	FindFileData;

  _good = (::FindFirstFile((LPCWSTR)file.c_str(), &FindFileData) != INVALID_HANDLE_VALUE);
#else
  _good = (lstat(file.c_str(), &_sb) == 0);
#endif
}

bool	InfoFile::isGood()
{
  return (this->_good);
}

const std::string&		InfoFile::getPath()
{
  return this->_file;
}

InfoFile::Type	InfoFile::getType()
{
  if (_good == true)
    {
#ifdef WIN32
      ::WIN32_FIND_DATA	FindFileData;

      ::FindFirstFile((LPCWSTR)this->_file.c_str(), &FindFileData);
      if (FindFileData.dwFileAttributes &= FILE_ATTRIBUTE_DIRECTORY)
	return (DIR);
      else
	return (FILE);
#else
      if (S_ISDIR(this->_sb.st_mode))
	return (DIR);
      if (S_ISREG(this->_sb.st_mode))
	return (FILE);
#endif
    }
  return (OTHER);
}

std::list<std::string>		*InfoFile::getListDir()
{
  std::list<std::string>	*listDir = new std::list<std::string>;

#ifdef WIN32
  WIN32_FIND_DATA	FindFileData;
  HANDLE		hFind;

  if ((hFind = ::FindFirstFile((LPCWSTR)this->_file.c_str(), &FindFileData)) != INVALID_HANDLE_VALUE)
    {
      while (::FindNextFile(hFind, &FindFileData))
	listDir->push_back((char*)FindFileData.cFileName);
      ::FindClose(hFind);
    }
#else
  struct dirent	*dp; 
  ::DIR		*dirp;

  if ((dirp = opendir(this->_file.c_str())) != NULL)
    {
      while ((dp = readdir(dirp)) != NULL)
	listDir->push_back(dp->d_name);
      closedir(dirp);
    }
#endif
  return (listDir);
}

int				InfoFile::getSize()
{
  if (this->_good)
    return this->_sb.st_size;
  return -1;
}