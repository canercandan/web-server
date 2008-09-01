#ifndef __IFILEINFO_H__
# define __IFILEINFO_H__

# include <list>
# include <string>
# include "IRoot.h"

namespace	ziApi
{
  //! IFileInfo
  class	IFileInfo : public IRoot
  {
  public:
    //! a list of string
    typedef std::list<std::string>	listDir;

    //! file's type
    enum	Type	{FILE, DIR, OTHER};

    virtual ~IFileInfo(){}

    //! return true if the path is good
    virtual bool		isGood() = 0;
    //! get the path
    //! \return const std::string&
    virtual const std::string&	getPath() const = 0;
    //! get the type of the path
    //! \return const Type&
    virtual const Type&		getType() const = 0;
    //! get size of the path
    //! \return const int&
    virtual const int&		getSize() const = 0;
    //! get time of the last file access
    //! \return std::string&
    virtual const int&		getLastTimeAccess() const = 0;
    //! get the list of the directory,
    //! only use if the path is a directory
    //! \return const listDir&
    virtual const listDir&	getListDir() = 0;
  };
};

#endif // !__IFILEINFO_H__
