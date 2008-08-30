#ifndef __HTTPPARSER_H__
# define __HTTPPARSER_H__

# include "IParser.h"
# include "Consumer.h"
# include "IRequest.h"

namespace	ziApi
{
  //! HttpParser
  class	HttpParser : public IParser
  {
  public:
    //! undef
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    //! \param parent a IParser pointer
    HttpParser(Consumer* consumer,
	       IRequest* request,
	       IParser* parent = NULL);

    //! first method called
    bool	run();
    //! read a CR character
    bool	readCR();
    //! read a LF character
    bool	readLF();
    //! read CRLF characters
    bool	readCRLF();
    //! read a char between a - z
    bool	readAlpha();
    //! read a char between 0 - 9
    bool	readDigit();
    //! read a char between 0 - 9 and a - f
    bool	readHexdig();
    //! read a space
    bool	readSP();
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
    //! read a cache extension
    bool	readCacheExtension();
    //! read a delta seconds
    bool	readDeltaSeconds();
    //! read a field name
    bool	readFieldName();
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
    //! read product
    bool	readProduct();
    //! read product - version
    bool	readProductVersion();
    //! read comment
    bool	readComment();
    //! read ctext
    bool	readCtext();
    //! read quoted string
    bool	readQuotedString();
    //! read quoted pair
    bool	readQuotedPair();
    //! read entity header
    bool	readEntityHeader();
  private:
    bool	_readRequestOptPart2();
    bool	_readCacheDirectiveSharp();
    bool	_readFieldNameSharp();
    bool	_readUserAgentPart2();
    bool	_readProductOpt();
    bool	_readCommentOpt();
  private:
    Consumer*	_consumer;
    IRequest*	_request;
    IParser*	_parent;
  };
};

#endif // !__HTTPPARSER_H__
