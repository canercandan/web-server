//
// Logger.h for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:07:23 2008 majdi toumi
// Last update Tue Sep 16 17:19:28 2008 caner candan
//

#ifndef __LOGGER_H__
# define __LOGGER_H__

#include <string>

namespace	Logger
{
  class	Log
  {
  public:
    enum	Level	{DEBUG, INFO, WARN, ERROR};
  public:
    Log(const Level&, const std::string& section /*= ""*/);

    Log&	operator<<(const std::string&);
  private:
    Level	_level;
    std::string	_section;
  };

  class	Debug
  {
  public:
    Debug(const std::string& section /*= ""*/);

    Debug&	operator<<(const std::string&);
  private:
    std::string	_section;
  };

  class	Info
  {
  public:
    Info(const std::string& section /*= ""*/);

    Info&	operator<<(const std::string&);
  private:
    std::string	_section;
  };

  class	Warn
  {
  public:
    Warn(const std::string& section /*= ""*/);

    Warn&	operator<<(const std::string&);
  private:
    std::string	_section;
  };

  class	Error
  {
  public:
    Error(const std::string& section /*= ""*/);

    Error&	operator<<(const std::string&);
  private:
    std::string	_section;
  };
}

#endif // __LOGGER_H__
