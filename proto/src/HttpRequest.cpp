//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:24 2008 morgan armand
// Last update Mon Aug 11 13:01:40 2008 morgan armand
//

#include "HttpRequest.h"

HttpRequest::HttpRequest()
  : _port(80)
{
}

const std::string&	HttpRequest::getMethod() const
{
  return (this->_method);
}

const std::string&	HttpRequest::getHost() const
{
  return (this->_host);
}

const int		HttpRequest::getPort() const
{
  return (this->_port);
}

const std::string&	HttpRequest::getPath() const
{
  return (this->_path);
}

const int		HttpRequest::getHttpMajorVersion() const
{
  return (this->_major);
}

const int		HttpRequest::getHttpMinorVersion() const
{
  return (this->_minor);
}

void			HttpRequest::setHost(const std::string& host)
{
  this->_host = host;
}

void			HttpRequest::setMethod(const std::string& method)
{
  this->_method = method;
}

void			HttpRequest::setPort(const int port)
{
  this->_port = port;
}

void			HttpRequest::setPath(const std::string& path)
{
  this->_path = path;
}

void			HttpRequest::setHttpMajorVersion(int major)
{
  this->_major = major;
}

void			HttpRequest::setHttpMinorVersion(int minor)
{
  this->_minor = minor;
}
