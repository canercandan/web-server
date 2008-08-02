//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:42 2008 morgan armand
// Last update Sat Aug  2 18:21:04 2008 florent hochwelker
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>

typedef struct	s_version
{ // HTTP-Version   = "HTTP" "/" 1*DIGIT "." 1*DIGIT
  int			major;
  int			minor;
}			t_VersionProtocol;

typedef struct	s_httpUrl
{ // http_URL = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
  std::string		host;
  int			port;
  std::string		abs_path;
  std::string		query;
}			t_HttpUrl;

typedef struct	s_acceptType
{ // [page 100] pas encore de gestion de quality et level
  std::string	typeMajor;
  std::string	typeMinor;
}		t_acceptType;

class	HttpRequest
{
private:
  std::string			_method; // [Page 35] "OPTIONS" | "GET" | ...
  t_VersionProtocol		_versionProtocol;
  t_HttpUrl			_httpUrl;
  std::string			_host;
  std::list<t_acceptType>	_acceptList;
  std::list<std::string>	_acceptCharsetList;
  std::list<std::string>	_acceptEncoding;
  std::list<std::string>	_acceptLanguage;
  std::list<std::string>	_cacheControl;
  
};

#endif // __HTTP_REQUEST_H__
