#ifndef __LOGGER_H__
# define __LOGGER_H__

# include "ILogger.h"

namespace	ziApi
{
  //! Logger
  class	Logger : public ILogger
  {
  public:
    //! undef
    virtual void	log(const Level level,
			    const std::string& msg);
    //! undef
    virtual void	debug(const std::string& msg);
    //! undef
    virtual void	info(const std::string& msg);
    //! undef
    virtual void	warn(const std::string& msg);
    //! undef
    virtual void	error(const std::string& msg);
  };
};

#endif // __LOGGER_H__
