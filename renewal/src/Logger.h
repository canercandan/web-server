//
// Logger.h for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:07:23 2008 majdi toumi
// Last update Wed Sep 17 10:50:54 2008 caner candan
//

#ifndef __LOGGER_H__
# define __LOGGER_H__

# include <string>
# include <iostream>

namespace	Logger
{
  class	Log
  {
  public:
    enum	Level	{LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR};
  public:
    Log(const Level&, const std::string& section = "");
  };

  class	Debug
  {
  public:
    Debug(const std::string& section = "");

    Debug&	operator<<(const std::string&);
    Debug&	operator<<(const int&);
  };

  class	Info
  {
  public:
    Info(const std::string& section = "");

    Info&	operator<<(const std::string&);
    Info&	operator<<(const int&);
  };

  class	Warn
  {
  public:
    Warn(const std::string& section = "");

    Warn&	operator<<(const std::string&);
    Warn&	operator<<(const int&);
  };

  class	Error
  {
  public:
    Error(const std::string& section = "");

    Error&	operator<<(const std::string&);
    Error&	operator<<(const int&);
  };
}

#endif // __LOGGER_H__
