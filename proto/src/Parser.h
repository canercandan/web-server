//
// Parser.h for Parser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Aug  3 08:34:55 2008 caner candan
// Last update Sun Aug  3 10:05:28 2008 caner candan
//

#ifndef __PARSER_H__
# define __PARSER_H__

# include "HttpConsumer.h"

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
    bool	readRequestURI(HttpConsumer*);
    bool	readAbsoluteURI(HttpConsumer*);
    bool	readAbsPath(HttpConsumer*);
    bool	readAuthority(HttpConsumer*);
    bool	readPathSegments(HttpConsumer*);
    bool	readSegment(HttpConsumer*);
    bool	readPchar(HttpConsumer*);
    bool	readParam(HttpConsumer*);
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
