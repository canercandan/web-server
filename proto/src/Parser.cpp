//
// Parser.cpp for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:33:19 2008 caner candan
// Last update Sun Aug  3 16:09:49 2008 caner candan
//

#include <iostream>
#include "Parser.h"
#include "HttpRequest.h"

using namespace	Parser;

void	Http::run(HttpConsumer* hc)
{
  if (RULE(readRequest))
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	Http::readRequest(HttpConsumer* hc)
{
  if (RULE(readRequestLine))
    return (true);
  return (false);
}

bool	Http::readRequestLine(HttpConsumer* hc)
{
  if (RULE(readMethod) && CONSUM(readChar(' ')) &&
      RULE(URI::readRequestURI) && CONSUM(readChar(' ')) &&
      RULE(readHttpVersion) &&
      CONSUM(readText("\r\n")))
    return (true);
  return (false);
}

bool	Http::readGeneralHeader(HttpConsumer* hc)
{
  if (RULE(readCacheControl)	||
      RULE(readConnection)	||
      RULE(readDate)		||
      RULE(readPragma)		||
      RULE(readTrailer)		||
      RULE(readTransferEncoding)||
      RULE(readUpgrade)		||
      RULE(readVia)		||
      RULE(readWarning))
    return (true);
  return (false);
}

bool	Http::readCacheControl(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readConnection(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readDate(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readPragma(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readTrailer(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readTransferEncoding(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readUpgrade(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readVia(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readWarning(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readMethod(HttpConsumer* hc)
{
  return (CONSUM(readText("OPTIONS"))	||
	  CONSUM(readText("GET"))	||
	  CONSUM(readText("HEAD"))	||
	  CONSUM(readText("POST"))	||
	  CONSUM(readText("PUT"))	||
	  CONSUM(readText("DELETE"))	||
	  CONSUM(readText("TRACE"))	||
	  CONSUM(readText("CONNECT"))	||
	  RULE(readExtensionMethod));
}

bool	Http::readExtensionMethod(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readHttpVersion(HttpConsumer* hc)
{
  if (CONSUM(readText("HTTP")) &&
      CONSUM(readChar('/')) &&
      CONSUM(readInteger()) &&
      CONSUM(readChar('.')) &&
      CONSUM(readInteger()))
    return (true);
  return (false);
}

bool	URI::readURIReference(HttpConsumer* hc)
{
  return ((RULE(readAbsoluteURI)	||
	   RULE(readRelativeURI))	&&
	  CONSUM(readChar('#'))		&&
	  RULE(readFragment));
}

bool	URI::readRelativeURI(HttpConsumer*)
{
  return (false);
}

bool	URI::readFragment(HttpConsumer*)
{
  return (false);
}

bool	URI::readRequestURI(HttpConsumer* hc)
{
  return (CONSUM(readChar('*'))	||
	  RULE(readAbsoluteURI)	||
	  RULE(readAbsPath)	||
	  RULE(readAuthority));
}

bool	URI::readAbsoluteURI(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URI::readAbsPath(HttpConsumer* hc)
{
  return (CONSUM(readChar('/')) &&
	  RULE(readPathSegments));
}

bool	URI::readAuthority(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URI::readPathSegments(HttpConsumer* hc)
{
  if (!RULE(readSegment))
    return (false);
  while (CONSUM(readChar('/')))
    RULE(readSegment);
  return (true);
}

bool	URI::readSegment(HttpConsumer* hc)
{
  while (RULE(readPchar));
  while (CONSUM(readChar(';')) && RULE(readParam));
  return (true);
}

bool	URI::readPchar(HttpConsumer* hc)
{
  return (RULE(readUnreserved)	||
	  RULE(readEscaped)	||
	  CONSUM(readChar(':'))	||
	  CONSUM(readChar('@'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(',')));
}

bool	URI::readParam(HttpConsumer* hc)
{
  while (RULE(readPchar));
  return (true);
}

bool	URI::readUnreserved(HttpConsumer* hc)
{
  return (RULE(readAlphanum) ||
	  RULE(readMark));
}

bool	URI::readEscaped(HttpConsumer* hc)
{
  return (CONSUM(readChar('%'))	&&
	  RULE(readHex)		&&
	  RULE(readHex));
}

bool	URI::readAlphanum(HttpConsumer* hc)
{
  return (RULE(readAlpha) ||
	  RULE(readDigit));
}

bool	URI::readMark(HttpConsumer* hc)
{
  return (CONSUM(readChar('-'))	||
	  CONSUM(readChar('_'))	||
	  CONSUM(readChar('.'))	||
	  CONSUM(readChar('!'))	||
	  CONSUM(readChar('~'))	||
	  CONSUM(readChar('*'))	||
	  CONSUM(readChar('\''))||
	  CONSUM(readChar('('))	||
	  CONSUM(readChar(')')));
}

bool	URI::readHex(HttpConsumer* hc)
{
  return (RULE(readDigit)		||
	  CONSUM(readRange('A', 'F'))	||
	  CONSUM(readRange('a', 'f')));
}

bool	URI::readDigit(HttpConsumer* hc)
{
  return (CONSUM(readRange('0', '9')));
}

bool	URI::readAlpha(HttpConsumer* hc)
{
  return (RULE(readLowalpha) ||
	  RULE(readUpalpha));
}

bool	URI::readLowalpha(HttpConsumer* hc)
{
  return (CONSUM(readRange('a', 'z')));
}

bool	URI::readUpalpha(HttpConsumer* hc)
{
  return (CONSUM(readRange('A', 'Z')));
}
