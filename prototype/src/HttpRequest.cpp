//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:24 2008 morgan armand
// Last update Wed Aug 13 17:41:56 2008 caner candan
//

#include <sstream>
#include "HttpRequest.h"

HttpRequest::HttpRequest()
{
  _httpUrl.getHost().setPort(80);
}

const std::string&	HttpRequest::VersionProtocol::getName() const
{
  return (this->_name);
}

const int&	HttpRequest::VersionProtocol::getMajor() const
{
  return (this->_major);
}

const int&	HttpRequest::VersionProtocol::getMinor() const
{
  return (this->_minor);
}

const std::string&	HttpRequest::VersionProtocol::getOtherVersion() const
{
  return (this->_otherVersion);
}

void	HttpRequest::VersionProtocol::setName(const std::string& name)
{
  this->_name = name;
}

void	HttpRequest::VersionProtocol::setMajor(const int& major)
{
  this->_major = major;
}

void	HttpRequest::VersionProtocol::setMinor(const int& minor)
{
  this->_minor = minor;
}

void	HttpRequest::VersionProtocol::setOtherVersion(const std::string& otherVersion)
{
  this->_otherVersion = otherVersion;
}

const std::string&	HttpRequest::Host::getHostname() const
{
  return (this->_hostname);
}

const int&	HttpRequest::Host::getPort() const
{
  return (this->_port);
}

void	HttpRequest::Host::setHostname(const std::string& hostname)
{
  this->_hostname = hostname;
}

void	HttpRequest::Host::setPort(const int& port)
{
  this->_port = port;
}

HttpRequest::Host&	HttpRequest::HttpUrl::getHost()
{
  return (this->_host);
}

const std::string&	HttpRequest::HttpUrl::getAbsPath() const
{
  return (this->_absPath);
}

const std::string&	HttpRequest::HttpUrl::getQuery() const
{
  return (this->_query);
}

void	HttpRequest::HttpUrl::setAbsPath(const std::string& absPath)
{
  this->_absPath = absPath;
}

void	HttpRequest::HttpUrl::setQuery(const std::string& query)
{
  this->_query = query;
}

const std::string&	HttpRequest::Type::getMajor() const
{
  return (this->_major);
}

const std::string&	HttpRequest::Type::getMinor() const
{
  return (this->_minor);
}

const HttpRequest::mapKey&	HttpRequest::Type::getParam() const
{
  return (this->_param);
}

const HttpRequest::listString&	HttpRequest::Type::getParam(const std::string& key)
{
  return (this->_param[key]);
}

const std::string&	HttpRequest::Type::getParam(const std::string& key,
						    const int& pos)
{
  listString::const_iterator	it;
  listString::const_iterator	end = this->_param[key].end();
  int				i;

  i = 0;
  for (it = this->_param[key].begin(); it != end; ++it)
    if (i == pos)
      return (*it);
  return (*it);
}

void	HttpRequest::Type::setMajor(const std::string& major)
{
  this->_major = major;
}

void	HttpRequest::Type::setMinor(const std::string& minor)
{
  this->_minor = minor;
}

void	HttpRequest::Type::addParam(const std::string& key,
				    const std::string& value)
{
  this->_param[key].push_back(value);
}

const std::string&	HttpRequest::Warning::getCode() const
{
  return (this->_code);
}

const std::string&	HttpRequest::Warning::getAgent() const
{
  return (this->_agent);
}

const std::string&	HttpRequest::Warning::getText() const
{
  return (this->_text);
}

const std::string&	HttpRequest::Warning::getDate() const
{
  return (this->_date);
}

void	HttpRequest::Warning::setCode(const std::string& code)
{
  this->_code = code;
}

void	HttpRequest::Warning::setAgent(const std::string& agent)
{
  this->_agent = agent;
}

void	HttpRequest::Warning::setText(const std::string& text)
{
  this->_text = text;
}

void	HttpRequest::Warning::setDate(const std::string& date)
{
  this->_date = date;
}

const std::string&	HttpRequest::getMethod() const
{
  return (this->_method);
}

HttpRequest::HttpUrl&	HttpRequest::getHttpUrl()
{
  return (this->_httpUrl);
}

HttpRequest::VersionProtocol&	HttpRequest::getVersionProtocol()
{
  return (this->_versionProtocol);
}

const std::string&	HttpRequest::getPath() const
{
  return (this->_path);
}

const HttpRequest::mapKey&	HttpRequest::getCacheControl() const
{
  return (this->_cacheControl);
}

const HttpRequest::listString&	HttpRequest::getConnection() const
{
  return (this->_connection);
}

const std::string&	HttpRequest::getDate() const
{
  return (this->_date);
}

const HttpRequest::mapKey&	HttpRequest::getPragma() const
{
  return (this->_pragma);
}

const HttpRequest::listString&	HttpRequest::getTrailer() const
{
  return (this->_trailer);
}

const HttpRequest::listString&	HttpRequest::getTransferEncoding() const
{
  return (this->_transferEncoding);
}

const HttpRequest::listVP&	HttpRequest::getUpgrade() const
{
  return (this->_upgrade);
}

const HttpRequest::listWarning& HttpRequest::getWarning() const
{
  return (this->_warning);
}

const HttpRequest::listType&	HttpRequest::getAccept() const
{
  return (this->_accept);
}

const HttpRequest::listString&	HttpRequest::getAcceptCharset() const
{
  return (this->_acceptCharset);
}

const HttpRequest::listString&	HttpRequest::getAcceptEncoding() const
{
  return (this->_acceptEncoding);
}

const HttpRequest::listString&	HttpRequest::getAcceptLangage() const
{
  return (this->_acceptLangage);
}

const std::string&	HttpRequest::getAuthorization() const
{
  return (this->_authorization);
}

const HttpRequest::mapKey&	HttpRequest::getExcept() const
{
  return (this->_expect);
}

const std::string	HttpRequest::getFrom() const
{
  return (this->_from);
}

const HttpRequest::Host&	HttpRequest::getHost() const
{
  return (this->_host);
}

const HttpRequest::listString&	HttpRequest::getIfMatch()
{
  return (this->_ifMatch);
}

const HttpRequest::listString&	HttpRequest::getAllow() const
{
  return (this->_allow);
}

const HttpRequest::listString&	HttpRequest::getContentEncoding() const
{
  return (this->_contentEncoding);
}

const HttpRequest::listString&	HttpRequest::getContentLangage() const
{
  return (this->_contentLangage);
}

const int&	HttpRequest::getContentLength() const
{
  return (this->_contentLength);
}

const std::string&	HttpRequest::getContentLocation() const
{
  return (this->_contentLocation);
}

const std::string&	HttpRequest::getContentMd5() const
{
  return (this->_contentMd5);
}

const std::string&	HttpRequest::getContentRange() const
{
  return (this->_contentRange);
}

const HttpRequest::listType&	HttpRequest::getContentType() const
{
  return (this->_contentType);
}

const std::string&	HttpRequest::getExpires() const
{
  return (this->_expires);
}

const std::string&	HttpRequest::getLastModified() const
{
  return (this->_lastModified);
}

void	HttpRequest::setMethod(const std::string& method)
{
  this->_method = method;
}

void	HttpRequest::setPath(const std::string& path)
{
  this->_path = path;
}

void	HttpRequest::addCacheControl(const std::string& key,
				     const std::string& value)
{
  this->_cacheControl[key].push_back(value);
}

void	HttpRequest::addConnection(const std::string& connection)
{
  this->_connection.push_back(connection);
}

void	HttpRequest::setDate(const std::string& date)
{
  this->_date = date;
}

void	HttpRequest::addPragma(const std::string& key,
			       const std::string& value)
{
  this->_pragma[key].push_back(value);
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

void	HttpRequest::addExpect(const std::string& key,
			       const std::string& value)
{
  this->_expect[key].push_back(value);
}

void	HttpRequest::setFrom(const std::string& from)
{
  this->_from = from;
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
