//
// HttpParser.h for 102 in /home/armand_m/zia/renewal/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Thu Sep 11 14:28:09 2008 morgan armand
// Last update Sat Sep 13 22:17:15 2008 caner candan
//
#ifndef __HTTPPARSER_H__
# define __HTTPPARSER_H__

# include "IParser.h"
# include "Consumer.h"
# include "IRequest.hpp"

class	HttpParser : public IParser
{
public:
  HttpParser(Consumer& consumer, ZenZiAPI::IRequest& request);

  bool	run();
private:
  bool	_readChar();

  bool	_peekCTL();
  bool	_peekSeparators();

  bool	_readToken();
  bool	_readRequest();
  bool	_readRequestOpt();
  bool	_readRequestLine();
  bool	_readMethod();
  bool	_readExtensionMethod();
  bool	_readRequestURI();
  bool	_readPathAbsoluteQuery();
  bool	_readHttpVersion();
  bool	_readGeneralHeader();
  bool	_readCacheControl();
  bool	_readCacheDirective();
  bool	_readCacheExtension();
  bool	_readDeltaSeconds();
  bool	_readFieldName();

  bool	_readCacheRequestDirective();
  bool	_readCacheResponseDirective();

  bool	_readConnection();
  bool	_readDate();
  bool	_readPragma();
  bool	_readTrailer();
  bool	_readTransferEncoding();
  bool	_readUpgrade();
  bool	_readVia();
  bool	_readWarning();
  bool	_readRequestHeader();

  bool	_readAccept();
  bool	_readAcceptCharset();
  bool	_readAcceptEncoding();
  bool	_readAcceptLanguage();

  bool	_readAuthorization();
  bool	_readExcept();
  bool	_readFrom();

  bool	_readIfMatch();
  bool	_readIfModifiedSince();
  bool	_readIfNoneMatch();
  bool	_readIfRange();
  bool	_readIfUnmodifiedSince();

  bool	_readMaxForwards();
  bool	_readProxyAuthorization();
  bool	_readReferer();
  bool	_readTE();
  bool	_readUserAgent();

  bool	_readProduct();
  bool	_readProductVersion();

  bool	_readComment();
  bool	_readCtext();

  bool	_readQuotedString();
  bool	_readQuotedPair();

  bool	_readEntityHeader();
private:
  bool	_readRequestOptPart2();
  bool	_readCacheDirectiveSharp();
  bool	_readFieldNameSharp();
  bool	_readUserAgentPart2();
  bool	_readProductOpt();
  bool	_readCommentOpt();
private:
  Consumer&		_consumer;
  ZenZiAPI::IRequest&	_request;
};

#endif // !__HTTPPARSER_H__
