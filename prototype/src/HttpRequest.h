//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:10 2008 morgan armand
// Last update Wed Aug 13 12:15:37 2008 caner candan
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

  void	setMethod(const std::string& method);
  void	setPath(const std::string& path);

  const mapKey&	getCacheControl() const
  {return (this->_cacheControl);}

  const listString&	getConnection() const
  {return (this->_connection);}

  const std::string&	getDate() const
  {return (this->_date);}

  const mapKey&	getPragma() const
  {return (this->_pragma);}

  const listString&	getTrailer() const
  {return (this->_trailer);}

  const listString&	getTransferEncoding() const
  {return (this->_transferEncoding);}

  const listVP&	getUpgrade() const
  {return (this->_upgrade);}

  const listWarning& getWarning() const
  {return (this->_warning);}

  const listType&	getAccept() const
  {return (this->_accept);}

  const listString&	getAcceptCharset() const
  {return (this->_acceptCharset);}

  const listString&	getAcceptEncoding() const
  {return (this->_acceptEncoding);}

  const listString&	getAcceptLangage() const
  {return (this->_acceptLangage);}

  const std::string&	getAuthorization() const
  {return (this->_authorization);}

  const mapKey&	getExcept() const
  {return (this->_expect);}

  const std::string	getFrom() const
  {return (this->_from);}

  const Host&	getHost() const
  {return (this->_host);}

  const listString&	getIfMatch()
  {return (this->_ifMatch);}

  const listString&	getAllow() const
  {return (this->_allow);}

  const listString&	getContentEncoding() const
  {return (this->_contentEncoding);}

  const listString&	getContentLangage() const
  {return (this->_contentLangage);}

  const int&	getContentLength() const
  {return (this->_contentLength);}

  const std::string&	getContentLocation() const
  {return (this->_contentLocation);}

  const std::string&	getContentMd5() const
  {return (this->_contentMd5);}

  const std::string&	getContentRange() const
  {return (this->_contentRange);}

  const listType&	getContentType() const
  {return (this->_contentType);}

  const std::string&	getExpires() const
  {return (this->_expires);}

  const std::string&	getLastModified() const
  {return (this->_lastModified);}
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
