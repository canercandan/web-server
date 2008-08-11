//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:24 2008 morgan armand
// Last update Mon Aug 11 11:34:18 2008 morgan armand
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

void			HttpRequest::setMethod(const std::string& method)
{
  this->_method = method;
}

const std::string&	HttpRequest::getHost() const
{
  return (this->_host);
}

void			HttpRequest::setHost(const std::string& host)
{
  this->_host = host;
}


const int		HttpRequest::getPort() const
{
  return (this->_port);
}

void			HttpRequest::setPort(const int port)
{
  this->_port = port;
}

const std::string&	HttpRequest::getPath() const
{
  return (this->_path);
}

void			HttpRequest::setPath(const std::string& path)
{
  this->_path = path;
}
