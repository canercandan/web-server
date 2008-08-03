//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:48:50 2008 morgan armand
// Last update Sat Aug  2 23:47:03 2008 florent hochwelker
//

#include "HttpRequest.h"

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
