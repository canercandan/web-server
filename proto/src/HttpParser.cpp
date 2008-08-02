//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:28:00 2008 morgan armand
// Last update Sat Aug  2 16:34:14 2008 morgan armand
//

#include <iostream>
#include "HttpParser.h"
#include "HttpRequest.h"

HttpParser::HttpParser(HttpProducer* prod)
  : URIParser(prod)
{
}

void	HttpParser::run()
{
  if (this->readRequest())
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	HttpParser::readRequest(/*HttpRequest& req*/)
{
  if (this->readRequestLine())
    return (true);
  return (false);
}

bool	HttpParser::readRequestLine()
{
  if (this->readMethod() && this->readChar(' ') &&
      this->readRequestURI() && this->readChar(' ') &&
      this->readHttpVersion() && this->readText("\r\n"))
    return (true);
  return (false);
}

bool	HttpParser::readGeneralHeader()
{
  if (this->readCacheControl() ||
      this->readConnection() ||
      this->readDate() ||
      this->readPragma() ||
      this->readTrailer() ||
      this->readTransferEncoding() ||
      this->readUpgrade() ||
      this->readVia() ||
      this->readWarning())
    return (true);
  return (false);
}

bool	HttpParser::readCacheControl()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readConnection()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readDate()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readPragma()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readTrailer()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readTransferEncoding()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readUpgrade()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readVia()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readWarning()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	HttpParser::readMethod()
{
  if (this->readText("OPTIONS")	||
      this->readText("GET")	||
      this->readText("HEAD")	||
      this->readText("POST")	||
      this->readText("PUT")	||
      this->readText("DELETE")	||
      this->readText("TRACE")	||
      this->readText("CONNECT")	||
      this->readExtensionMethod())
    return (true);
  return (false);
}

bool	HttpParser::readExtensionMethod()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
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
