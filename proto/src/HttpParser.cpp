//
// HttpParser.cpp for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:53:09 2008 caner candan
// Last update Wed Aug  6 14:21:09 2008 morgan armand
//

#include <iostream>
#include "HttpParser.h"

HttpParser::HttpParser()
  : URIParser()
{}

HttpParser::~HttpParser()
{}

void	HttpParser::run()
{
  if (readRequest())
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	HttpParser::readRequest()
{
  DEBUG_ENTER();
  RULE(this->readRequestLine());
  DEBUG_RETURN(true);
}

bool	HttpParser::readRequestLine()
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(this->readMethod())	&&
	       RULE(readChar(' '))	&&
	       RULE(readRequestURI())	&&
	       RULE(readChar(' '))	&&
	       RULE(readHttpVersion())	&&
	       RULE(readText("\r\n")));
}

bool	HttpParser::readRequestURI()
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readChar('*'))		||
	       RULE(this->readAbsoluteURI())	||
	       RULE(this->readAbsPath())		||
	       RULE(this->readAuthority()));
}

bool	HttpParser::readGeneralHeader()
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readCacheControl())		||
	       RULE(readConnection())		||
	       RULE(readDate())			||
	       RULE(readPragma())		||
	       RULE(readTrailer())		||
	       RULE(readTransferEncoding())	||
	       RULE(readUpgrade())		||
	       RULE(readVia())			||
	       RULE(readWarning()));
}

bool	HttpParser::readCacheControl()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readConnection()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readDate()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readPragma()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readTrailer()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readTransferEncoding()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readUpgrade()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readVia()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readWarning()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readMethod()
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readText("OPTIONS"))	||
	       RULE(readText("GET"))		||
	       RULE(readText("HEAD"))		||
	       RULE(readText("POST"))		||
	       RULE(readText("PUT"))		||
	       RULE(readText("DELETE"))		||
	       RULE(readText("TRACE"))		||
	       RULE(readText("CONNECT"))	||
	       RULE(readExtensionMethod()));
}

bool	HttpParser::readExtensionMethod()
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readHttpVersion()
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readText("HTTP"))	&&
	       RULE(readChar('/'))	&&
	       RULE(readInteger())	&&
	       RULE(readChar('.'))	&&
	       RULE(readInteger()));
}
