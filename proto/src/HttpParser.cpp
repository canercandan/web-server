//
// HttpParser.cpp for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:53:09 2008 caner candan
// Last update Wed Aug  6 17:55:45 2008 caner candan
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
  DEBUG_ENTER();
  RULE(readRequestLine());
}

bool	HttpParser::readRequestLine()
{
  DEBUG_ENTER();
  RULE(readMethod() &&
       readChar(' ') &&
       readRequestURI() &&
       readChar(' ') &&
       readHttpVersion() &&
       readText("\r\n"));
}

bool	HttpParser::readRequestURI()
{
  DEBUG_ENTER();
//   RULE(readChar('*') ||
//        readAbsoluteURI() ||
//        readAbsPath() ||
//        readAuthority());
  RULE(readChar('*'));
}

bool	HttpParser::readGeneralHeader()
{
  DEBUG_ENTER();
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
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readConnection()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readDate()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readPragma()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readTrailer()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readTransferEncoding()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readUpgrade()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readVia()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readWarning()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readMethod()
{
  DEBUG_ENTER();
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
  DEBUG_ENTER();
  RULE(false);
}

bool	HttpParser::readHttpVersion()
{
  DEBUG_ENTER();
  RULE(readText("HTTP") &&
       readChar('/') &&
       readInteger() &&
       readChar('.') &&
       readInteger());
}
