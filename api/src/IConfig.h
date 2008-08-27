#ifndef __CONFIG_H__
# define __CONFIG_H__

# include <string>
# include "IServer.h"

//! IConfig
class IConfig : public IServer
{
public:
  virtual ~IConfig(){}

  //! undef
  virtual const std::string&	getPath() = 0;
  //! undef
  virtual void			setPath(const std::string&) = 0;
};

#endif // !__CONFIG_H__
