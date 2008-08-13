//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:54 2008 morgan armand
// Last update Wed Aug 13 13:28:50 2008 caner candan
//

#include "HttpParser.h"

HttpParser::HttpParser(HttpProducer* prod, HttpRequest* request)
  : URIParser(prod, request)
{
}

HttpParser::~HttpParser()
{
}

bool	HttpParser::readCHAR()
{
  return (this->readRange(0, 127));
}

bool	HttpParser::peekCTL()
{
  return (this->peekRange(0, 31) ||
	  this->peekChar(127));
}

bool	HttpParser::readCTL()
{
  return (this->readRange(0, 31) ||
	  this->readChar(127));
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

bool	HttpParser::readSeparators()
{
  return (this->readChar('(') || this->readChar(')') ||
	  this->readChar('<') || this->readChar('>') ||
	  this->readChar('@') || this->readChar(',') ||
	  this->readChar(';') || this->readChar(':') ||
	  this->readChar('\\') || this->readChar('"') ||
	  this->readChar('/') || this->readChar('[') ||
	  this->readChar(']') || this->readChar('?') ||
	  this->readChar('=') || this->readChar('{') ||
	  this->readChar('}') || this->readChar(' ') ||
	  this->readChar('\t'));
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
  return (this->readRequestLine() &&
	  this->readRequestOpt());// && CRLF);
}

bool	HttpParser::readRequestOpt()
{
  while (this->readRequestOptPart2());
  return (true);
}

bool	HttpParser::readRequestOptPart2()
{
  this->save();
  if ((this->readGeneralHeader() ||
       this->readRequestHeader() ||
       this->readEntityHeader()) && CRLF)
    return (true);
  this->back();
  return (false);
}

bool	HttpParser::readRequestLine()
{
  return (this->readMethod() && SP &&
	  this->readRequestURI() && SP &&
	  this->readHttpVersion() && CRLF);
}

bool	HttpParser::readMethod()
{
  this->prepare();
  if (TEXT("OPTIONS") ||
      TEXT("GET") ||
      TEXT("HEAD") ||
      TEXT("POST") ||
      TEXT("PUT") ||
      TEXT("DELETE") ||
      TEXT("TRACE") ||
      TEXT("CONNECT") ||
      this->readExtensionMethod())
    {
      this->_request->setMethod(this->extract());
      this->consume();
      return (true);
    }
  return (false);
}

bool	HttpParser::readExtensionMethod()
{
  return (this->readToken());
}

bool	HttpParser::readRequestURI()
{
  if (CHAR('*') ||
      this->readAbsoluteURI() ||
      this->readPathAbsolute() ||
      this->readAuthority())
    return (true);
  return (false);
}

bool	HttpParser::readHttpVersion()
{
  std::string	name;
  int		major;
  int		minor;

  if (TEXT_R("HTTP", name) &&
      CHAR('/') &&
      INTEGER_R(major) &&
      CHAR('.') &&
      INTEGER_R(minor))
    {
      this->_request->getVersionProtocol().setName(name);
      this->_request->getVersionProtocol().setMajor(major);
      this->_request->getVersionProtocol().setMinor(minor);
      return (true);
    }
  return (false);
}

bool	HttpParser::readGeneralHeader()
{
  return (this->readCacheControl() ||
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
  return (TEXT("Cache-Control") && CHAR(':') &&
   	  this->readCacheDirective());
}

bool	HttpParser::readCacheDirective()
{
  if (!this->readCacheDirectiveSharp())
    return (false);
  SHARP(this->readCacheDirectiveSharp());
  return (true);
}

bool	HttpParser::readCacheDirectiveSharp()
{
  return (this->readCacheRequestDirective() ||
	  this->readCacheResponseDirective());
}

bool	HttpParser::readCacheRequestDirective()
{
  return (TEXT("no-cache") ||
	  TEXT("no-store") ||
	  (TEXT("max-age") && CHAR('=') && readDeltaSeconds()) ||
	  (TEXT("max-stale") && (CHAR('=') && readDeltaSeconds())) || // todo: backtracking
	  (TEXT("min-fresh") && CHAR('=') && readDeltaSeconds()) ||
	  TEXT("no-transform") ||
	  TEXT("only-if-cached") ||
	  readCacheExtension());
}

bool	HttpParser::readCacheResponseDirective()
{
  return (TEXT("public") ||
	  (TEXT("private") &&
	   (CHAR('=') && CHAR('"') && readFieldName() && CHAR('"'))) ||
	  (TEXT("no-cache") &&
	   (CHAR('=') && CHAR('"') && readFieldName() && CHAR('"'))) ||
	  TEXT("no-store") ||
	  TEXT("no-transform") ||
	  TEXT("must-revalidate") ||
	  TEXT("proxy-revalidate") ||
	  (TEXT("max-age") && CHAR('=') && readDeltaSeconds()) ||
	  (TEXT("s-maxage") && CHAR('=') && readDeltaSeconds()) ||
	  readCacheExtension()); 
}

bool	HttpParser::readCacheExtension()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readDeltaSeconds()
{
  NOT_IMPLEMENTED;
}

bool	HttpParser::readFieldName()
{
  NOT_IMPLEMENTED;
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
  return (this->readAccept() ||
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
  return (TEXT("User-Agent") && CHAR(':') &&
	  this->readUserAgentPart2());
}

bool	HttpParser::readUserAgentPart2()
{
  int	i;

  i = 0;
  while (this->readProduct() ||
	 this->readComment())
    i++;

  return (i > 0);
}

bool	HttpParser::readProduct()
{
  return (this->readToken() &&
	  this->readProductOpt());
}

bool	HttpParser::readComment()
{
  return (this->readChar('(') &&
	  this->readCommentOpt() &&
	  this->readChar(')'));
}

bool	HttpParser::readProductOpt()
{
  this->save();

  if (this->readChar('/') &&
      this->readProductVersion())
    return (true);

  this->back();
  return (false);
}

bool	HttpParser::readProductVersion()
{
  return (this->readToken());
}

bool	HttpParser::readCommentOpt()
{
  while (this->readCtext() ||
	 this->readQuotedPair() ||
	 this->readComment());
  return (true);
}

bool	HttpParser::readCtext()
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
