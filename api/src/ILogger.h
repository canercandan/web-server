#ifndef __ILOGGER_H__
# define __ILOGGER_H__

# include <string>
# include "IRoot.h"

//! ILogger
class	ILogger : public IRoot
{
public:
  enum	Level
    {
      DEBUG,
      INFO,
      WARN,
      ERROR
    };

  virtual ~ILogger(){}

  //! log
  virtual void	log(const Level level,
		    const std::string& msg) = 0;
  //! debug
  virtual void	debug(const std::string& msg) = 0;
  //! info
  virtual void	info(const std::string& msg) = 0;
  //! warn
  virtual void	warn(const std::string& msg) = 0;
  //! error
  virtual void	error(const std::string& msg) = 0;
};

#endif // !__ILOGGER_H__
