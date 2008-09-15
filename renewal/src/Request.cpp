//
// Request.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 16:19:10 2008 caner candan
// Last update Fri Sep 12 14:57:04 2008 majdi toumi
//

#include "Request.h"

//using namespace	ZenZiAPI;

const std::string&	Request::getHTTPVersion()
{
  return (this->_version);
}

void	Request::setHTTPVersion(const std::string& version)
{
  this->_version = version;
}

const std::string&	Request::getMethod()
{
  return (this->_method);
}

void	Request::setMethod(const std::string& http_method)
{
  this->_method = http_method;
}

const std::string&	Request::getUri()
{
  return (this->_uri);
}

void	Request::setUri(const std::string& http_uri)
{
  this->_uri = http_uri;
}

const std::map<std::string, std::string>&	Request::getHeaders(const std::string& field)
{
  return (this->_headers[field]);
}

void	Request::setHeaders(const std::string& field,
			    std::map<std::string, std::string>& headers)
{
  this->_headers[field] = headers;
}

const std::string&	Request::getHeader(const std::string& field,
					   const std::string& key)
{
  return (this->_headers[field][key]);
}

void	Request::setHeader(const std::string& field,
			   const std::string& key,
			   const std::string& value)
{
  this->_headers[field][key] = value;
}

const std::string&	Request::getHeader(const std::string& header)
{
  return (this->_header[header]);
}

void	Request::setHeader(const std::string& field,
			   const std::string& value)
{
  this->_header[field] = value;
}

const std::string&	Request::getBody()
{
  return (this->_body);
}


void	Request::setBody(const std::string& body)
{
  this->_body = body;
}

void	Request::bodyAppend(const std::string& body)
{
  this->_body += body;
}

void	Request::bodyAppend(char* body,
			    unsigned int size)
{
  if (size > 0)
    for (unsigned int i = 0; i < size; ++i)
      this->_body += body[i];
  else
    this->_body += body;
}

bool	Request::isChunk() const
{
  return (this->_isChunked);
}

void	Request::setChunk(bool isChunked)
{
  this->_isChunked = isChunked;
}
