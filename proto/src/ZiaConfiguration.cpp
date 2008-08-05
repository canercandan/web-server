//
// ZiaConfiguration.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Mon Aug  4 16:47:00 2008 majdi toumi
//

#include <sstream>
#include <string>
#include "ZiaConfiguration.h"

ZiaConfiguration::ZiaConfiguration()
{
  _name = "";
  _port = -1;
  _shutdown = "";
  _debug = false;
  _respect_rfc = false;
}

ZiaConfiguration::ZiaConfiguration(const ZiaConfiguration& ziaConfig)
{
  *this = ziaConfig;
}

ZiaConfiguration&	ZiaConfiguration::operator=(const ZiaConfiguration& ziaConfig)
{
  if (this != &ziaConfig)
    {
      this->_name = ziaConfig._name;
      this->_port = ziaConfig._port;
      this->_shutdown = ziaConfig._shutdown;
      this->_debug = ziaConfig._debug;
      this->_respect_rfc = ziaConfig._respect_rfc;
    }
  return (*this);
}

void			ZiaConfiguration::setName(std::string name)
{
  this->_name = name;
}

void			ZiaConfiguration::setPort(int port)
{
  this->_port = port;
}

void			ZiaConfiguration::setShutdown(std::string shutdown)
{
  this->_shutdown = shutdown;
}

void			ZiaConfiguration::setDebug(bool debug)
{
  this->_debug = debug;
}

void			ZiaConfiguration::setRespectRfc(bool respect_rfc)
{
  this->_respect_rfc = respect_rfc;
}

std::string		ZiaConfiguration::getName()
{
  return (this->_name);
}

int			ZiaConfiguration::getPort()
{
  return (this->_port);
}

std::string		ZiaConfiguration::getShutdown()
{
  return (this->_shutdown);
}

bool			ZiaConfiguration::getDebug()
{
  return (this->_debug);
}

bool			ZiaConfiguration::getRespectRfc()
{
  return (this->_respect_rfc);
}
