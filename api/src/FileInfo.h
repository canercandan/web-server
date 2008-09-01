//
// FileInfo.h for ** zia ** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Mon Sep  1 09:12:43 2008 majdi toumi
//

#ifndef __FILEINFO_H__
#define __FILEINFO_H__

#include <list>
#include <string>
#include <sys/stat.h>
#include "IFileInfo.h"

namespace	ziApi
{
  //! FileInfo
  class	FileInfo : public IFileInfo
  {
  public:
    //! Enum
    enum Type { FILE, DIR, OTHER };
    FileInfo(const std::string& file);

    //! undef
    virtual bool		isGood();
    //! undef
    virtual FileInfo::Type	getType();
    //! undef
    virtual listDir&		*getListDir();
    //! undef
    virtual const std::string&	getPath();
    //! undef
    virtual int			getSize();
    //! undef
    virtual const int&		getLastTimeAccess();

  private:
    struct stat	_sb;
    bool	_good;
    std::string	_file;
  };
};

#endif // !__FILEINFO_H__
