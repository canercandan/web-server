//
// FileInfo.h for ** zia ** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Tue Sep  9 20:42:16 2008 majdi toumi
//

#ifndef __FILEINFO_H__
#define __FILEINFO_H__

#include <list>
#include <string>
#include <sys/stat.h>
#include "IFileInfo.h"

namespace	ZenZiAPI
{
  //! FileInfo
  class	FileInfo : public IFileInfo
  {
  public:
    //! undef
    FileInfo(const std::string& path);
    ~FileInfo();

    //! undef
    bool		isGood();
    //! undef
    const std::string&	getPath() const;
    //! undef
    const Type&		getType() const;
    //! undef
    const int&		getSize() const;
    //! undef
    const std::string&	getLastTimeAccess();
    //! undef
    const listDir&	getListDir();
  private:
    void	_setGood();
    void	_setType();
    void	_setSize();
    void	_setLastTimeAccess();
    void	_setListDir();
  private:
    std::string	_path;
    Type	_type;
    listDir	_listDir;
    int		_size;
#ifdef WIN32
    SYSTEMTIME	_lastTimeAccess;
#else
    std::string	_lastTimeAccess;
#endif
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
