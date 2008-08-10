//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:54 2008 morgan armand
// Last update Fri Aug  8 20:09:05 2008 morgan armand
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
  if (this->readRequestLine())
    return (true);
  return (false);
}

bool	HttpParser::readRequestLine()
{
  if (this->readMethod() && this->readSP() &&
      this->readRequestURI() && this->readSP() &&
      this->readHttpVersion() && this->readCRLF())
    return (true);
  return (false);
}

bool	HttpParser::readMethod()
{
  std::string	method;

  this->prepare();

  if (this->readText("OPTIONS") ||
      this->readText("GET") ||
      this->readText("HEAD") ||
      this->readText("POST") ||
      this->readText("PUT") ||
      this->readText("DELETE") ||
      this->readText("TRACE") ||
      this->readText("CONNECT") ||
      this->readExtensionMethod())
    {
      this->extract(method);
      this->consume();
      std::cout << "METHOD: " << method << std::endl;
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
  if (this->readChar('*') ||
      this->readAbsoluteURI() ||
      this->readPathAbsolute() ||
      this->readAuthority())
    return (true);
  return (false);
}

bool	HttpParser::readHttpVersion()
{
  if (this->readText("HTTP") &&
      this->readChar('/') &&
      this->readInteger() &&
      this->readChar('.') &&
      this->readInteger())
    return (true);
  return (false);
}
