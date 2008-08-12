//
// InfoFile.h for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Mon Aug 11 22:34:42 2008 florent hochwelker
// Last update Tue Aug 12 01:36:11 2008 florent hochwelker
//

#ifndef __INFOFILE_H__
#define __INFOFILE_H__

#include <list>
#include <string>
#include <sys/stat.h>

class	InfoFile
{
public:
  enum Type { FILE, DIR, OTHER };
  InfoFile(const std::string& file);
  
  bool				isGood();
  InfoFile::Type		getType();
  std::list<std::string>	*getListDir();

private:
  struct stat	_sb;
  bool		_good;
  std::string	_file;
};

#endif // !__INFOFILE_H__
