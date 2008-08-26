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
};

#endif // !__CONFIG_H__
