//
// FileInfo.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug 31 18:03:55 2008 majdi toumi
// Last update Wed Sep 10 12:20:24 2008 majdi toumi
//

#ifndef __FILEINFO_H__
# define __FILEINFO_H__

# include <list>
# include <string>
# include <sys/stat.h>

class	FileInfo
{
public:
  //! a list of string
  typedef std::list<std::string>	ListDir_t;

  //! file's type
  enum Type
    {
      FILE,
      DIR,
      OTHER
    };

  FileInfo(const std::string& path);
  ~FileInfo();

  //! return true if the path is good
  bool		isGood();
  //! get the path
  //! \return const std::string&
  const std::string&	getPath() const;
  //! get the type of the path
  //! \return const Type&
  const Type&		getType() const;
  //! get size of the path
  //! \return const int&
  const int&		getSize() const;
  //! get time of the last file access
  //! \return std::string&
  const std::string&	getLastTimeAccess();
  //! get the list of the directory,
  //! only use if the path is a directory
  //! \return const listDir&
  const ListDir_t&	getListDir();

private:
  void	_setGood();
  void	_setType();
  void	_setSize();
  void	_setLastTimeAccess();
  void	_setListDir();

private:
  std::string	_path;
  Type	_type;
  ListDir_t	_list_dir;
  int		_size;
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
