//
// HttpParser.cpp for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:53:09 2008 caner candan
// Last update Wed Aug  6 10:56:55 2008 caner candan
//

#include "HttpParser.h"

void	HttpParser::run(HttpConsumer* hc)
{
  if (readRequest())
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	HttpParser::readRequest(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readRequestLine));
}

bool	HttpParser::readRequestLine(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readMethod)		&&
	 CONSUM(readChar(' '))		&&
	 RULE(readRequestURI)		&&
	 CONSUM(readChar(' '))		&&
	 RULE(readHttpVersion)		&&
	 CONSUM(readText("\r\n")));
}

bool	HttpParser::readRequestURI(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(CONSUM(readChar('*'))		||
	 RULE(URI::readAbsoluteURI)	||
	 RULE(URI::readAbsPath)	||
	 RULE(URI::readAuthority));
}

bool	HttpParser::readGeneralHeader(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(RULE(readCacheControl)	||
	 RULE(readConnection)		||
	 RULE(readDate)		||
	 RULE(readPragma)		||
	 RULE(readTrailer)		||
	 RULE(readTransferEncoding)	||
	 RULE(readUpgrade)		||
	 RULE(readVia)			||
	 RULE(readWarning));
}

bool	HttpParser::readCacheControl(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readConnection(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readDate(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readPragma(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readTrailer(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readTransferEncoding(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readUpgrade(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readVia(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readWarning(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readMethod(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(CONSUM(readText("OPTIONS"))	||
	 CONSUM(readText("GET"))	||
	 CONSUM(readText("HEAD"))	||
	 CONSUM(readText("POST"))	||
	 CONSUM(readText("PUT"))	||
	 CONSUM(readText("DELETE"))	||
	 CONSUM(readText("TRACE"))	||
	 CONSUM(readText("CONNECT"))	||
	 RULE(readExtensionMethod));
}

bool	HttpParser::readExtensionMethod(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(false);
}

bool	HttpParser::readHttpVersion(HttpConsumer* hc)
{
  DEBUG_ENTER();
  DEBUG_RETURN(CONSUM(readText("HTTP"))	&&
	 CONSUM(readChar('/'))		&&
	 CONSUM(readInteger())		&&
	 CONSUM(readChar('.'))		&&
	 CONSUM(readInteger()));
}
