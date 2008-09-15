//
// FileInfo.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Mon Sep 15 11:01:29 2008 majdi toumi
//

#ifndef __FILEINFO_H__
# define __FILEINFO_H__

# include <list>
# include <string>

# ifdef WIN32
#  include <windows.h>
# else
#  include <sys/stat.h>
#endif

class	FileInfo
{
public:
  typedef std::list<std::string>	listDir;

  enum	Type {FILE, DIR, OTHER};
public:
  FileInfo(const std::string& path);
  ~FileInfo();

  bool		isGood();

  const std::string&	getPath() const;
  const Type&		getType() const;
  const unsigned int		getSize() const;
#ifdef WIN32
<<<<<<< .mine
  bool	isAccessModified(SYSTEMTIME oldTime);
=======
  bool			isAccessModified(SYSTEMTIME oldTime);
  SYSTEMTIME		getLastTimeAccess();
>>>>>>> .r494
# else
  bool			isAccessModified(std::string& oldTime);
  std::string&		getLastTimeAccess();
#endif
  listDir&		getListDir();
  std::string		getContent();
private:
  void	_setGood();
  void	_setType();
  void	_setSize();
  void	_setLastTimeAccess();
  void	_setListDir();
private:
  std::string	_path;
  Type		_type;
  listDir	_listDir;
  unsigned int		_size;
# ifdef WIN32
  SYSTEMTIME	_lastTimeAccess;
# else
  std::string	_lastTimeAccess;
# endif
  bool		_good;
# ifdef WIN32
  WIN32_FIND_DATA	_findFileData;
  HANDLE		_hFind;
# else
  struct stat		_sb;
# endif
};

#endif // !__FILEINFO_H__
