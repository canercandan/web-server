#ifndef __CONFIG_H__
# define __CONFIG_H__

# include "IConfig.h"
# include "Singleton.hpp"

//! Config
class Config : public IConfig,
	       public Singleton<Config>
{
public:
  //! undef
  Config();

  //! undef
  virtual const std::string&	getPath();
  //! undef
  virtual void			setPath(const std::string&);
private:
  std::string	_path;
};

#endif // !__CONFIG_H__
