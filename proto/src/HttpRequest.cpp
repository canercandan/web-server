//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:48:50 2008 morgan armand
// Last update Fri Aug  8 17:01:31 2008 caner candan
//

#include "HttpRequest.h"

// std::string&	HttpRequest::method()
// {
//   return (this->_method);
// }

// std::string&	HttpRequest::httpUrlHost()
// {
//   return (this->_httpUrl.host.host);
// }

// int&		HttpRequest::httpUrlPort()
// {
//   return (this->_httpUrl.host.port);
// }

// std::string&	HttpRequest::httpUrlAbs()
// {
//   return (this->_httpUrl.abs_path);
// }

// std::string&	HttpRequest::httpUrlQuery()
// {
//   return (this->_httpUrl.query);
// }

// std::string&	HttpRequest::versionProtocolName()
// {
//   return (this->_versionProtocol.name);
// }

// int&	HttpRequest::versionProtocolMajor()
// {
//   return (this->_versionProtocol.major);
// }

// int&	HttpRequest::versionProtocolMinor()
// {
//   return (this->_versionProtocol.minor);
// }

// std::string&	HttpRequest::versionProtocolOtherVersion()
// {
//   return (this->_versionProtocol.otherVersion);
// }

// std::string&	HttpRequest::cacheControlKey()
// {
//   this->_cacheControl.push_back(Key());
//   return (this->_cacheControl.back().key);
// }

// std::string&	HttpRequest::cacheControlValue()
// {
//   this->_cacheControl.back().value.push_back("");
//   return (this->_cacheControl.back().value.back());
// }

// std::string&	HttpRequest::connection()
// {
//   this->_connection.push_back("");
//   return (this->_connection.back());
// }

// std::string&	HttpRequest::date()
// {
//   return (this->_date);
// }

// std::string&	HttpRequest::pragmaKey()
// {
//   this->_pragma.push_back(Key());
//   return (this->_pragma.back().key);
// }

// std::string&	HttpRequest::pragmaValue()
// {
//   this->_pragma.back().value.push_back("");
//   return (this->_pragma.back().value.back());
// }

// std::string&	HttpRequest::trailer()
// {
//   this->_trailer.push_back("");
//   return (this->_trailer.back());
// }

// std::string&	HttpRequest::transferEncoding()
// {
//   this->_transferEncoding.push_back("");
//   return (this->_transferEncoding.back());
// }

// std::string&	HttpRequest::acceptCharset()
// {
//   this->_acceptCharset.push_back("");
//   return (this->_acceptCharset.back());
// }

// std::string&	HttpRequest::acceptEncoding()
// {
//   this->_acceptEncoding.push_back("");
//   return (this->_acceptEncoding.back());
// }

// std::string&	HttpRequest::acceptLanguage()
// {
//   this->_acceptLangage.push_back("");
//   return (this->_acceptLangage.back());
// }

// std::string&	HttpRequest::authorization()
// {
//   return (this->_authorization);
// }

// std::string&	HttpRequest::expectKey()
// {
//   this->_expect.push_back(Key());
//   return (this->_expect.back().key);
// }

// std::string&	HttpRequest::expectValue()
// {
//   this->_expect.back().value.push_back("");
//   return (this->_expect.back().value.back());
// }

// std::string&	HttpRequest::from()
// {
//   return (this->_from);
// }

// std::string&	HttpRequest::host()
// {
//   return (this->_host.host);
// }

// int&		HttpRequest::port()
// {
//   return (this->_host.port);
// }

// std::string&	HttpRequest::match()
// {
//   this->_ifMatch.push_back("");
//   return (this->_ifMatch.back());
// }

// std::string&	HttpRequest::allow()
// {
//   this->_allow.push_back("");
//   return (this->_allow.back());
// }

// std::string&	HttpRequest::contentEncoding()
// {
//   this->_contentEncoding.push_back("");
//   return (this->_contentEncoding.back());
// }

// std::string&	HttpRequest::contentLanguage()
// {
//   this->_contentLangage.push_back("");
//   return (this->_contentLangage.back());
// }

// int&		HttpRequest::contentLength()
// {
//   return (this->_contentLength);
// }

// std::string&	HttpRequest::contentLocation()
// {
//   return (this->_contentLocation);
// }

// std::string&	HttpRequest::contentMd5()
// {
//   return (this->_contentMd5);
// }

// std::string&	HttpRequest::contentRange()
// {
//   return (this->_contentRange);
// }

// std::string&	HttpRequest::expires()
// {
//   return (this->_expires);
// }

// std::string&	HttpRequest::lastModifies()
// {
//   return (this->_lastModified);
// }


void	HttpRequest::setMethod(const std::string& method)
{
  this->_method = method;
}

void	HttpRequest::setHttpUrl(const std::string& host, int port, const std::string& abs, std::string query)
{
  this->_httpUrl.host.host = host;
  this->_httpUrl.host.port = port;
  this->_httpUrl.abs_path = abs;
  this->_httpUrl.query = query;
}

void	HttpRequest::setVersionProtocol(const std::string name, int major, int minor, const std::string otherVersion)
{
  this->_versionProtocol.name = name;
  this->_versionProtocol.major = major;
  this->_versionProtocol.minor = minor;
  this->_versionProtocol.otherVersion = otherVersion;
}

void	HttpRequest::addCacheControl(const std::string& key, const std::string& value)
{
  Key	myKey;
  myKey.key = key;
  myKey.value.push_back(value);
  this->_cacheControl.push_back(myKey);
}

void	HttpRequest::addConnection(const std::string& connection)
{
  this->_connection.push_back(connection);
}

void	HttpRequest::setDate(const std::string& date)
{
  this->_date = date;
}

void	HttpRequest::addPragma(const std::string& key, const std::string& value)
{
  Key	myKey;
  myKey.key = key;
  myKey.value.push_back(value);
  this->_pragma.push_back(myKey);
}

void	HttpRequest::addTrailer(const std::string& trailer)
{
  this->_trailer.push_back(trailer);
}

void	HttpRequest::addTransferEncoding(const std::string& encoding)
{
  this->_transferEncoding.push_back(encoding);
}

void	HttpRequest::addUpgrade(const VersionProtocol& versionProtocol)
{
  this->_upgrade.push_back(versionProtocol);
}

void	HttpRequest::addWarning(const Warning& warning)
{
  this->_warning.push_back(warning);
}

void	HttpRequest::addAccept(const Type& type)
{
  this->_accept.push_back(type);
}

void	HttpRequest::addAcceptCharset(const std::string& charset)
{
  this->_acceptCharset.push_back(charset);
}

void	HttpRequest::addAcceptEncoding(const std::string& encoding)
{
  this->_acceptEncoding.push_back(encoding);
}

void	HttpRequest::addAcceptLangage(const std::string& lang)
{
  this->_acceptLangage.push_back(lang);
}

void	HttpRequest::setAuthorization(const std::string& digest)
{
  this->_authorization = digest;
}

void	HttpRequest::addExpect(const std::string& key, const std::string& value)
{
  Key	myKey;
  myKey.key = key;
  myKey.value.push_back(value);
  this->_expect.push_back(myKey);
}

void	HttpRequest::setFrom(const std::string& from)
{
  this->_from = from;
}

void	HttpRequest::setHost(const std::string& host, int port)
{
  this->_host.host = host;
  this->_host.port = port;
}

void	HttpRequest::addIfMatch(const std::string& match)
{
  this->_ifMatch.push_back(match);
}

void	HttpRequest::addAllow(const std::string& allow)
{
  this->_allow.push_back(allow);
}

void	HttpRequest::addContentEncoding(const std::string& encoding)
{
  this->_contentEncoding.push_back(encoding);
}

void	HttpRequest::addContentLangage(const std::string& lang)
{
  this->_contentLangage.push_back(lang);
}

void	HttpRequest::setContentLength(const int length)
{
  this->_contentLength = length;
}

void	HttpRequest::setContentLocation(const std::string& location)
{
  this->_contentLocation = location;
}

void	HttpRequest::setContentMd5(const std::string& base64ToMd5)
{
  this->_contentMd5 = base64ToMd5;
}

void	HttpRequest::setContentRange(const std::string& range)
{
  this->_contentRange = range;
}

void	HttpRequest::addContentType(const Type& type)
{
  this->_contentType.push_back(type);
}

void	HttpRequest::setExpires(const std::string& expires)
{
  this->_expires = expires;
}

void	HttpRequest::setLastModifies(const std::string& lastModified)
{
  this->_lastModified = lastModified;
}
