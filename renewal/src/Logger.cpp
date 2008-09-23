//
// Logger.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 12:23:59 2008 majdi toumi
// Last update Wed Sep 17 17:55:59 2008 caner candan
//

#include <time.h>
#include <iostream>
#include "Logger.h"

Logger::Log::Log(const Logger::Log::Level& level,
		 const std::string& section /*= ""*/)
{
  time_t	tm;
  char*		stm;

  time(&tm);
  stm = ctime(&tm);
  stm[24] = 0;
  std::clog << "[" << stm << "] ";
  if (level == LOG_DEBUG)
    std::clog << "DEBUG";
  else if (level == LOG_INFO)
    std::clog << "INFO";
  else if (level == LOG_WARN)
    std::clog << "WARN";
  else if (level == LOG_ERROR)
    std::clog << "ERROR";
  if (!section.empty())
    std::clog << " -- " << section;
  std::clog << " -- ";
  std::clog.flush();
}

Logger::Debug::Debug(const std::string& section /*= ""*/)
{
  Log	log(Log::LOG_DEBUG, section);
}

Logger::Debug&	Logger::Debug::operator<<(const std::string& msg)
{
  std::clog << msg;
  return (*this);
}

Logger::Debug&	Logger::Debug::operator<<(const int& value)
{
  std::clog << value;
  std::clog.flush();
  return (*this);
}

Logger::Info::Info(const std::string& section /*= ""*/)
{
  Log	log(Log::LOG_INFO, section);
}

Logger::Info&	Logger::Info::operator<<(const std::string& msg)
{
  std::clog << msg;
  std::clog.flush();
  return (*this);
}

Logger::Info&	Logger::Info::operator<<(const int& value)
{
  std::clog << value;
  std::clog.flush();
  return (*this);
}

Logger::Warn::Warn(const std::string& section /*= ""*/)
{
  Log	log(Log::LOG_WARN, section);
}

Logger::Warn&	Logger::Warn::operator<<(const std::string& msg)
{
  std::clog << msg;
  std::clog.flush();
  return (*this);
}

Logger::Warn&	Logger::Warn::operator<<(const int& value)
{
  std::clog << value;
  std::clog.flush();
  return (*this);
}

Logger::Error::Error(const std::string& section /*= ""*/)
{
  Log	log(Log::LOG_ERROR, section);
}

Logger::Error&	Logger::Error::operator<<(const std::string& msg)
{
  std::clog << msg;
  std::clog.flush();
  return (*this);
}

Logger::Error&	Logger::Error::operator<<(const int& value)
{
  std::clog << value;
  std::clog.flush();
  return (*this);
}
