#include "HttpParser.h"

using namespace ziApi;

HttpParser::HttpParser(const Consumer& consumer,
		       const IRequest& request)
  : Parser(consumer, request)
{}

bool	HttpParser::readChar()
{
  return (this->readRange(0, 127));
}

bool	HttpParser::peekCTL()
{
  return (this->peekRange(0, 31) ||
	  this->peekChar(127));
}

bool	HttpParser::peekSeparators()
{
  return (this->peekChar('(') || this->peekChar(')') ||
	  this->peekChar('<') || this->peekChar('>') ||
	  this->peekChar('@') || this->peekChar(',') ||
	  this->peekChar(';') || this->peekChar(':') ||
	  this->peekChar('\\') || this->peekChar('"') ||
	  this->peekChar('/') || this->peekChar('[') ||
	  this->peekChar(']') || this->peekChar('?') ||
	  this->peekChar('=') || this->peekChar('{') ||
	  this->peekChar('}') || this->peekChar(' ') ||
	  this->peekChar('\t'));
}

bool	HttpParser::readToken()
{
  int	i;

  i = 0;
  while (!this->peekCTL() &&
	 !this->peekSeparators())
    {
      this->readCHAR();
      i++;
    }
  return (i > 0);
}

bool	HttpParser::readRequest()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readRequestLine() &&
		this->readRequestOpt()); //&& CRLF);
}

bool	HttpParser::readRequestOpt()
{
  DEBUG_ENTER;
  while (this->readRequestOptPart2());
  DEBUG_RETURN (true);
}

bool	HttpParser::readRequestOptPart2()
{
  DEBUG_ENTER;
  this->save();
  if ((this->readGeneralHeader() ||
       this->readRequestHeader() ||
       this->readEntityHeader()) && CRLF)
    DEBUG_RETURN (true);
  this->back();
  DEBUG_RETURN (false);
}

bool	HttpParser::readRequestLine()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readMethod() && SP &&
	  this->readRequestURI() && SP &&
	  this->readHttpVersion() && CRLF);
}

bool	HttpParser::readMethod()
{
  DEBUG_ENTER;
  this->prepare();
  if (TEXT_("OPTIONS") ||
      TEXT_("GET") ||
      TEXT_("HEAD") ||
      TEXT_("POST") ||
      TEXT_("PUT") ||
      TEXT_("DELETE") ||
      TEXT_("TRACE") ||
      TEXT_("CONNECT") ||
      this->readExtensionMethod())
    {
      this->_request->setMethod(this->extract());
      this->consume();
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	HttpParser::readExtensionMethod()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readToken());
}

bool	HttpParser::readRequestURI()
{
  DEBUG_ENTER;
  if (CHAR('*') ||
      this->readAbsoluteURI() ||
      (this->readPathAbsolute() &&
       this->readPathAbsoluteQuery()) ||
      this->readAuthority())
    DEBUG_RETURN (true);
  DEBUG_RETURN (false);
}

bool	HttpParser::readPathAbsoluteQuery()
{
  DEBUG_ENTER;

  
  if (CHAR('?'))
    this->readQuery();

  DEBUG_RETURN (true);
}

bool	HttpParser::readHttpVersion()
{
  std::string	name;
  int		major;
  int		minor;

  DEBUG_ENTER;
  if (TEXT_R("HTTP", name) &&
      CHAR('/') &&
      INTEGER_R(major) &&
      CHAR('.') &&
      INTEGER_R(minor))
    {
      this->_request->getVersionProtocol().setName(name);
      this->_request->getVersionProtocol().setMajor(major);
      this->_request->getVersionProtocol().setMinor(minor);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	HttpParser::readGeneralHeader()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readCacheControl() ||
	  this->readConnection() ||
	  this->readDate() ||
	  this->readPragma() ||
	  this->readTrailer() ||
	  this->readTransferEncoding() ||
	  this->readUpgrade() ||
	  this->readVia() ||
	  this->readWarning());
}

bool	HttpParser::readCacheControl()
{
  NOT_IMPLEMENTED;
  //   return (TEXT_("Cache-Control") && CHAR(':') &&
  //    	  this->readCacheDirective());
}

bool	HttpParser::readCacheDirective()
{
  DEBUG_ENTER;
  if (!this->readCacheDirectiveSharp())
    DEBUG_RETURN (false);
  SHARP(this->readCacheDirectiveSharp());
  DEBUG_RETURN (true);
}

bool	HttpParser::readCacheDirectiveSharp()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readCacheRequestDirective() ||
	  this->readCacheResponseDirective());
}

bool	HttpParser::readCacheRequestDirective()
{
  DEBUG_ENTER;
  DEBUG_RETURN (TEXT_("no-cache") ||
	  TEXT_("no-store") ||
	  (TEXT_("max-age") && CHAR('=') && readDeltaSeconds()) ||
	  (TEXT_("max-stale") && (CHAR('=') && readDeltaSeconds())) || // todo: backtracking
	  (TEXT_("min-fresh") && CHAR('=') && readDeltaSeconds()) ||
	  TEXT_("no-transform") ||
	  TEXT_("only-if-cached") ||
	  readCacheExtension());
}

bool	HttpParser::readCacheResponseDirective()
{
  DEBUG_ENTER;
  DEBUG_RETURN (TEXT_("public") ||
	  (TEXT_("private") &&
	   (CHAR('=') && CHAR('"') && this->readFieldName() && CHAR('"'))) ||
	  (TEXT_("no-cache") &&
	   (CHAR('=') && CHAR('"') && this->readFieldName() && CHAR('"'))) ||
	  TEXT_("no-store") ||
	  TEXT_("no-transform") ||
	  TEXT_("must-revalidate") ||
	  TEXT_("proxy-revalidate") ||
	  (TEXT_("max-age") && CHAR('=') && this->readDeltaSeconds()) ||
	  (TEXT_("s-maxage") && CHAR('=') && this->readDeltaSeconds()) ||
	  this->readCacheExtension());
}

bool	HttpParser::readCacheExtension()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readToken() &&
	  (this->readToken() || // todo: backtracking
	   this->readQuotedString()));
}

bool	HttpParser::readDeltaSeconds()
{
  int	i;

  DEBUG_ENTER;
  for (i = 0; DIGIT; i++);
  DEBUG_RETURN (i > 0);
}

bool	HttpParser::readFieldName()
{
  DEBUG_ENTER;
  if (!this->readFieldNameSharp())
    DEBUG_RETURN (false);
  SHARP(this->readFieldNameSharp());
  DEBUG_RETURN (true);
}

bool	HttpParser::readFieldNameSharp()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readToken());
}

bool	HttpParser::readConnection()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readDate()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readPragma()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readTrailer()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readTransferEncoding()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readUpgrade()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readVia()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readWarning()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readRequestHeader()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readAccept() ||
	  this->readAcceptCharset() ||
	  this->readAcceptEncoding() ||
	  this->readAcceptLanguage() ||
	  this->readAuthorization() ||
	  this->readExpect() ||
	  this->readFrom() ||
	  //	  this->readHost() ||
	  this->readIfMatch() ||
	  this->readIfModifiedSince() ||
	  this->readIfNoneMatch() ||
	  this->readIfRange() ||
	  this->readIfUnmodifiedSince() ||
	  this->readMaxForwards() ||
	  this->readProxyAuthorization() ||
	  //	  this->readRange() ||
	  this->readReferer() ||
	  this->readTE() ||
	  this->readUserAgent());
}

bool	HttpParser::readAccept()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readAcceptCharset()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readAcceptEncoding()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readAcceptLanguage()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readAuthorization()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readExpect()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readFrom()
{
  NOT_IMPLEMENTED;
}

// bool	HttpParser::readHost()
// {
//   NOT_IMPLEMENTED;
// }

bool	HttpParser::readIfMatch()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readIfModifiedSince()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readIfNoneMatch()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readIfRange()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readIfUnmodifiedSince()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readMaxForwards()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readProxyAuthorization()
{
  NOT_IMPLEMENTED;
}

// bool	HttpParser::readRange()
// {
//   NOT_IMPLEMENTED;
// }

bool	HttpParser::readReferer()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readTE()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readUserAgent()
{
  DEBUG_ENTER;
  DEBUG_RETURN (TEXT_("User-Agent") && CHAR(':') &&
	  this->readUserAgentPart2());
}

bool	HttpParser::readUserAgentPart2()
{
  int	i;

  DEBUG_ENTER;
  i = 0;
  while (this->readProduct() ||
	 this->readComment())
    i++;

  DEBUG_RETURN (i > 0);
}

bool	HttpParser::readProduct()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readToken() &&
	  this->readProductOpt());
}

bool	HttpParser::readComment()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readChar('(') &&
	  this->readCommentOpt() &&
	  this->readChar(')'));
}

bool	HttpParser::readProductOpt()
{
  DEBUG_ENTER;
  this->save();

  if (this->readChar('/') &&
      this->readProductVersion())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (false);
}

bool	HttpParser::readProductVersion()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readToken());
}

bool	HttpParser::readCommentOpt()
{
  DEBUG_ENTER;
  while (this->readCtext() ||
	 this->readQuotedPair() ||
	 this->readComment());
  DEBUG_RETURN (true);
}

bool	HttpParser::readCtext()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readQuotedString()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readQuotedPair()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readEntityHeader()
{
  NOT_IMPLEMENTED;
}
