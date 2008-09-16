//
// Logger.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:23:59 2008 majdi toumi
// Last update Tue Sep 16 17:20:02 2008 caner candan
//

#include <time.h>
#include <iostream>
#include "Logger.h"

Logger::Log::Log(const Logger::Log::Level& level,
		 const std::string& section)
  : _level(level), _section(section)
{}

Logger::Log&	Logger::Log::operator<<(const std::string& msg)
{
  time_t	tm;
  char*		stm;

  time(&tm);
  stm = ctime(&tm);
  stm[24] = 0;
  std::clog << "[" << stm << "] ";
  if (_level == DEBUG)
    std::clog << "DEBUG";
  else if (_level == INFO)
    std::clog << "INFO";
  else if (_level == WARN)
    std::clog << "WARN";
  else if (_level == ERROR)
    std::clog << "ERROR";
  std::clog << " -- " << _section << " -- "
	    << msg << std::endl;
  return (*this);
}

Logger::Debug::Debug(const std::string& section)
  : _section(section)
{}

Logger::Debug&	Logger::Debug::operator<<(const std::string& msg)
{
  Log	log(Log::DEBUG, _section);

  log << msg;
  return (*this);
}

Logger::Info::Info(const std::string& section)
  : _section(section)
{}

Logger::Info&	Logger::Info::operator<<(const std::string& msg)
{
  Log	log(Log::INFO, _section);

  log << msg;
  return (*this);
}

Logger::Warn::Warn(const std::string& section)
  : _section(section)
{}

Logger::Warn&	Logger::Warn::operator<<(const std::string& msg)
{
  Log	log(Log::WARN, _section);

  log << msg;
  return (*this);
}

Logger::Error::Error(const std::string& section)
  : _section(section)
{}

Logger::Error&	Logger::Error::operator<<(const std::string& msg)
{
  Log	log(Log::ERROR, _section);

  log << msg;
  return (*this);
}
