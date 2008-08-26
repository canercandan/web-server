#ifndef __HTTPPARSER_H__
# define __HTTPPARSER_H__

# include "IParser.h"
# include "Consumer.h"

//! HttpParser
class HttpParser : public IParser
{
public:
  //! \param consumer a Consumer pointer
  HttpParser(Consumer* consumer);

  //! read a http char
  bool	readChar();
  //! check if exist a ctl
  bool	peekCTL();
  //! check if exist a separator
  bool	peekSeparators();
  //! read a token
  bool	readToken();
  //! read a request
  bool	readRequest();
  //! request rule option
  bool	readRequestOpt();
  //! request rule option part 2
  bool	readRequestOptPart2();
  //! read a request line
  bool	readRequestLine();
  //! read a method
  bool	readMethod();
  //! read an extension method
  bool	readExtensionMethod();
  //! read a request uri
  bool	readRequestURI();
  //! read a path absolute query
  bool	readPathAbsoluteQuery();
  //! read a http version
  bool	readHttpVersion();
  //! read a general header
  bool	readGeneralHeader();
  //! read a cache control
  bool	readCacheControl();
  //! read a cache directive
  bool	readCacheDirective();
  //! read a cache directive - sharp part
  bool	readCacheDirectiveSharp();
  //! read a cache extension
  bool	readCacheExtension();
  //! read a delta seconds
  bool	readDeltaSeconds();
  //! read a field name
  bool	readFieldName();
  //! read a field name - sharp part
  bool	readFieldNameSharp();
  //! read a cache request directive
  bool	readCacheRequestDirective();
  //! read a cache response directive
  bool	readCacheResponseDirective();
  //! read a connection
  bool	readConnection();
  //! read a date
  bool	readDate();
  //! read a pragma
  bool	readPragma();
  //! read a trailer
  bool	readTrailer();
  //! read a transfer encoding
  bool	readTransferEncoding();
  //! read a upgrade
  bool	readUpgrade();
  //! read a via
  bool	readVia();
  //! read a warning
  bool	readWarning();
  //! read a request header
  bool	readRequestHeader();
  //! read an accept
  bool	readAccept();
  //! read an accept charset
  bool	readAcceptCharset();
  //! read an accept encoding
  bool	readAcceptEncoding();
  //! read an accept langage
  bool	readAcceptLangage();
  //! read an authorization
  bool	readAuthorization();
  //! read an except
  bool	readExcept();
  //! read a from
  bool	readFrom();
  //! read if match
  bool	readIfMatch();
  //! read if mofidied since ...
  bool	readIfModifiedSince();
  //! read if none match
  bool	readIfNoneMatch();
  //! read if range
  bool	readIfRange();
  //! read if unmodified since ...
  bool	readIfUnmodifiedSince();
  //! read max forward
  bool	readMaxForwards();
  //! read proxy authorization
  bool	readProxyAuthorization();
  //! read referer
  bool	readReferer();
  //! read TE
  bool	readTE();
  //! read user agent
  bool	readUserAgent();
  //! read user agent - part2
  bool	readUserAgentPart2();
  //! read product
  bool	readProduct();
  //! read product - option
  bool	readProductOpt();
  //! read product - version
  bool	readProductVersion();
  //! read comment
  bool	readComment();
  //! read comment - option
  bool	readCommentOpt();
  //! read ctext
  bool	readCtext();
  //! read quoted string
  bool	readQuotedString();
  //! read quoted pair
  bool	readQuotedPair();
  //! read entity header
  bool	readEntityHeader();
};

#endif // !__HTTPPARSER_H__
