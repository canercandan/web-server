//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:54 2008 morgan armand
// Last update Mon Aug 11 20:59:21 2008 morgan armand
//

#include "HttpParser.h"

HttpParser::HttpParser(HttpProducer* prod, HttpRequest* request)
  : URIParser(prod, request)
{
}

HttpParser::~HttpParser()
{
}

bool	HttpParser::readRequest()
{
  return (this->readRequestLine() &&
	  this->readRequestOpt() && CRLF);
}

bool	HttpParser::readRequestOpt()
{
  while (this->readRequestHeader());
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
  NOT_IMPLEMENTED;
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
      this->_request->setHttpMajorVersion(major);
      this->_request->setHttpMinorVersion(minor);
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
  NOT_IMPLEMENTED;
  //   return (TEXT("Cache-Control") && CHAR(':') &&
  // 	  this->readCacheDirective() &&
  // 	  this->readCacheDirectiveOpt());
}

// bool	HttpParser::readCacheDirective()
// {
//   NOT_IMPLEMENTED;
// }

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
	  this->readHost() ||
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
  NOT_IMPLEMENTED;
}

bool	HttpParser::readEntityHeader()
{
  NOT_IMPLEMENTED;
}
