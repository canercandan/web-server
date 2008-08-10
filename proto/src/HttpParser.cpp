//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:54 2008 morgan armand
// Last update Fri Aug  8 21:29:35 2008 caner candan
//

#include "HttpParser.h"

HttpParser::HttpParser(HttpProducer* prod, HttpRequest* request)
  : URIParser(prod), _request(request)
{
}

HttpParser::~HttpParser()
{
}

bool	HttpParser::readRequest()
{
  return (this->readRequestLine());
}

bool	HttpParser::readRequestLine()
{
  return (this->readMethod() && SP &&
	  this->readRequestURI() && SP &&
	  this->readHttpVersion() && CRLF);
}

bool	HttpParser::readMethod()
{
  this->prepare();
  if (TEXT("OPTIONS") ||
      TEXT("GET") ||
      TEXT("HEAD") ||
      TEXT("POST") ||
      TEXT("PUT") ||
      TEXT("DELETE") ||
      TEXT("TRACE") ||
      TEXT("CONNECT") ||
      this->readExtensionMethod())
    {
      this->_request->setMethod(this->extract());
      this->consume();
      return (true);
    }
  return (false);
}

bool	HttpParser::readExtensionMethod()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readRequestURI()
{
  if (CHAR('*') ||
      this->readAbsoluteURI() ||
      this->readPathAbsolute() ||
      this->readAuthority())
    return (true);
  return (false);
}

bool	HttpParser::readHttpVersion()
{
  std::string	name;
  int		major;
  int		minor;

  if (TEXT_R("HTTP", name) &&
      CHAR('/') &&
      INTEGER_R(major) &&
      CHAR('.') &&
      INTEGER_R(minor))
    {
      this->_request->setVersionProtocol(name, major, minor);
      return (true);
    }
  return (false);
}
