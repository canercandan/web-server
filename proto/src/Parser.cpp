//
// Parser.cpp for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:33:19 2008 caner candan
// Last update Mon Aug  4 02:47:03 2008 caner candan
//

#include <iostream>
#include "Parser.h"
#include "HttpRequest.h"

using namespace	Parser;

void	Http::run(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  if (RULE(readRequest))
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	Http::readRequest(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readRequestLine));
}

bool	Http::readRequestLine(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readMethod)		&&
	  CONSUM(readChar(' '))		&&
	  RULE(URI::readURIReference)	&&
	  CONSUM(readChar(' '))		&&
	  RULE(readHttpVersion)		&&
	  CONSUM(readText("\r\n")));
}

bool	Http::readGeneralHeader(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readCacheControl)	||
	  RULE(readConnection)		||
	  RULE(readDate)		||
	  RULE(readPragma)		||
	  RULE(readTrailer)		||
	  RULE(readTransferEncoding)	||
	  RULE(readUpgrade)		||
	  RULE(readVia)			||
	  RULE(readWarning));
}

bool	Http::readCacheControl(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readConnection(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readDate(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readPragma(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readTrailer(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readTransferEncoding(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readUpgrade(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readVia(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readWarning(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readMethod(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
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

bool	Http::readExtensionMethod(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (false);
}

bool	Http::readHttpVersion(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readText("HTTP"))	&&
	  CONSUM(readChar('/'))		&&
	  CONSUM(readInteger())		&&
	  CONSUM(readChar('.'))		&&
	  CONSUM(readInteger()));
}

bool	URI::readURIReference(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULEINT(readURIReferenceCond1) &&
	  RULEINT(readURIReferenceCond2));
}

bool	URI::readURIReferenceCond1(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAbsoluteURI) ||
	  RULE(readRelativeURI));
}

bool	URI::readURIReferenceCond2(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('#')) &&
	  RULE(readFragment));
}

bool	URI::readAbsoluteURI(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readScheme)	&&
	  CONSUM(readChar(':')) &&
	  (RULE(readHierPart)	||
	   RULE(readOpaquePart)));
}

bool	URI::readRelativeURI(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return ((RULE(readNetPath)	||
	   RULE(readAbsPath)	||
	   RULE(readRelPath))	&&
	  RULEINT(readRelativeURICond));
}

bool	URI::readRelativeURICond(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('?')) &&
	  RULE(readQuery));
}

bool	URI::readFragment(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readUric));
}

bool	URI::readQuery(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readUric));
}

bool	URI::readUric(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readReserved)	||
	  RULE(readUnreserved)	||
	  RULE(readEscaped));
}

bool	URI::readUricNoSlash(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readUnreserved)	||
	  RULE(readEscaped)	||
	  CONSUM(readChar(';'))	||
	  CONSUM(readChar('?'))	||
	  CONSUM(readChar(':'))	||
	  CONSUM(readChar('@'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(',')));
}

bool	URI::readScheme(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlpha) &&
	  LOOPM(readSchemeLoop));
}

bool	URI::readSchemeLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlpha)	||
	  RULE(readDigit)	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('-'))	||
	  CONSUM(readChar('.')));
}

bool	URI::readHierPart(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return ((RULE(readNetPath)	||
	   RULE(readAbsPath))	&&
	  RULEINT(readHierPartCond));
}

bool	URI::readHierPartCond(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('?')) &&
	  RULE(readQuery));
}

bool	URI::readOpaquePart(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << std::endl;
  return (RULE(readUricNoSlash) &&
	  LOOPM(readUric));
}

bool	URI::readNetPath(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readText("//"))	&&
	  RULE(readAuthority)		&&
	  RULEINT(readAbsPath));
}

bool	URI::readAbsPath(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('/')) &&
	  RULE(readPathSegments));
}

bool	URI::readRelPath(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readRelSegment) &&
	  RULEINT(readAbsPath));
}

bool	URI::readRelSegmentLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readUnreserved)	||
	  RULE(readEscaped)	||
	  CONSUM(readChar(';'))	||
	  CONSUM(readChar('@'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(',')));
}

bool	URI::readRelSegment(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPA(readRelSegmentLoop));
}

bool	URI::readAuthority(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << std::endl;
  return (RULE(readServer) ||
	  RULE(readRegName));
}

bool	URI::readServer(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULEINT(readServerCond));
}

bool	URI::readServerCond(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << std::endl;
  return (RULEINT(readServerCondCond) &&
	  RULE(readHostport));
}

bool	URI::readServerCondCond(HttpConsumer* hc)
{
  return (RULE(readUserinfo) &&
	  CONSUM(readChar('@')));
}

bool	URI::readRegName(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPA(readRegNameLoop));
}

bool	URI::readRegNameLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readUnreserved)	||
	  RULE(readEscaped)	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(','))	||
	  CONSUM(readChar(';'))	||
	  CONSUM(readChar(':'))	||
	  CONSUM(readChar('@'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+')));
}

bool	URI::readUserinfo(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readUserinfoLoop));
}

bool	URI::readUserinfoLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readUnreserved)	||
	  RULE(readEscaped)	||
	  CONSUM(readChar(';'))	||
	  CONSUM(readChar(':'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(',')));
}

bool	URI::readHostport(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readHost)	&&
	  RULEINT(readHostportCond));
}

bool	URI::readHostportCond(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar(':')) &&
	  RULE(readPort));
}

bool	URI::readHost(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readHostname) ||
	  RULE(readIPv4address));
}

bool	URI::readPort(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readDigit));
}

bool	URI::readHostname(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readHostnameLoop)	&&
	  RULE(readToplabel)		&&
	  CONSUMINT(readChar('.')));
}

bool	URI::readHostnameLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  std::cout << "readHostnameLoop" << std::endl;
  return (RULE(readDomainlabel) ||
	  CONSUM(readChar('.')));
}

bool	URI::readIPv4address(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPA(readDigit)	&&
	  CONSUM(readChar('.'))	&&
	  LOOPA(readDigit)	&&
	  CONSUM(readChar('.'))	&&
	  LOOPA(readDigit)	&&
	  CONSUM(readChar('.'))	&&
	  LOOPA(readDigit));
}

bool	URI::readDomainlabel(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlphanum)		||
	  (RULE(readAlphanum)		&&
	   LOOPM(readDomainlabelLoop)));
}

bool	URI::readDomainlabelLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlphanum)		||
	  (CONSUM(readChar('-'))	&&
	   RULE(readAlphanum)));
}

bool	URI::readToplabel(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlpha)		||
	  (RULE(readAlpha)		&&
	   LOOPM(readToplabelLoop)));
}

bool	URI::readToplabelLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlphanum)		||
	  (CONSUM(readChar('-'))	&&
	   RULE(readAlphanum)));
}

bool	URI::readPathSegments(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readSegment) &&
	  LOOPM(readPathSegmentsLoop));
}

bool	URI::readPathSegmentsLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('/')) &&
	  RULE(readSegment));
}

bool	URI::readSegment(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readPchar) &&
	  LOOPM(readSegmentLoop));
}

bool	URI::readSegmentLoop(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar(';')) &&
	  RULE(readParam));
}

bool	URI::readPchar(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
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
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (LOOPM(readPchar));
}

bool	URI::readReserved(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar(';'))	||
	  CONSUM(readChar('/'))	||
	  CONSUM(readChar('?'))	||
	  CONSUM(readChar(':'))	||
	  CONSUM(readChar('@'))	||
	  CONSUM(readChar('&'))	||
	  CONSUM(readChar('='))	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('$'))	||
	  CONSUM(readChar(',')));
}

bool	URI::readUnreserved(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlphanum) ||
	  RULE(readMark));
}

bool	URI::readEscaped(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readChar('%'))	&&
	  RULE(readHex)		&&
	  RULE(readHex));
}

bool	URI::readAlphanum(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readAlpha) ||
	  RULE(readDigit));
}

bool	URI::readMark(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
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
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readDigit)		||
	  CONSUM(readRange('A', 'F'))	||
	  CONSUM(readRange('a', 'f')));
}

bool	URI::readDigit(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readRange('0', '9')));
}

bool	URI::readAlpha(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (RULE(readLowalpha) ||
	  RULE(readUpalpha));
}

bool	URI::readLowalpha(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readRange('a', 'z')));
}

bool	URI::readUpalpha(HttpConsumer* hc)
{
  if (DEBUG)
    std::cout << __FUNCTION__ << "->"
	      << hc->getBuf() << std::endl;
  return (CONSUM(readRange('A', 'Z')));
}
