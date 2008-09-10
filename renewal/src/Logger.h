//
// Logger.h for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:07:23 2008 majdi toumi
// Last update Wed Sep 10 12:23:16 2008 majdi toumi
//

#ifndef __LOGGER_H__
# define __LOGGER_H__

#include <string>

//! Logger
class	Logger
{
public:
  //! level
  enum	Level
    {
      DEBUG,
      INFO,
      WARN,
      ERROR
      };
  //! undef
  void	log(const Level level, const std::string& msg);
  //! undef
  void	debug(const std::string& msg);
  //! undef
  void	info(const std::string& msg);
  //! undef
  void	warn(const std::string& msg);
  //! undef
  void	error(const std::string& msg);
};

#endif // __LOGGER_H__
