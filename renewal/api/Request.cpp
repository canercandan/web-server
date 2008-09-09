#include "Request.hpp"

const std::string&		Request::HTTPVersion()
{
  return (this->_version);
}

void				Request::HTTPVersion(const std::string& version)
{
  this->_version = version;
}

const std::string&		Request::method()
{
  return (this->_method);
}

void				Request::method(const std::string& http_method)
{
  this->_method = http_method;
}

const std::string&		Request::uri()
{
  return (this->_uri);
}

void				Request::uri(std::string& field)
{
  this->_uri = field;
}

const std::map<std::string, std::string>&	Request::getHeaders(const std::string& field)
{
  return (this->_headers);
}

void				Request::setHeaders(const std::string& field,
						    std::map<std::string, std::string>& headers)
{
  this->_headers[field] = headers;
}

const std::string&		Request::getHeader(const std::string& field, const std::string& key)
{
  return (this->_headers[field][key]);
}

void				Request::setHeader(const std::string& field, const std::string& key,
						   const std::string& value)
{
  this->_headers[field][key] = value;
}

const std::string&		Request::getHeader(const std::string& header)
{
  return (this->_headers[header]);
}

void				Request::setHeader(const std::string& field, const std::string& value)
{
  this->_headers[field] = value;
}

const std::string&		Request::body()
{
  return (this->_body);
}

void				Request::body(const std::string& body)
{
  this->_body = body;
}

void				Request::bodyAppend(const std::string& body)
{
  this->_body += body;
}

void				Request::bodyAppend(char* body, unsigned int size = 0)
{
  if (size > 0)
    for (int i = 0; i < size; ++i)
      this->_body += body[i];
  else
    this->_body += body;
}

bool				Request::chunked() const
{
  return (isChunked);
}

void				Request::chunked(bool isChunked)
{
  this->_isChunked = isChunked;
}
