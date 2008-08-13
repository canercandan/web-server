//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:46 2008 morgan armand
// Last update Wed Aug 13 12:42:00 2008 caner candan
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "URIParser.h"
#include "HttpRequest.h"

class	HttpParser : public URIParser
{
public:
  HttpParser(HttpProducer* prod, HttpRequest* request);
  ~HttpParser();

  bool	readCHAR();

  bool	peekCTL();
  bool	readCTL();

  bool	peekSeparators();
  bool	readSeparators();

  bool	readToken();

  bool	readRequest();
  bool	readRequestOpt();	// NOT RFC
  bool	readRequestOptPart2();	// NOT RFC

  bool	readRequestLine();

  bool	readMethod();
  bool	readExtensionMethod();

  bool	readRequestURI();
  bool	readHttpVersion();

  bool	readGeneralHeader();

  bool	readCacheControl();
  bool	readCacheDirective();
  bool	readCacheDirectiveSharp();
  bool	readDeltaSeconds();
  bool	readCacheExtension();

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
  bool	readExpect();
  bool	readFrom();
  //  bool	readHost();
  bool	readIfMatch();
  bool	readIfModifiedSince();
  bool	readIfNoneMatch();
  bool	readIfRange();
  bool	readIfUnmodifiedSince();
  bool	readMaxForwards();
  bool	readProxyAuthorization();
  //  bool	readRange();
  bool	readReferer();
  bool	readTE();

  bool	readUserAgent();
  bool	readUserAgentPart2();

  bool	readProduct();
  bool	readProductOpt();
  bool	readProductVersion();

  bool	readComment();
  bool	readCommentOpt();

  bool	readCtext();
  bool	readQuotedPair();

  bool	readEntityHeader();
};

#endif // !__HTTP_PARSER_H__
