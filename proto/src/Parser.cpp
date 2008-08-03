//
// Parser.cpp for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:33:19 2008 caner candan
// Last update Sun Aug  3 10:16:17 2008 caner candan
//

#include <iostream>
#include "Parser.h"
#include "HttpRequest.h"

using namespace	Parser;

void	Http::run(HttpConsumer* hc)
{
  if (readRequest(hc))
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	Http::readRequest(HttpConsumer* hc)
{
  if (readRequestLine(hc))
    return (true);
  return (false);
}

bool	Http::readRequestLine(HttpConsumer* hc)
{
  if (readMethod(hc) && hc->readChar(' ') &&
      URI::readRequestURI(hc) && hc->readChar(' ') &&
      readHttpVersion(hc) &&
      hc->readText("\r\n"))
    return (true);
  return (false);
}

bool	Http::readGeneralHeader(HttpConsumer* hc)
{
  if (hc->testRule(readCacheControl)		||
      hc->testRule(readConnection)		||
      hc->testRule(readDate)			||
      hc->testRule(readPragma)			||
      hc->testRule(readTrailer)			||
      hc->testRule(readTransferEncoding)	||
      hc->testRule(readUpgrade)			||
      hc->testRule(readVia)			||
      hc->testRule(readWarning))
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
  if (hc->readText("OPTIONS")	||
      hc->readText("GET")	||
      hc->readText("HEAD")	||
      hc->readText("POST")	||
      hc->readText("PUT")	||
      hc->readText("DELETE")	||
      hc->readText("TRACE")	||
      hc->readText("CONNECT")	||
      hc->testRule(readExtensionMethod))
    return (true);
  return (false);
}

bool	Http::readExtensionMethod(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	Http::readHttpVersion(HttpConsumer* hc)
{
  if (hc->readText("HTTP") &&
      hc->readChar('/') &&
      hc->readInteger() &&
      hc->readChar('.') &&
      hc->readInteger())
    return (true);
  return (false);
}

bool	URI::readRequestURI(HttpConsumer* hc)
{
  return (hc->readChar('*')		||
	  hc->testRule(readAbsoluteURI)	||
	  hc->testRule(readAbsPath)	||
	  hc->testRule(readAuthority));
}

bool	URI::readAbsoluteURI(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URI::readAbsPath(HttpConsumer* hc)
{
  return (hc->readChar('/') &&
	  readPathSegments(hc));
}

bool	URI::readAuthority(HttpConsumer*)
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URI::readPathSegments(HttpConsumer* hc)
{
  if (!readSegment(hc))
    return (false);
  while (hc->readChar('/'))
    readSegment(hc);
  return (true);
}

bool	URI::readSegment(HttpConsumer* hc)
{
  while (readPchar(hc));
  while (hc->readChar(';') && readParam(hc));
  return (true);
}

bool	URI::readPchar(HttpConsumer* hc)
{
  return (hc->testRule(readUnreserved)	||
	  hc->testRule(readEscaped)	||
	  hc->readChar(':')		||
	  hc->readChar('@')		||
	  hc->readChar('&')		||
	  hc->readChar('=')		||
	  hc->readChar('+')		||
	  hc->readChar('$')		||
	  hc->readChar(','));
}

bool	URI::readParam(HttpConsumer* hc)
{
  while (readPchar(hc));
  return (true);
}

bool	URI::readUnreserved(HttpConsumer* hc)
{
  return (hc->testRule(readAlphanum) ||
	  hc->testRule(readMark));
}

bool	URI::readEscaped(HttpConsumer* hc)
{
  return (hc->readChar('%')	&&
	  readHex(hc)		&&
	  readHex(hc));
}

bool	URI::readAlphanum(HttpConsumer* hc)
{
  return (hc->testRule(readAlpha) ||
	  hc->testRule(readDigit));
}

bool	URI::readMark(HttpConsumer* hc)
{
  return (hc->readChar('-')	||
	  hc->readChar('_')	||
	  hc->readChar('.')	||
	  hc->readChar('!')	||
	  hc->readChar('~')	||
	  hc->readChar('*')	||
	  hc->readChar('\'')	||
	  hc->readChar('(')	||
	  hc->readChar(')'));
}

bool	URI::readHex(HttpConsumer* hc)
{
  return (hc->testRule(readDigit)	||
	  hc->readRange('A', 'F')	||
	  hc->readRange('a', 'f'));
}

bool	URI::readDigit(HttpConsumer* hc)
{
  return (hc->readRange('0', '9'));
}

bool	URI::readAlpha(HttpConsumer* hc)
{
  return (hc->testRule(readLowalpha) ||
	  hc->testRule(readUpalpha));
}

bool	URI::readLowalpha(HttpConsumer* hc)
{
  return (hc->readRange('a', 'z'));
}

bool	URI::readUpalpha(HttpConsumer* hc)
{
  return (hc->readRange('A', 'Z'));
}
