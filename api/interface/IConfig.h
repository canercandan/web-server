#ifndef __ICONFIG_H__
# define __ICONFIG_H__

# include <string>
# include <list>
# include "IRoot.h"
# include "FileInfo.h"

namespace	ziApi
{
  //! IConfig
  class	IConfig : public IRoot
  {
  public:
    //! a list of string
    typedef std::list<std::string>	listModule;

    virtual ~IConfig(){}

    //! undef
    virtual void	setValue(const std::string& key,
				 const std::string& value) = 0;
    //! undef
    virtual void	setXmlValue(const std::string& key,
				    const std::string& path) = 0;
    //! undef
    virtual const std::string&	getValue(const std::string& key) = 0;

    //! undef
    virtual void	refresh(FileInfo& info) = 0;
  };
};

#endif // !__ICONFIG_H__
