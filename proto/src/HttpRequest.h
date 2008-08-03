//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:42 2008 morgan armand
// Last update Sat Aug  2 23:44:09 2008 florent hochwelker
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <list>
#include "rfcStruct.h"

class	HttpRequest
{
public:
  void	setMethod(const std::string& method);
  void	setHttpUrl(const std::string& host, int port, const std::string& abs, std::string query = "");
  void	setVersionProtocol(const std::string name, int major, int minor, const std::string otherVersion);
  void	addCacheControl(const std::string& key, const std::string& value = "");
  void	addConnection(const std::string& connection);
  void	setDate(const std::string& date);
  void	addPragma(const std::string& key, const std::string& value = "");
  void	addTrailer(const std::string& trailer);
  void	addTransferEncoding(const std::string& encoding);
  void	addUpgrade(const VersionProtocol& versionProtocol);
  void	addWarning(const Warning& warning);
  void	addAccept(const Type& type);
  void	addAcceptCharset(const std::string& charset);
  void	addAcceptEncoding(const std::string& encoding);
  void	addAcceptLangage(const std::string& lang);
  void	setAuthorization(const std::string& digest);
  void	addExpect(const std::string& key, const std::string& value = "");
  void	setFrom(const std::string& from);
  void	setHost(const std::string& host, int port);
  void	addIfMatch(const std::string& match);
  void	addAllow(const std::string& allow);
  void	addContentEncoding(const std::string& encoding);
  void	addContentLangage(const std::string& lang);
  void	setContentLength(const int length);
  void	setContentLocation(const std::string& location);
  void	setContentMd5(const std::string& base64ToMd5);
  void	setContentRange(const std::string& range);
  void	addContentType(const Type& type);
  void	setExpires(const std::string& expires);
  void	setLastModifies(const std::string& modified);

private:
  // Request-Line Section 5.1
  std::string			_method;	// 5.1.1
  HttpUrl			_httpUrl;	// 5.1.2
  VersionProtocol		_versionProtocol;	// 3.1

  // General Header Section 4.5
  std::list<Key>		_cacheControl; // 14.9
  std::list<std::string>	_connection; // 14.10
  std::string			_date;	// 14.18
  std::list<Key>		_pragma;	// 14.32
  std::list<std::string>	_trailer;	// 14.40
  std::list<std::string>	_transferEncoding; // 14.41
  std::list<VersionProtocol>	_upgrade;	// 14.42
  std::list<Warning>		_warning;	// 14.46
  
  // Request Header Section 5.3
  std::list<Type>		_accept;	// 14.1
  std::list<std::string>	_acceptCharset;	// 14.2
  std::list<std::string>	_acceptEncoding;	// 14.3
  std::list<std::string>	_acceptLangage;	// 14.4
  std::string			_authorization; // 14.8
  std::list<Key>		_expect;	// 14.20
  std::string			_from;	// 14.22
  Host				_host;	// 14.23
  std::list<std::string>	_ifMatch;	// 14.24

  // Entity Header Fields Section 7.1
  std::list<std::string>	_allow;	// 14.7
  std::list<std::string>	_contentEncoding;	// 14.11
  std::list<std::string>	_contentLangage;	// 14.12
  int				_contentLength;	// 14.13
  std::string			_contentLocation;	// 14.14
  std::string			_contentMd5;	// 14.15
  std::string			_contentRange;	// 14.16
  std::list<Type>		_contentType;	// 14.17
  std::string			_expires;	// 14.21
  std::string			_lastModified;	// 14.29
  
};

#endif // __HTTP_REQUEST_H__
