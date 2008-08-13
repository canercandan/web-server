//
// InfoFile.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Mon Aug 11 22:36:09 2008 florent hochwelker
// Last update Tue Aug 12 07:24:41 2008 florent hochwelker
//

#include <sys/types.h>
#include <dirent.h>
#include "InfoFile.h"

InfoFile::InfoFile(const std::string& file)
  : _file(file)
{
  _good = (lstat(file.c_str(), &_sb) == 0);
}

bool	InfoFile::isGood()
{
  return (this->_good);
}

InfoFile::Type	InfoFile::getType()
{
  if (_good == true)
    {
      if (S_ISDIR(this->_sb.st_mode))
	return (DIR);
      if (S_ISREG(this->_sb.st_mode))
	return (FILE);
    }
  return (OTHER);
}

std::list<std::string>		*InfoFile::getListDir()
{
  struct dirent			*dp;
  std::list<std::string>	*listDir = new std::list<std::string>;
  ::DIR *dirp;

  if ((dirp = opendir(this->_file.c_str())) != NULL)
    {
      while ((dp = readdir(dirp)) != NULL)
	listDir->push_back(dp->d_name);
      closedir(dirp);
    }
  return (listDir);
}
