//
// ZiaConfiguration.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Tue Aug 12 15:10:50 2008 majdi toumi
//

#include <iostream>
#include <sstream>
#include <string>
#include "ZiaConfiguration.h"

ZiaConfiguration::ZiaConfiguration()
{
  _name = "";
  _port = 80;
  _shutdown = "";
  _debug = false;
  _respect_rfc = "";
  _document_root = "";
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
      this->_document_root = ziaConfig._document_root;
    }
  return (*this);
}

void			ZiaConfiguration::setName(std::string name)
{
  this->_name = name;
}

void			ZiaConfiguration::setPort(unsigned int port)
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

void			ZiaConfiguration::setRespectRfc(std::string respect_rfc)
{
  this->_respect_rfc = respect_rfc;
}

void			ZiaConfiguration::setDocumentRoot(std::string document_root)
{
  this->_document_root = document_root;
}

const std::string	ZiaConfiguration::getName() const
{
  return (this->_name);
}

const unsigned int	ZiaConfiguration::getPort() const
{
  return (this->_port);
}

const std::string	ZiaConfiguration::getShutdown() const
{
  return (this->_shutdown);
}

const bool		ZiaConfiguration::getDebug() const
{
  return (this->_debug);
}

const std::string	ZiaConfiguration::getRespectRfc() const
{
  return (this->_respect_rfc);
}

const std::string	ZiaConfiguration::getDocumentRoot() const
{
  return (this->_document_root);
}

void			ZiaConfiguration::ziaDumpConfig()
{
  std::cout << " ->> Dump zia configuration:" << std::endl;
  std::cout << "Name = " << this->_name << std::endl;
  std::cout << "Port = " << this->_port << std::endl;
  std::cout << "Shutdown = " << this->_shutdown << std::endl;
  std::cout << "Debug = " << std::boolalpha << this->_debug << std::endl;
  std::cout << "Respect rfc = " << this->_respect_rfc << std::endl;
  std::cout << "Document root = " << this->_document_root << std::endl;
  std::cout << std::endl;
}
