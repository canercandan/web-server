//
// Logger.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 09:40:58 2008 morgan armand
// Last update Wed Jul 30 10:34:42 2008 morgan armand
//

#ifndef __LOGGER_H__
#define __LOGGER_H__

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

public:
  void	log(const Logger::Level level, const std::string& msg);

  void	debug(const std::string& msg);
  void	info(const std::string& msg);
  void	warn(const std::string& msg);
  void	error(const std::string& msg);
};

#endif // __LOGGER_H__

