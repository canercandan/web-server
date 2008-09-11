//
// HttpParser.h for 102 in /home/armand_m/zia/renewal/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Thu Sep 11 14:28:09 2008 morgan armand
// Last update Thu Sep 11 14:47:03 2008 morgan armand
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

  bool	readChar();

  bool	peekCTL();
  bool	peekSeparators();

  bool	readToken();
  bool	readRequest();
  bool	readRequestOpt();
  bool	readRequestLine();
  bool	readMethod();
  bool	readExtensionMethod();
  bool	readRequestURI();
  bool	readPathAbsoluteQuery();
  bool	readHttpVersion();
  bool	readGeneralHeader();
  bool	readCacheControl();
  bool	readCacheDirective();
  bool	readCacheExtension();
  bool	readDeltaSeconds();
  bool	readFieldName();

  bool	readCacheRequestDirective();
  bool	readCacheResponseDirective();

  bool	readConnection();
  bool	readDate();
  bool	readPragma();
  bool	readTrailer();
  bool	readTransferEncoding();
  bool	readUpgrade();
  bool	readVia();
  bool	readWarning();
  bool	readRequestHeader();

  bool	readAccept();
  bool	readAcceptCharset();
  bool	readAcceptEncoding();
  bool	readAcceptLanguage();

  bool	readAuthorization();
  bool	readExcept();
  bool	readFrom();

  bool	readIfMatch();
  bool	readIfModifiedSince();
  bool	readIfNoneMatch();
  bool	readIfRange();
  bool	readIfUnmodifiedSince();

  bool	readMaxForwards();
  bool	readProxyAuthorization();
  bool	readReferer();
  bool	readTE();
  bool	readUserAgent();

  bool	readProduct();
  bool	readProductVersion();

  bool	readComment();
  bool	readCtext();

  bool	readQuotedString();
  bool	readQuotedPair();

  bool	readEntityHeader();
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

// -----------------------REMOVE ME --------------------------

#define DEBUG_ACTIVE		0

#define DEBUG_ENTER		Debug::enter(__FUNCTION__, this->_consumer.getBuf())
#define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, ret))

#define NOT_IMPLEMENTED							\
  std::cout << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;		\
  return (false);

namespace	Debug
{
  void	enter(const char* func, const std::string& buf);
  bool	leave(const char* func, bool ret);
};

// -----------------------REMOVE ME --------------------------

#endif // !__HTTPPARSER_H__
