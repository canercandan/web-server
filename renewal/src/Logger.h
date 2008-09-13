//
// Logger.h for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:07:23 2008 majdi toumi
// Last update Sat Sep 13 22:20:10 2008 caner candan
//

#ifndef __LOGGER_H__
# define __LOGGER_H__

#include <string>

class	Logger
{
public:
  enum	Level
    {
      DEBUG,
      INFO,
      WARN,
      ERROR
      };

  void	log(const Level level, const std::string& msg);
  void	debug(const std::string& msg);
  void	info(const std::string& msg);
  void	warn(const std::string& msg);
  void	error(const std::string& msg);
};

#endif // __LOGGER_H__
