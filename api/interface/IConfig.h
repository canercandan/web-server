#ifndef __ICONFIG_H__
# define __ICONFIG_H__

# include <string>
# include "IRoot.h"

namespace	ziApi
{
  //! IConfig
  class	IConfig : public IRoot
  {
  public:
    virtual ~IConfig(){}

    //! undef
    virtual void	setValue(const std::string& key,
				 const std::string& value) = 0;
    //! undef
    virtual void	setXmlValue(const std::string& key,
				    const std::string& path) = 0;
    //! undef
    virtual const std::string&	getValue(const std::string& key) = 0;
  };
};

#endif // !__ICONFIG_H__
