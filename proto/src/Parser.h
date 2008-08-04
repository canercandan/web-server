//
// Parser.h for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:34:55 2008 caner candan
// Last update Mon Aug  4 02:15:38 2008 caner candan
//

#ifndef __PARSER_H__
# define __PARSER_H__

# include "HttpConsumer.h"

# define DEBUG		true

# define RULE(a)	(hc->testRule(a))
# define RULEINT(a)	(hc->testRule(a) ? true : true)
# define CONSUM(a)	(hc->a)
# define CONSUMINT(a)	(hc->a ? true : true)
# define LOOPA(a)	(hc->loopRuleAdd(a))
# define LOOPM(a)	(hc->loopRuleMul(a))

namespace	Parser
{
  namespace	Http
  {
    void	run(HttpConsumer*);
    bool	readRequest(HttpConsumer*);
    bool	readRequestLine(HttpConsumer*);
    bool	readMethod(HttpConsumer*);
    bool	readExtensionMethod(HttpConsumer*);
    bool	readHttpVersion(HttpConsumer*);
    bool	readGeneralHeader(HttpConsumer*);
    bool	readCacheControl(HttpConsumer*);
    bool	readConnection(HttpConsumer*);
    bool	readDate(HttpConsumer*);
    bool	readPragma(HttpConsumer*);
    bool	readTrailer(HttpConsumer*);
    bool	readTransferEncoding(HttpConsumer*);
    bool	readUpgrade(HttpConsumer*);
    bool	readVia(HttpConsumer*);
    bool	readWarning(HttpConsumer*);
  };

  namespace	URI
  {
    bool	readURIReference(HttpConsumer*);
    bool	readURIReferenceCond1(HttpConsumer*);
    bool	readURIReferenceCond2(HttpConsumer*);
    bool	readRequestURI(HttpConsumer*);
    bool	readAbsoluteURI(HttpConsumer*);
    bool	readRelativeURI(HttpConsumer*);
    bool	readRelativeURICond(HttpConsumer*);
    bool	readFragment(HttpConsumer*);
    bool	readQuery(HttpConsumer*);
    bool	readUric(HttpConsumer*);
    bool	readUricNoSlash(HttpConsumer*);
    bool	readScheme(HttpConsumer*);
    bool	readSchemeLoop(HttpConsumer*);
    bool	readHierPart(HttpConsumer*);
    bool	readHierPartCond(HttpConsumer*);
    bool	readOpaquePart(HttpConsumer*);
    bool	readNetPath(HttpConsumer*);
    bool	readAbsPath(HttpConsumer*);
    bool	readRelPath(HttpConsumer*);
    bool	readRelSegment(HttpConsumer*);
    bool	readRelSegmentLoop(HttpConsumer*);
    bool	readAuthority(HttpConsumer*);
    bool	readServer(HttpConsumer*);
    bool	readServerCond(HttpConsumer*);
    bool	readServerCondCond(HttpConsumer*);
    bool	readRegName(HttpConsumer*);
    bool	readRegNameLoop(HttpConsumer*);
    bool	readUserinfo(HttpConsumer*);
    bool	readUserinfoLoop(HttpConsumer*);
    bool	readHostport(HttpConsumer*);
    bool	readHostportCond(HttpConsumer*);
    bool	readHost(HttpConsumer*);
    bool	readPort(HttpConsumer*);
    bool	readHostname(HttpConsumer*);
    bool	readHostnameLoop(HttpConsumer*);
    bool	readIPv4address(HttpConsumer*);
    bool	readDomainlabel(HttpConsumer*);
    bool	readDomainlabelLoop(HttpConsumer*);
    bool	readToplabel(HttpConsumer*);
    bool	readToplabelLoop(HttpConsumer*);
    bool	readPathSegments(HttpConsumer*);
    bool	readPathSegmentsLoop(HttpConsumer*);
    bool	readSegment(HttpConsumer*);
    bool	readSegmentLoop(HttpConsumer*);
    bool	readPchar(HttpConsumer*);
    bool	readParam(HttpConsumer*);
    bool	readReserved(HttpConsumer*);
    bool	readUnreserved(HttpConsumer*);
    bool	readEscaped(HttpConsumer*);
    bool	readAlphanum(HttpConsumer*);
    bool	readMark(HttpConsumer*);
    bool	readHex(HttpConsumer*);
    bool	readDigit(HttpConsumer*);
    bool	readAlpha(HttpConsumer*);
    bool	readLowalpha(HttpConsumer*);
    bool	readUpalpha(HttpConsumer*);
  };
};

#endif // __PARSER_H__
