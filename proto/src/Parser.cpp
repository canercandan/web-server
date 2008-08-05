//
// Parser.cpp for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:33:19 2008 caner candan
// Last update Tue Aug  5 15:37:24 2008 majdi toumi
//

#include <iostream>
#include "Parser.h"
#include "HttpRequest.h"

using namespace	Parser;

void	Debug::getBuf(HttpConsumer* hc,
		      const std::string& sFunc)
{
  if (DEBUG_PARSER)
    std::cout << '[' << sFunc << ']'
	      << " -> "
	      << '[' << hc->getBuf() << ']'
	      << std::endl;
}

bool	Debug::getRes(const std::string& sFunc,
		      bool res)
{
  if (DEBUG_PARSER)
    std::cout << '[' << sFunc << ']'
	      << " -> "
	      << '[' << std::boolalpha << res << ']'
	      << std::endl;
  return (res);
}

void	Http::run(HttpConsumer* hc)
{
  if (RULE(readRequest))
    std::cout << "Valid Request" << std::endl;
  else
    std::cout << "Invalid Request" << std::endl;
}

bool	Http::readRequest(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readRequestLine));
}

bool	Http::readRequestLine(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readMethod)		&&
	 CONSUM(readChar(' '))		&&
	 RULE(readRequestURI)		&&
	 CONSUM(readChar(' '))		&&
	 RULE(readHttpVersion)		&&
	 CONSUM(readText("\r\n")));
}

bool	Http::readRequestURI(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('*'))		||
	 RULE(URI::readAbsoluteURI)	||
	 RULE(URI::readAbsPath)	||
	 RULE(URI::readAuthority));
}

bool	Http::readGeneralHeader(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readCacheControl)	||
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
  BUFFER();
  RETURN(false);
}

bool	Http::readConnection(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readDate(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readPragma(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readTrailer(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readTransferEncoding(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readUpgrade(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readVia(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readWarning(HttpConsumer* hc)
{
  BUFFER();
  RETURN(false);
}

bool	Http::readMethod(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readText("OPTIONS"))	||
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
  BUFFER();
  RETURN(false);
}

bool	Http::readHttpVersion(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readText("HTTP"))	&&
	 CONSUM(readChar('/'))		&&
	 CONSUM(readInteger())		&&
	 CONSUM(readChar('.'))		&&
	 CONSUM(readInteger()));
}

bool	URI::readURIReference(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULEINT(readURIReferenceCond1) &&
	 RULEINT(readURIReferenceCond2));
}

bool	URI::readURIReferenceCond1(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAbsoluteURI) ||
	 RULE(readRelativeURI));
}

bool	URI::readURIReferenceCond2(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('#')) &&
	 RULE(readFragment));
}

bool	URI::readAbsoluteURI(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readScheme)	&&
	 CONSUM(readChar(':')) &&
	 (RULE(readHierPart)	||
	  RULE(readOpaquePart)));
}

bool	URI::readRelativeURI(HttpConsumer* hc)
{
  BUFFER();
  RETURN((RULE(readNetPath)	||
	  RULE(readAbsPath)	||
	  RULE(readRelPath))	&&
	 RULEINT(readRelativeURICond));
}

bool	URI::readRelativeURICond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('?')) &&
	 RULE(readQuery));
}

bool	URI::readFragment(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readUric));
}

bool	URI::readQuery(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readUric));
}

bool	URI::readUric(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readReserved)	||
	 RULE(readUnreserved)	||
	 RULE(readEscaped));
}

bool	URI::readUricNoSlash(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUnreserved)	||
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
  BUFFER();
  RETURN(RULE(readAlpha) &&
	 LOOPM(readSchemeLoop));
}

bool	URI::readSchemeLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlpha)	||
	 RULE(readDigit)	||
	 CONSUM(readChar('+'))	||
	 CONSUM(readChar('-'))	||
	 CONSUM(readChar('.')));
}

bool	URI::readHierPart(HttpConsumer* hc)
{
  BUFFER();
  RETURN((RULE(readNetPath)	||
	  RULE(readAbsPath))	&&
	 RULEINT(readHierPartCond));
}

bool	URI::readHierPartCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('?')) &&
	 RULE(readQuery));
}

bool	URI::readOpaquePart(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUricNoSlash) &&
	 LOOPM(readUric));
}

bool	URI::readNetPath(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readText("//"))	&&
	 RULE(readAuthority)		&&
	 RULEINT(readAbsPath));
}

bool	URI::readAbsPath(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('/')) &&
	 RULE(readPathSegments));
}

bool	URI::readRelPath(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readRelSegment) &&
	 RULEINT(readAbsPath));
}

bool	URI::readRelSegmentLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUnreserved)	||
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
  BUFFER();
  RETURN(LOOPA(readRelSegmentLoop));
}

bool	URI::readAuthority(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readServer) ||
	 RULE(readRegName));
}

bool	URI::readServer(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULEINT(readServerCond));
}

bool	URI::readServerCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULEINT(readServerCondCond) &&
	 RULE(readHostport));
}

bool	URI::readServerCondCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUserinfo) &&
	 CONSUM(readChar('@')));
}

bool	URI::readRegName(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPA(readRegNameLoop));
}

bool	URI::readRegNameLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUnreserved)	||
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
  BUFFER();
  RETURN(LOOPM(readUserinfoLoop));
}

bool	URI::readUserinfoLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUnreserved)	||
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
  BUFFER();
  RETURN(RULE(readHost)	&&
	 RULEINT(readHostportCond));
}

bool	URI::readHostportCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar(':')) &&
	 RULE(readPort));
}

bool	URI::readHost(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readHostname) ||
	 RULE(readIPv4address));
}

bool	URI::readPort(HttpConsumer* hc)
{
  BUFFER();
  RETURN (LOOPM(readDigit));
}

bool	URI::readHostname(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readHostnameLoop)	&&
	 RULE(readToplabel)		&&
	 CONSUMINT(readChar('.')));
}

bool	URI::readHostnameLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readDomainlabel) &&
	 CONSUM(readChar('.')));
}

bool	URI::readIPv4address(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPA(readDigit)	&&
	 CONSUM(readChar('.'))	&&
	 LOOPA(readDigit)	&&
	 CONSUM(readChar('.'))	&&
	 LOOPA(readDigit)	&&
	 CONSUM(readChar('.'))	&&
	 LOOPA(readDigit));
}

bool	URI::readDomainlabel(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlphanum) ||
	 RULE(readAlphanum) && RULEINT(readDomainlabelCond));
}

bool	URI::readDomainlabelCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readDomainlabelLoop));// && RULEINT(readAlphanum));
}

bool	URI::readDomainlabelLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlphanum) ||
	 CONSUM(readChar('-')));
}

bool	URI::readToplabel(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlpha) &&
	 RULEINT(readToplabelCond));
}

bool	URI::readToplabelCond(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readToplabelLoop));// && RULEINT(readAlphanum));
}

bool	URI::readToplabelLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlphanum) ||
	 CONSUM(readChar('-')));
}

bool	URI::readPathSegments(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readSegment) &&
	 LOOPM(readPathSegmentsLoop));
}

bool	URI::readPathSegmentsLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('/')) &&
	 RULE(readSegment));
}

bool	URI::readSegment(HttpConsumer* hc)
{
  BUFFER();
  RETURN(LOOPM(readPchar) &&
	 LOOPM(readSegmentLoop));
}

bool	URI::readSegmentLoop(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar(';')) &&
	 RULE(readParam));
}

bool	URI::readPchar(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readUnreserved)	||
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
  BUFFER();
  RETURN(LOOPM(readPchar));
}

bool	URI::readReserved(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar(';'))	||
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
  BUFFER();
  RETURN(RULE(readAlphanum) ||
	 RULE(readMark));
}

bool	URI::readEscaped(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('%'))	&&
	 RULE(readHex)		&&
	 RULE(readHex));
}

bool	URI::readAlphanum(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readAlpha) ||
	 RULE(readDigit));
}

bool	URI::readMark(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readChar('-'))	||
	 CONSUM(readChar('_'))	||
	 CONSUM(readChar('.'))	||
	 CONSUM(readChar('!'))	||
	 CONSUM(readChar('~'))	||
	 CONSUM(readChar('*'))	||
	 CONSUM(readChar('\'')) ||
	 CONSUM(readChar('('))	||
	 CONSUM(readChar(')')));
}

bool	URI::readHex(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readDigit)		||
	 CONSUM(readRange('A', 'F'))	||
	 CONSUM(readRange('a', 'f')));
}

bool	URI::readDigit(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readRange('0', '9')));
}

bool	URI::readAlpha(HttpConsumer* hc)
{
  BUFFER();
  RETURN(RULE(readLowalpha) ||
	 RULE(readUpalpha));
}

bool	URI::readLowalpha(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readRange('a', 'z')));
}

bool	URI::readUpalpha(HttpConsumer* hc)
{
  BUFFER();
  RETURN(CONSUM(readRange('A', 'Z')));
}
