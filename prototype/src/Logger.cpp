//
// Logger.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 09:53:20 2008 morgan armand
// Last update Wed Jul 30 10:19:44 2008 morgan armand
//

#include <time.h>
#include <iostream>
#include "Logger.h"

void		Logger::log(const Logger::Level level, const std::string& msg)
{
  time_t	tm;
  char*		stm;

  time(&tm);

  // Get rid of \n
  // #ifdef WIN32 ctime_s()	  
  stm = ctime(&tm);
  stm[24] = 0;

  std::clog << "[" << stm << "] ";

  switch (level)
    {
    case Logger::DEBUG:
      std::clog << "DEBUG";
      break;

    case Logger::INFO:
      std::clog << "INFO";
      break;

    case Logger::WARN:
      std::clog << "WARN";
      break;

    case Logger::ERROR:
      std::clog << "ERROR";
      break;
    }

  std::clog << " -- " << msg << std::endl;
}

void	Logger::debug(const std::string& msg)
{
  this->log(Logger::DEBUG, msg);
}

void	Logger::info(const std::string& msg)
{
  this->log(Logger::INFO, msg);
}

void	Logger::warn(const std::string& msg)
{
  this->log(Logger::WARN, msg);
}

void	Logger::error(const std::string& msg)
{
  this->log(Logger::ERROR, msg);
}
