//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:10 2008 morgan armand
// Last update Mon Aug 11 22:45:32 2008 caner candan
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>

class	HttpRequest
{
public:
  HttpRequest();

  const std::string&	getMethod() const;
  const std::string&	getHost() const;
  const int		getPort() const;
  const std::string&	getPath() const;
  const int		getHttpMajorVersion() const;
  const int		getHttpMinorVersion() const;

  void			setMethod(const std::string& method);
  void			setHost(const std::string& host);
  void			setPort(const std::string& port);
  void			setPath(const std::string& path);
  void			setHttpMajorVersion(int major);
  void			setHttpMinorVersion(int minor);

private:
  std::string		_method;
  std::string		_host;
  int			_port;
  std::string		_path;
  int			_major;
  int			_minor;
};

#endif // !__HTTP_REQUEST_H__
