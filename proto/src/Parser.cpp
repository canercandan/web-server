//
// Parser.cpp for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:33:19 2008 caner candan
// Last update Mon Aug  4 00:54:40 2008 caner candan
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
      RULE(URI::readURIReference) && CONSUM(readChar(' ')) &&
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
  return (RULEINT(readURIReferenceCond1) &&
	  RULEINT(readURIReferenceCond2));
}

bool	URI::readURIReferenceCond1(HttpConsumer* hc)
{
  return (RULE(readAbsoluteURI) ||
	  RULE(readRelativeURI));
}

bool	URI::readURIReferenceCond2(HttpConsumer* hc)
{
  return (CONSUM(readChar('#')) &&
	  RULE(readFragment));
}

bool	URI::readAbsoluteURI(HttpConsumer* hc)
{
  return (RULE(readScheme)	&&
	  CONSUM(readChar(':')) &&
	  (RULE(readHierPart)	||
	   RULE(readOpaquePart)));
}

bool	URI::readRelativeURI(HttpConsumer* hc)
{
  return ((RULE(readNetPath)	||
	   RULE(readAbsPath)	||
	   RULE(readRelPath))	&&
	  RULEINT(readRelativeURICond));
}

bool	URI::readRelativeURICond(HttpConsumer* hc)
{
  return (CONSUM(readChar('?')) &&
	  RULE(readQuery));
}

bool	URI::readFragment(HttpConsumer* hc)
{
  return (LOOPM(readUric));
}

bool	URI::readQuery(HttpConsumer* hc)
{
  return (LOOPM(readUric));
}

bool	URI::readUric(HttpConsumer* hc)
{
  return (RULE(readReserved)	||
	  RULE(readUnreserved)	||
	  RULE(readEscaped));
}

bool	URI::readUricNoSlash(HttpConsumer* hc)
{
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

bool	URI::readSchemeLoop(HttpConsumer* hc)
{
  return (RULE(readAlpha)	||
	  RULE(readDigit)	||
	  CONSUM(readChar('+'))	||
	  CONSUM(readChar('-'))	||
	  CONSUM(readChar('.')));
}

bool	URI::readScheme(HttpConsumer* hc)
{
  return (RULE(readAlpha) &&
	  LOOPM(readSchemeLoop));
}

bool	URI::readHierPart(HttpConsumer* hc)
{
  return ((RULE(readNetPath)	||
	   RULE(readAbsPath))	&&
	  RULEINT(readHierPartCond));
}

bool	URI::readHierPartCond(HttpConsumer* hc)
{
  return (CONSUM(readChar('?')) &&
	  RULE(readQuery));
}

bool	URI::readOpaquePart(HttpConsumer* hc)
{
  return (RULE(readUricNoSlash) &&
	  LOOPM(readUric));
}

bool	URI::readNetPath(HttpConsumer* hc)
{
  return (CONSUM(readText("//"))	&&
	  RULE(readAuthority)		&&
	  RULEINT(readAbsPath));
}

bool	URI::readAbsPath(HttpConsumer* hc)
{
  return (CONSUM(readChar('/')) &&
	  RULE(readPathSegments));
}

bool	URI::readRelPath(HttpConsumer* hc)
{
  return (RULE(readRelSegment) &&
	  RULEINT(readAbsPath));
}

bool	URI::readRelSegmentLoop(HttpConsumer* hc)
{
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
  return (LOOPA(readRelSegmentLoop));
}

bool	URI::readAuthority(HttpConsumer* hc)
{
  return (RULE(readServer) ||
	  RULE(readRegName));
}

bool	URI::readServer(HttpConsumer* hc)
{
  return (RULEINT(readServerCond));
}

bool	URI::readServerCond(HttpConsumer* hc)
{
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
  return (LOOPA(readRegNameLoop));
}

bool	URI::readRegNameLoop(HttpConsumer* hc)
{
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
  return (LOOPM(readUserinfoLoop));
}

bool	URI::readUserinfoLoop(HttpConsumer* hc)
{
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
  return (RULE(readHost)	&&
	  RULEINT(readHostportCond));
}

bool	URI::readHostportCond(HttpConsumer* hc)
{
  return (CONSUM(readChar(':')) &&
	  RULE(readPort));
}

bool	URI::readHost(HttpConsumer* hc)
{
  return (RULE(readHostname) ||
	  RULE(readIPv4address));
}

bool	URI::readPort(HttpConsumer* hc)
{
  return (LOOPM(readDigit));
}

bool	URI::readHostname(HttpConsumer* hc)
{
  return (LOOPM(readHostnameLoop)	&&
	  RULE(readToplabel)		&&
	  CONSUMINT(readChar(':')));
}

bool	URI::readHostnameLoop(HttpConsumer* hc)
{
  return (RULE(readDomainlabel) ||
	  CONSUM(readChar('.')));
}

bool	URI::readIPv4address(HttpConsumer* hc)
{
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
  return (RULE(readAlphanum)		||
	  (RULE(readAlphanum)		&&
	   LOOPM(readDomainlabelLoop)	&&
	   RULE(readAlphanum)));
}

bool	URI::readDomainlabelLoop(HttpConsumer* hc)
{
  return (RULE(readAlphanum) ||
	  CONSUM(readChar('-')));
}

bool	URI::readToplabel(HttpConsumer* hc)
{
  return (RULE(readAlpha)		||
	  (RULE(readAlpha)		&&
	   LOOPM(readToplabelLoop)	&&
	   RULE(readAlphanum)));
}

bool	URI::readToplabelLoop(HttpConsumer* hc)
{
  return (RULE(readAlphanum)	||
	  CONSUM(readChar('-')));
}

bool	URI::readPathSegments(HttpConsumer* hc)
{
  return (RULE(readSegment) &&
	  LOOPM(readPathSegmentsLoop));
}

bool	URI::readPathSegmentsLoop(HttpConsumer* hc)
{
  return (CONSUM(readChar('/')) &&
	  RULE(readSegment));
}

bool	URI::readSegment(HttpConsumer* hc)
{
  return (LOOPM(readPchar) &&
	  LOOPM(readSegmentLoop));
}

bool	URI::readSegmentLoop(HttpConsumer* hc)
{
  return (CONSUM(readChar(';')) &&
	  RULE(readParam));
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
  return (LOOPM(readPchar));
}

bool	URI::readReserved(HttpConsumer* hc)
{
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
