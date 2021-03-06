//
// FileInfo.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Thu Sep 25 07:00:48 2008 caner candan
//

#ifndef __FILEINFO_H__
# define __FILEINFO_H__

# include <list>
# include <string>

# ifdef WIN32
#  define WIN32_LEAN_AND_MEAN
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
  const unsigned int	getSize() const;
#ifdef WIN32
  bool			isAccessModified(SYSTEMTIME oldTime);
  SYSTEMTIME		getLastTimeAccess();
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
