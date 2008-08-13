//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:10 2008 morgan armand
// Last update Wed Aug 13 17:38:06 2008 caner candan
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <list>
#include <map>

class	HttpRequest
{
  class	VersionProtocol;
  class	Host;
  class	HttpUrl;
  class	Type;
  class	Warning;

  typedef std::list<std::string>		listString;
  typedef std::map<std::string, listString>	mapKey;
  typedef std::list<VersionProtocol>		listVP;
  typedef std::list<Type>			listType;
  typedef std::list<Warning>			listWarning;

  class	VersionProtocol
  {
  public:
    const std::string&	getName() const;
    const int&		getMajor() const;
    const int&		getMinor() const;
    const std::string&	getOtherVersion() const;

    void	setName(const std::string& name);
    void	setMajor(const int& major);
    void	setMinor(const int& minor);
    void	setOtherVersion(const std::string& otherVersion);
  private:
    std::string	_name;
    int		_major;
    int		_minor;
    std::string	_otherVersion;
  };

  class	Host
  {
  public:
    const std::string&	getHostname() const;
    const int&		getPort() const;

    void	setHostname(const std::string& hostname);
    void	setPort(const int& port);
  private:
    std::string	_hostname;
    int		_port;
  };

  class	HttpUrl
  {
  public:
    Host&		getHost();
    const std::string&	getAbsPath() const;
    const std::string&	getQuery() const;

    void	setAbsPath(const std::string& absPath);
    void	setQuery(const std::string& query);
  private:
    Host	_host;
    std::string	_absPath;
    std::string	_query;
  };

  class	Type
  {
  public:
    const std::string&	getMajor() const;
    const std::string&	getMinor() const;
    const mapKey&	getParam() const;
    const listString&	getParam(const std::string& key);
    const std::string&	getParam(const std::string& key,
				 const int& pos);

    void	setMajor(const std::string& major);
    void	setMinor(const std::string& minor);
    void	addParam(const std::string& key,
			 const std::string& value);
  private:
    std::string	_major;
    std::string	_minor;
    mapKey	_param;
  };

  class	Warning
  {
    const std::string&	getCode() const;
    const std::string&	getAgent() const;
    const std::string&	getText() const;
    const std::string&	getDate() const;

    void	setCode(const std::string& code);
    void	setAgent(const std::string& agent);
    void	setText(const std::string& text);
    void	setDate(const std::string& date);
  private:
    std::string	_code;
    std::string	_agent;
    std::string	_text;
    std::string	_date;
  };
public:
  HttpRequest();

  const std::string&	getMethod() const;
  HttpUrl&		getHttpUrl();
  VersionProtocol&	getVersionProtocol();
  const std::string&	getPath() const;
  const mapKey&		getCacheControl() const;
  const listString&	getConnection() const;
  const std::string&	getDate() const;
  const mapKey&		getPragma() const;
  const listString&	getTrailer() const;
  const listString&	getTransferEncoding() const;
  const listVP&		getUpgrade() const;
  const listWarning&	getWarning() const;
  const listType&	getAccept() const;
  const listString&	getAcceptCharset() const;
  const listString&	getAcceptEncoding() const;
  const listString&	getAcceptLangage() const;
  const std::string&	getAuthorization() const;
  const mapKey&		getExcept() const;
  const std::string	getFrom() const;
  const Host&		getHost() const;
  const listString&	getIfMatch();
  const listString&	getAllow() const;
  const listString&	getContentEncoding() const;
  const listString&	getContentLangage() const;
  const int&		getContentLength() const;
  const std::string&	getContentLocation() const;
  const std::string&	getContentMd5() const;
  const std::string&	getContentRange() const;
  const listType&	getContentType() const;
  const std::string&	getExpires() const;
  const std::string&	getLastModified() const;

  void	setMethod(const std::string& method);
  void	setPath(const std::string& path);
  void	addCacheControl(const std::string& key,
			const std::string& value = "");
  void	addConnection(const std::string& connection);
  void	setDate(const std::string& date);
  void	addPragma(const std::string& key,
		  const std::string& value = "");
  void	addTrailer(const std::string& trailer);
  void	addTransferEncoding(const std::string& encoding);
  void	addUpgrade(const VersionProtocol& versionProtocol);
  void	addWarning(const Warning& warning);
  void	addAccept(const Type& type);
  void	addAcceptCharset(const std::string& charset);
  void	addAcceptEncoding(const std::string& encoding);
  void	addAcceptLangage(const std::string& lang);
  void	setAuthorization(const std::string& digest);
  void	addExpect(const std::string& key,
		  const std::string& value = "");
  void	setFrom(const std::string& from);
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
  std::string		_method;		// 5.1.1
  HttpUrl		_httpUrl;		// 5.1.2
  VersionProtocol	_versionProtocol;	// 3.1
  std::string		_path;

  // General Header Section 4.5
  mapKey	_cacheControl;			// 14.9
  listString	_connection;			// 14.10
  std::string	_date;				// 14.18
  mapKey	_pragma;			// 14.32
  listString	_trailer;			// 14.40
  listString	_transferEncoding;		// 14.41
  listVP	_upgrade;			// 14.42
  listWarning	_warning;			// 14.46
  
  // Request Header Section 5.3
  listType	_accept;			// 14.1
  listString	_acceptCharset;			// 14.2
  listString	_acceptEncoding;		// 14.3
  listString	_acceptLangage;			// 14.4
  std::string	_authorization;			// 14.8
  mapKey	_expect;			// 14.20
  std::string	_from;				// 14.22
  Host		_host;				// 14.23
  listString	_ifMatch;			// 14.24

  // Entity Header Fields Section 7.1
  listString	_allow;				// 14.7
  listString	_contentEncoding;		// 14.11
  listString	_contentLangage;		// 14.12
  int		_contentLength;			// 14.13
  std::string	_contentLocation;		// 14.14
  std::string	_contentMd5;			// 14.15
  std::string	_contentRange;			// 14.16
  listType	_contentType;			// 14.17
  std::string	_expires;			// 14.21
  std::string	_lastModified;			// 14.29
};

#endif // !__HTTP_REQUEST_H__
