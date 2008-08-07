//
// HttpParser.cpp for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:53:09 2008 caner candan
// Last update Thu Aug  7 06:25:09 2008 caner candan
//

#include <iostream>
#include "HttpParser.h"

HttpParser::HttpParser(HttpProducer* prod)
  : URIParser(prod)
{}

HttpParser::~HttpParser()
{}

void	HttpParser::run()
{
  if (this->readRequest() && this->eof())
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	HttpParser::readRequest()
{
  RULE(readRequestLine());
}

bool	HttpParser::readRequestLine()
{
  RULE(readMethod() && SP &&
       readRequestURI() && SP &&
       readHttpVersion() && CRLF);
}

bool	HttpParser::readRequestURI()
{
  RULE(readChar('*') ||
       readAbsoluteURI() ||
       readPathAbsolute() ||
       readAuthority());
}

bool	HttpParser::readGeneralHeader()
{
  RULE(readCacheControl() ||
       readConnection() ||
       readDate() ||
       readPragma() ||
       readTrailer() ||
       readTransferEncoding() ||
       readUpgrade() ||
       readVia() ||
       readWarning());
}

bool	HttpParser::readCacheControl()
{
  RULE(false);
}

bool	HttpParser::readConnection()
{
  RULE(false);
}

bool	HttpParser::readDate()
{
  RULE(false);
}

bool	HttpParser::readPragma()
{
  RULE(false);
}

bool	HttpParser::readTrailer()
{
  RULE(false);
}

bool	HttpParser::readTransferEncoding()
{
  RULE(false);
}

bool	HttpParser::readUpgrade()
{
  RULE(false);
}

bool	HttpParser::readVia()
{
  RULE(false);
}

bool	HttpParser::readWarning()
{
  RULE(false);
}

bool	HttpParser::readMethod()
{
  RULE(readText("OPTIONS") ||
       readText("GET") ||
       readText("HEAD") ||
       readText("POST") ||
       readText("PUT") ||
       readText("DELETE") ||
       readText("TRACE") ||
       readText("CONNECT") ||
       readExtensionMethod());
}

bool	HttpParser::readExtensionMethod()
{
  RULE(false);
}

bool	HttpParser::readHttpVersion()
{
  RULE(readText("HTTP") &&
       readChar('/') &&
       readInteger() &&
       readChar('.') &&
       readInteger());
}
