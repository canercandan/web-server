//
// FileInfo.h for ** zia ** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Mon Sep  1 12:18:19 2008 caner candan
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
    //! undef
    FileInfo(const std::string& path);

    //! undef
    bool		isGood();
    //! undef
    const std::string&	getPath() const;
    //! undef
    const Type&		getType() const;
    //! undef
    const int&		getSize() const;
    //! undef
    const int&		getLastTimeAccess() const;
    //! undef
    const listDir&	getListDir();
  private:
    void	_setGood();
    void	_setType();
    void	_setListDir();
  private:
    std::string	_path;
    Type	_type;
    listDir	_listDir;
    int		_size;
    int		_lastTimeAccess;
    bool	_good;
# ifdef WIN32
    WIN32_FIND_DATA	_findFileData;
    HANDLE		_hFind;
# else
    struct stat		_sb;
# endif
  };
};

#endif // !__FILEINFO_H__
