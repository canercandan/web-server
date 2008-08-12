//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:10 2008 morgan armand
// Last update Tue Aug 12 15:58:03 2008 caner candan
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <list>

class	HttpRequest
{
  typedef std::list<std::string>	listString;

  class	VersionProtocol;
  class	Host;
  class	HttpUrl;
  class	Key;
  class	Type;
  class	Warning;

  typedef std::list<Key>		listKey;
  typedef std::list<VersionProtocol>	listVP;
  typedef std::list<Type>		listType;
  typedef std::list<Warning>		listWarning;

  class	VersionProtocol
  {
  public:
    const std::string&	getName() const
    {return (this->_name);}
    const int&		getMajor() const
    {return (this->_major);}
    const int&		getMinor() const
    {return (this->_minor);}
    const std::string&	getOtherVersion() const
    {return (this->_otherVersion);}

    void	setName(const std::string& name)
    {this->_name = name;}
    void	setMajor(const int& major)
    {this->_major = major;}
    void	setMinor(const int& minor)
    {this->_minor = minor;}
    void	setOtherVersion(const std::string& otherVersion)
    {this->_otherVersion = otherVersion;}
  private:
    std::string	_name;
    int		_major;
    int		_minor;
    std::string	_otherVersion;
  };

  class	Host
  {
  public:
    const std::string&	getHost() const
    {return (this->_host);}
    const int&		getPort() const
    {return (this->_port);}

    void	setHost(const std::string& host)
    {this->_host = host;}
    void	setPort(const int& port)
    {this->_port = port;}
  private:
    std::string	_host;
    int		_port;
  };

  class	HttpUrl
  {
  public:
    Host&		getHost()
    {return (this->_host);}
    const std::string&	getAbsPath() const
    {return (this->_absPath);}
    const std::string&	getQuery() const
    {return (this->_query);}

    void	setAbsPath(const std::string& absPath)
    {this->_absPath = absPath;}
    void	setQuery(const std::string& query)
    {this->_query = query;}
  private:
    Host	_host;
    std::string	_absPath;
    std::string	_query;
  };

  class	Key
  {
  public:
    const std::string&	getKey() const
    {return (this->_key);}
    const listString&	getValues() const
    {return (this->_values);}

    void	setKey(const std::string& key)
    {this->_key = key;}
    void	setValues(const std::string& value)
    {this->_values.push_back(value);}
  private:
    std::string	_key;
    listString	_values;
  };

  class	Type
  {
  public:
    const std::string&	getMajor() const
    {return (this->_major);}
    const std::string&	getMinor() const
    {return (this->_minor);}
    const listKey&	getParam() const
    {return (this->_param);}

    void	setMajor(const std::string& major)
    {this->_major = major;}
    void	setMinor(const std::string& minor)
    {this->_minor = minor;}
    void	setParam(const Key& key)
    {this->_param.push_back(key);}
  private:
    std::string	_major;
    std::string	_minor;
    listKey	_param;
  };

  class	Warning
  {
    const std::string&	getCode() const
    {return (this->_code);}
    const std::string&	getAgent() const
    {return (this->_agent);}
    const std::string&	getText() const
    {return (this->_text);}
    const std::string&	getDate() const
    {return (this->_date);}

    void	setCode(const std::string& code)
    {this->_code = code;}
    void	setAgent(const std::string& agent)
    {this->_agent = agent;}
    void	setText(const std::string& text)
    {this->_text = text;}
    void	setDate(const std::string& date)
    {this->_date = date;}
  private:
    std::string	_code;
    std::string	_agent;
    std::string	_text;
    std::string	_date;
  };
public:
  HttpRequest();

  const std::string&	getMethod() const
  {return (this->_method);}
  HttpUrl&		getHttpUrl()
  {return (this->_httpUrl);}
  VersionProtocol&	getVersionProtocol()
  {return (this->_versionProtocol);}
  const std::string&	getPath() const
  {return (this->_path);}

  void		setMethod(const std::string& method)
  {this->_method = method;}
  void		setPath(const std::string& path)
  {this->_path = path;}
private:
  // Request-Line Section 5.1
  std::string		_method;		// 5.1.1
  HttpUrl		_httpUrl;		// 5.1.2
  VersionProtocol	_versionProtocol;	// 3.1
  std::string		_path;

  // General Header Section 4.5
  listKey	_cacheControl;			// 14.9
  listString	_connection;			// 14.10
  std::string	_date;				// 14.18
  listKey	_pragma;			// 14.32
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
  listKey	_expect;			// 14.20
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
