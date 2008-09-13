//
// HttpParser.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 21:12:41 2008 caner candan
// Last update Sat Sep 13 22:17:32 2008 caner candan
//

#include <string>
#include "HttpParser.h"
#include "URIParser.h"

HttpParser::HttpParser(Consumer& consumer, ZenZiAPI::IRequest& request)
  : _consumer(consumer), _request(request)
{}

bool	HttpParser::run()
{
  return (this->_readRequest());
}

bool	HttpParser::_readChar()
{
  return (RANGE(0, 127));
}

bool	HttpParser::_peekCTL()
{
  return (PRANGE(0, 31) ||
	  PCHAR(127));
}

bool	HttpParser::_peekSeparators()
{
  return (PCHAR('(') || PCHAR(')') || PCHAR('<') ||
	  PCHAR('>') || PCHAR('@') || PCHAR(',') ||
	  PCHAR(';') || PCHAR(':') || PCHAR('\\') ||
	  PCHAR('"') || PCHAR('/') || PCHAR('[') ||
	  PCHAR(']') || PCHAR('?') || PCHAR('=') ||
	  PCHAR('{') || PCHAR('}') || PCHAR(' ') ||
	  PCHAR('\t'));
}

bool	HttpParser::_readToken()
{
  int	i;

  for (i = 0;
       !this->_peekCTL() && !this->_peekSeparators();
       i++)
    this->_readChar();
  return (i > 0);
}

bool	HttpParser::_readRequest()
{
  return (this->_readRequestLine() &&
	  this->_readRequestOpt()); //&& CRLF);
}

bool	HttpParser::_readRequestOpt()
{
  while (this->_readRequestOptPart2());
  return (true);
}

bool	HttpParser::_readRequestOptPart2()
{
  this->_consumer.save();
  if ((this->_readGeneralHeader() ||
       this->_readRequestHeader() ||
       this->_readEntityHeader()) && CRLF)
    return (true);
  this->_consumer.back();
  return (false);
}

bool	HttpParser::_readRequestLine()
{
  return (this->_readMethod() && SP &&
	  this->_readRequestURI() && SP &&
	  this->_readHttpVersion() && CRLF);
}

bool	HttpParser::_readMethod()
{
  this->_consumer.prepare();
  if (TEXT_("OPTIONS") ||
      TEXT_("GET") ||
      TEXT_("HEAD") ||
      TEXT_("POST") ||
      TEXT_("PUT") ||
      TEXT_("DELETE") ||
      TEXT_("TRACE") ||
      TEXT_("CONNECT") ||
      this->_readExtensionMethod())
    {
      this->_request.setMethod(this->_consumer.extract());
      this->_consumer.consume();
      return (true);
    }
  return (false);
}

bool	HttpParser::_readExtensionMethod()
{
  return (this->_readToken());
}

bool		HttpParser::_readRequestURI()
{
  this->_consumer.prepare();
  while (!PCHAR(' '))
    RANGE(0, 127);
  this->_request.setUri(this->_consumer.extract());
  return (true);
}

bool	HttpParser::_readHttpVersion()
{
  this->_consumer.prepare();
  if (TEXT_("HTTP") &&
      CHAR('/') &&
      INTEGER &&
      CHAR('.') &&
      INTEGER)
    {
      this->_request.setHTTPVersion(this->_consumer.extract());
      return (true);
    }
  return (false);
}

bool	HttpParser::_readGeneralHeader()
{
  return (this->_readCacheControl() ||
	  this->_readConnection() ||
	  this->_readDate() ||
	  this->_readPragma() ||
	  this->_readTrailer() ||
	  this->_readTransferEncoding() ||
	  this->_readUpgrade() ||
	  this->_readVia() ||
	  this->_readWarning());
}

bool	HttpParser::_readCacheControl()
{
  NOT_IMPLEMENTED;
  //   return (TEXT_("Cache-Control") && CHAR(':') &&
  //    	  this->_readCacheDirective());
}

bool	HttpParser::_readCacheDirective()
{
  if (!this->_readCacheDirectiveSharp())
    return (false);
  SHARP(this->_readCacheDirectiveSharp());
  return (true);
}

bool	HttpParser::_readCacheDirectiveSharp()
{
  return (this->_readCacheRequestDirective() ||
	  this->_readCacheResponseDirective());
}

bool	HttpParser::_readCacheRequestDirective()
{
  return (TEXT_("no-cache") ||
	  TEXT_("no-store") ||
	  (TEXT_("max-age") && CHAR('=') && _readDeltaSeconds()) ||
	  (TEXT_("max-stale") && (CHAR('=') && _readDeltaSeconds())) || // todo: backtracking
	  (TEXT_("min-fresh") && CHAR('=') && _readDeltaSeconds()) ||
	  TEXT_("no-transform") ||
	  TEXT_("only-if-cached") ||
	  _readCacheExtension());
}

bool	HttpParser::_readCacheResponseDirective()
{
  return (TEXT_("public") ||
	  (TEXT_("private") &&
	   (CHAR('=') && CHAR('"') && this->_readFieldName() && CHAR('"'))) ||
	  (TEXT_("no-cache") &&
	   (CHAR('=') && CHAR('"') && this->_readFieldName() && CHAR('"'))) ||
	  TEXT_("no-store") ||
	  TEXT_("no-transform") ||
	  TEXT_("must-revalidate") ||
	  TEXT_("proxy-revalidate") ||
	  (TEXT_("max-age") && CHAR('=') && this->_readDeltaSeconds()) ||
	  (TEXT_("s-maxage") && CHAR('=') && this->_readDeltaSeconds()) ||
	  this->_readCacheExtension());
}

bool	HttpParser::_readCacheExtension()
{
  return (this->_readToken() &&
	  (this->_readToken() || // todo: backtracking
	   this->_readQuotedString()));
}

bool	HttpParser::_readDeltaSeconds()
{
  int	i;

  for (i = 0; DIGIT; i++);
  return (i > 0);
}

bool	HttpParser::_readFieldName()
{
  if (!this->_readFieldNameSharp())
    return (false);
  SHARP(this->_readFieldNameSharp());
  return (true);
}

bool	HttpParser::_readFieldNameSharp()
{
  return (this->_readToken());
}

bool	HttpParser::_readConnection()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readDate()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readPragma()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readTrailer()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readTransferEncoding()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readUpgrade()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readVia()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readWarning()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readRequestHeader()
{
  return (this->_readAccept() ||
	  this->_readAcceptCharset() ||
	  this->_readAcceptEncoding() ||
	  this->_readAcceptLanguage() ||
	  this->_readAuthorization() ||
	  this->_readExcept() ||
	  this->_readFrom() ||
	  //	  this->_readHost() ||
	  this->_readIfMatch() ||
	  this->_readIfModifiedSince() ||
	  this->_readIfNoneMatch() ||
	  this->_readIfRange() ||
	  this->_readIfUnmodifiedSince() ||
	  this->_readMaxForwards() ||
	  this->_readProxyAuthorization() ||
	  //	  this->_readRange() ||
	  this->_readReferer() ||
	  this->_readTE() ||
	  this->_readUserAgent());
}

bool	HttpParser::_readAccept()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAcceptCharset()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAcceptEncoding()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAcceptLanguage()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAuthorization()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readExcept()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readFrom()
{
  NOT_IMPLEMENTED;
}

// bool	HttpParser::_readHost()
// {
//   NOT_IMPLEMENTED;
// }

bool	HttpParser::_readIfMatch()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readIfModifiedSince()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readIfNoneMatch()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readIfRange()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readIfUnmodifiedSince()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readMaxForwards()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readProxyAuthorization()
{
  NOT_IMPLEMENTED;
}

// bool	HttpParser::_readRange()
// {
//   NOT_IMPLEMENTED;
// }

bool	HttpParser::_readReferer()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readTE()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readUserAgent()
{
  return (TEXT_("User-Agent") && CHAR(':') &&
	  this->_readUserAgentPart2());
}

bool	HttpParser::_readUserAgentPart2()
{
  int	i;

  for (i = 0;
       this->_readProduct() || this->_readComment();
       i++);
  return (i > 0);
}

bool	HttpParser::_readProduct()
{
  return (this->_readToken() &&
	  this->_readProductOpt());
}

bool	HttpParser::_readComment()
{
  return (CHAR('(') &&
	  this->_readCommentOpt() &&
	  CHAR(')'));
}

bool	HttpParser::_readProductOpt()
{
  this->_consumer.save();
  if (CHAR('/') &&
      this->_readProductVersion())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	HttpParser::_readProductVersion()
{
  return (this->_readToken());
}

bool	HttpParser::_readCommentOpt()
{
  while (this->_readCtext() ||
	 this->_readQuotedPair() ||
	 this->_readComment());
  return (true);
}

bool	HttpParser::_readCtext()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readQuotedString()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readQuotedPair()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readEntityHeader()
{
  NOT_IMPLEMENTED;
}
