//
// FileInfo.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:12 2008 caner candan
// Last update Sun Sep 14 09:57:06 2008 caner candan
//

#include <sys/types.h>

#ifdef WIN32
# include <windows.h>
#else
# include <dirent.h>
#endif

#include <fstream>
#include "FileInfo.h"

FileInfo::FileInfo(const std::string& path)
  : _path(path), _type(OTHER)
{
  _setGood();
  _setType();
  _setSize();
  _setLastTimeAccess();
  _setListDir();
}

FileInfo::~FileInfo()
{
#ifdef WIN32
  ::FindClose(this->_hFind);
#endif
}

void	FileInfo::_setGood()
{
#ifdef WIN32
  this->_good = (_hFind = ::FindFirstFile((LPCWSTR)this->_path.c_str(),
					  &this->_findFileData)
		 != INVALID_HANDLE_VALUE);
#else
  this->_good = (!lstat(this->_path.c_str(), &this->_sb));
#endif
}

void	FileInfo::_setType()
{
  if (!isGood())
    return;
#ifdef WIN32
  if (_findFileData.dwFileAttributes &= FILE_ATTRIBUTE_DIRECTORY)
    this->_type = DIR;
  else
    this->_type = FILE;
#else
  if (S_ISDIR(this->_sb.st_mode))
    this->_type = DIR;
  else if (S_ISREG(this->_sb.st_mode))
    this->_type = FILE;
#endif
}

void	FileInfo::_setSize()
{
  if (!this->isGood())
    {
      this->_size = -1;
      return;
    }
#ifdef WIN32
  this->_size = (this->_findFileData.nFileSizeHigh * (MAXDWORD + 1))
    + this->_findFileData.nFileSizeLow;
#else
  this->_size = this->_sb.st_size;
#endif
}

void	FileInfo::_setLastTimeAccess()
{
  //this->_setGood();
  if (!this->isGood())
    return;

#ifdef WIN32
  FileTimeToSystemTime(&this->_findFileData.ftLastAccessTime, &this->_lastTimeAccess);
#else
  this->_lastTimeAccess = this->_sb.st_ctime;
#endif
}

void	FileInfo::_setListDir()
{
  if (this->getType() != DIR)
    return;
#ifdef WIN32
  const std::string&	file
    = (this->getType() == DIR) ? this->_path + "\\*" : this->_path;

  if (this->_hFind)
    while (::FindNextFile(this->_hFind, &this->_findFileData))
      this->_listDir->push_back((char*)this->_findFileData.cFileName);
#else
  struct dirent	*dp;
  ::DIR		*dirp;

  if ((dirp = opendir(this->_path.c_str())) != NULL)
    {
      while ((dp = readdir(dirp)))
	this->_listDir.push_back(dp->d_name);
      closedir(dirp);
    }
#endif
}

bool	FileInfo::isGood()
{
  return (this->_good);
}

const std::string&	FileInfo::getPath() const
{
  return (this->_path);
}

const FileInfo::Type&	FileInfo::getType() const
{
  return (this->_type);
}

const int&	FileInfo::getSize() const
{
  return (this->_size);
}

const std::string&	FileInfo::getLastTimeAccess()
{
#ifdef WIN32
  return (this->_lastTimeAccess.wYear
	  + this->_lastTimeAccess.wMonth
	  + this->_lastTimeAccess.wDay
	  + this->_lastTimeAccess.wHour
	  + this->_lastTimeAccess.wMinute
	  + this->_lastTimeAccess.wSecond);
#else
  return (this->_lastTimeAccess);
#endif
}

FileInfo::listDir&	FileInfo::getListDir()
{
  return (this->_listDir);
}

std::string	FileInfo::getContent()
{
  std::ifstream	in(this->getPath().c_str());
  std::string	content;

  if (this->getType() == FILE)
    return (content);
  if (!in.is_open())
    return (content);
  while (in.good())
    {
      content += in.get();
//       if (!in.good())
// 	break;
    }
  in.close();
  return (content);
}
