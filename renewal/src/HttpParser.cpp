//
// HttpParser.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 21:12:41 2008 caner candan
// Last update Thu Sep 25 14:29:57 2008 caner candan
//

#include <string>
#include "HttpParser.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"

HttpParser::HttpParser(Consumer& consumer, ZenZiAPI::IRequest& request)
  : _consumer(consumer), _request(request)
{}

bool	HttpParser::run()
{
  return (_readRequest());
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
       !_peekCTL() && !_peekSeparators();
       i++)
    _readChar();
  return (i > 0);
}

bool	HttpParser::_readRequest()
{
  return (_readRequestLine() &&
	  _readRequestOpt()); //&& CRLF);
}

bool	HttpParser::_readRequestOpt()
{
  while (_readRequestOptPart2());
  return (true);
}

bool	HttpParser::_readRequestOptPart2()
{
  _consumer.save();
  if ((_readGeneralHeader() ||
       _readRequestHeader() ||
       _readEntityHeader()) && CRLF)
    return (true);
  _consumer.back();
  return (false);
}

bool	HttpParser::_readRequestLine()
{
  return (_readMethod() && SP &&
	  _readRequestURI() && SP &&
	  _readHttpVersion() && CRLF);
}

bool	HttpParser::_readMethod()
{
  _consumer.prepare();
  if (TEXT_("OPTIONS") ||
      TEXT_("GET") ||
      TEXT_("HEAD") ||
      TEXT_("POST") ||
      TEXT_("PUT") ||
      TEXT_("DELETE") ||
      TEXT_("TRACE") ||
      TEXT_("CONNECT") ||
      _readExtensionMethod())
    {
      _request.setMethod(_consumer.extract());
      _consumer.consume();
      return (true);
    }
  return (false);
}

bool	HttpParser::_readExtensionMethod()
{
  return (_readToken());
}

bool		HttpParser::_readRequestURI()
{
  _consumer.prepare();
  while (!PCHAR(' '))
    RANGE(0, 127);
  _request.setUri(_consumer.extract());
  return (true);
}

bool	HttpParser::_readHttpVersion()
{
  _consumer.prepare();
  if (TEXT_("HTTP") &&
      CHAR('/') &&
      INTEGER &&
      CHAR('.') &&
      INTEGER)
    {
      _request.setHTTPVersion(_consumer.extract());
      return (true);
    }
  return (false);
}

bool	HttpParser::_readGeneralHeader()
{
  return (_readCacheControl() ||
	  _readConnection() ||
	  _readDate() ||
	  _readPragma() ||
	  _readTrailer() ||
	  _readTransferEncoding() ||
	  _readUpgrade() ||
	  _readVia() ||
	  _readWarning());
}

bool	HttpParser::_readCacheControl()
{
  NOT_IMPLEMENTED;
  //   return (TEXT_("Cache-Control") && CHAR(':') &&
  //    	  _readCacheDirective());
}

bool	HttpParser::_readCacheDirective()
{
  if (!_readCacheDirectiveSharp())
    return (false);
  SHARP(_readCacheDirectiveSharp());
  return (true);
}

bool	HttpParser::_readCacheDirectiveSharp()
{
  return (_readCacheRequestDirective() ||
	  _readCacheResponseDirective());
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
	   (CHAR('=') && CHAR('"') && _readFieldName() && CHAR('"'))) ||
	  (TEXT_("no-cache") &&
	   (CHAR('=') && CHAR('"') && _readFieldName() && CHAR('"'))) ||
	  TEXT_("no-store") ||
	  TEXT_("no-transform") ||
	  TEXT_("must-revalidate") ||
	  TEXT_("proxy-revalidate") ||
	  (TEXT_("max-age") && CHAR('=') && _readDeltaSeconds()) ||
	  (TEXT_("s-maxage") && CHAR('=') && _readDeltaSeconds()) ||
	  _readCacheExtension());
}

bool	HttpParser::_readCacheExtension()
{
  return (_readToken() &&
	  (_readToken() || // todo: backtracking
	   _readQuotedString()));
}

bool	HttpParser::_readDeltaSeconds()
{
  int	i;

  for (i = 0; DIGIT; i++);
  return (i > 0);
}

bool	HttpParser::_readFieldName()
{
  if (!_readFieldNameSharp())
    return (false);
  SHARP(_readFieldNameSharp());
  return (true);
}

bool	HttpParser::_readFieldNameSharp()
{
  return (_readToken());
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
  return (_readAccept() ||
	  _readAcceptCharset() ||
	  _readAcceptEncoding() ||
	  _readAcceptLanguage() ||
	  _readAuthorization() ||
	  _readExcept() ||
	  _readFrom() ||
	  _readHost() ||
	  _readIfMatch() ||
	  _readIfModifiedSince() ||
	  _readIfNoneMatch() ||
	  _readIfRange() ||
	  _readIfUnmodifiedSince() ||
	  _readMaxForwards() ||
	  _readProxyAuthorization() ||
	  _readRange() ||
	  _readReferer() ||
	  _readTE() ||
	  _readUserAgent());
}

bool	HttpParser::_readAccept()
{
  if (!(TEXT_("Accept") && CHAR(':')))
    return (false);

  while (SP);

  _consumer.prepare();

  while (!PCHAR('\r'))
    RANGE(0, 127);

  _request.setHeader("Accept", _consumer.extract());

  TEXT_("\r\n");

  //SHARP(_readAcceptSharp());
  return (true);
}

bool	HttpParser::_readAcceptSharp()
{
  _consumer.prepare();
  if (!_readMediaRange())
    return (false);
  _readAcceptParam();
  _request.setHeader("Accept", _consumer.extract());
  return (true);
}

bool	HttpParser::_readMediaRange()
{
  if (!(TEXT_("*/*") ||
	(_readType() && CHAR('/') && CHAR('*')) ||
	(_readType() && CHAR('/') && _readSubType())))
    return (false);
  while (CHAR(';') && _readParameter());
  return (true);
}

bool	HttpParser::_readAcceptParam()
{
  if (!(CHAR(';') && CHAR('q') && CHAR('=')
	&& _readQvalue()))
    return (false);
  while (_readAcceptExtension());
  return (true);
}

bool	HttpParser::_readAcceptExtension()
{
  if (!(CHAR(';') && _readToken()))
    return (false);
  (CHAR('=') &&
   (_readToken() || _readQuotedString()));
  return (true);
}

bool	HttpParser::_readType()
{
  return (_readToken());
}

bool	HttpParser::_readSubType()
{
  return (_readToken());
}

bool	HttpParser::_readParameter()
{
  return (_readAttribute() &&
	  CHAR('=') &&
	  _readValue());
}

bool	HttpParser::_readAttribute()
{
  return (_readToken());
}

bool	HttpParser::_readValue()
{
  return (_readToken() ||
	  _readQuotedString());
}

bool	HttpParser::_readQvalue()
{
  return (_readQvalueOpt1() ||
	  _readQvalueOpt2());
}

bool	HttpParser::_readQvalueOpt1()
{
  if (!CHAR('0'))
    return (false);
  (CHAR('.') && DIGIT && DIGIT && DIGIT);
  return (true);
}

bool	HttpParser::_readQvalueOpt2()
{
  if (!CHAR('1'))
    return (false);
  (CHAR('.') && CHAR('0') && CHAR('0') && CHAR('0'));
  return (true);
}

bool	HttpParser::_readAcceptCharset()
{
  if (!(TEXT_("Accept-Charset") && CHAR(':')))
    return (false);
  SHARP(_readAcceptCharsetSharp());
  return (true);
}

bool	HttpParser::_readAcceptCharsetSharp()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAcceptEncoding()
{
  if (!(TEXT_("Accept-Encoding") && CHAR(':')))
    return (false);
  SHARP(_readAcceptEncodingSharp());
  return (true);
}

bool	HttpParser::_readAcceptEncodingSharp()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAcceptLanguage()
{
  if (!(TEXT_("Accept-Language") && CHAR(':')))
    return (false);
  SHARP(_readAcceptLanguageSharp());
  return (true);
}

bool	HttpParser::_readAcceptLanguageSharp()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readAuthorization()
{
  return (TEXT_("Authorization") && CHAR(':') &&
	  _readCredentials());
}

bool	HttpParser::_readCredentials()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readExcept()
{
  if (!(TEXT_("Except") && CHAR(':')))
    return (false);
  SHARP(_readExpectation());
  return (true);
}

bool	HttpParser::_readExpectation()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readFrom()
{
  return (TEXT_("From") && CHAR(':') &&
	  _readMailbox());
}

bool	HttpParser::_readMailbox()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::_readHost()
{
  if (!(TEXT_("Host") && CHAR(':')))
    return (false);
  while (SP);
  _consumer.prepare();
  while (!PCHAR('\n'))
    RANGE(0, 127);

  FluxString	flux(_consumer.extract());
  Consumer	consumer(flux);
  URIParser	uri(consumer);

  uri.run();

  _request.setHeader("Host", "host", uri.getHost());
  _request.setHeader("Host", "port", uri.getPort());

  TEXT_("\r\n");

  return (true);
}

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

bool	HttpParser::_readRange()
{
  NOT_IMPLEMENTED;
}

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
  if (!(TEXT_("User-Agent") && CHAR(':')))
    return (false);
  //_readUserAgentPart2()

  while (SP);

  _consumer.prepare();

  while (!PCHAR('\r'))
    RANGE(0, 127);

  _request.setHeader("User-Agent", _consumer.extract());

  TEXT_("\r\n");

  return (true);
}

bool	HttpParser::_readUserAgentPart2()
{
  _consumer.prepare();

  int	i;

  for (i = 0; _readProduct() || _readComment(); i++);

  if (i > 0)
    {
      _request.setHeader("User-Agent", _consumer.extract());
      return (true);
    }
  return (false);
}

bool	HttpParser::_readProduct()
{
  return (_readToken() &&
	  _readProductOpt());
}

bool	HttpParser::_readComment()
{
  return (CHAR('(') &&
	  _readCommentOpt() &&
	  CHAR(')'));
}

bool	HttpParser::_readProductOpt()
{
  _consumer.save();
  if (CHAR('/') &&
      _readProductVersion())
    return (true);
  _consumer.back();
  return (false);
}

bool	HttpParser::_readProductVersion()
{
  return (_readToken());
}

bool	HttpParser::_readCommentOpt()
{
  while (_readCtext() ||
	 _readQuotedPair() ||
	 _readComment());
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
