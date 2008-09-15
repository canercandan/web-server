//
// FileInfo.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:12 2008 caner candan
// Last update Mon Sep 15 14:56:56 2008 majdi toumi
//

#include <iostream>
#include <algorithm>
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
#ifdef WIN32
	std::replace(_path.begin(), _path.end(), '/', '\\');

	if (_path[_path.size() - 1] == '\\')
		_path += '*';
#endif

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
	WCHAR	wszPath[MAX_PATH];

	//this->_path = "\\\\?\\" + this->_path;
	MultiByteToWideChar(CP_ACP, 0, this->_path.c_str(), -1, wszPath, MAX_PATH);

  //this->_good = ((_hFind = ::FindFirstFile(wszPath, &this->_findFileData))
//		 != INVALID_HANDLE_VALUE);
	if ((_hFind = FindFirstFile(wszPath, &this->_findFileData)) == INVALID_HANDLE_VALUE)
	{
		TCHAR	wczErr[255];
		char	err[255];

		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), 0, wczErr, 255, NULL);
		WideCharToMultiByte(CP_ACP, 0, wczErr, -1, err, 255, NULL, NULL);

		std::cerr << this->_path << ": " << err << std::endl;

		this->_good = false;
	}
	else
		this->_good = true;
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
      this->_size = 0;
      return;
    }
#ifdef WIN32
  this->_size = this->_findFileData.nFileSizeLow;
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
  {
	  char		czFilename[MAX_PATH];

    while (::FindNextFile(this->_hFind, &this->_findFileData))
	{
		WideCharToMultiByte(CP_ACP, 0, this->_findFileData.cFileName, -1,
			czFilename, MAX_PATH, NULL, NULL);

      this->_listDir.push_back(czFilename);
	}
  }
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

const unsigned int	FileInfo::getSize() const
{
  return (this->_size);
}

#ifdef WIN32
bool	FileInfo::isAccessModified(SYSTEMTIME oldTime)
# else
  bool	FileInfo::isAccessModified(std::string& oldTime)
#endif
{
#ifdef WIN32
  if ((this->_lastTimeAccess.wYear != oldTime.wYear)
      || (this->_lastTimeAccess.wMonth != oldTime.wMonth)
      || (this->_lastTimeAccess.wDay != oldTime.wDay)
      || (this->_lastTimeAccess.wHour != oldTime.wHour)
      || (this->_lastTimeAccess.wMinute != oldTime.wMinute)
      || (this->_lastTimeAccess.wSecond != oldTime.wSecond))
    return (true);
#else
  if ((oldTime == "") || (this->_lastTimeAccess != oldTime))
    return (true);
#endif
  return (false);
}

#ifdef WIN32
SYSTEMTIME	FileInfo::getLastTimeAccess()
# else
  std::string&	FileInfo::getLastTimeAccess()
#endif
{
  return (this->_lastTimeAccess);
}

FileInfo::listDir&	FileInfo::getListDir()
{
  return (this->_listDir);
}

std::string	FileInfo::getContent()
{
  std::ifstream	in(this->getPath().c_str());
  std::string	content;
  char		buf[4096];

  //  if (this->getType() == FILE)
  //    return (content);
  if (!in.is_open())
    return (content);

  while (in.good())
    {
      in.read(buf, 4096);
      content += std::string(buf, in.gcount());
    }

  in.close();
  return (content);
}
