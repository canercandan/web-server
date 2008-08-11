//
// HttpRequest.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:10 2008 morgan armand
// Last update Mon Aug 11 11:34:04 2008 morgan armand
//

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>

class	HttpRequest
{
public:
  HttpRequest();

  const std::string&	getMethod() const;
  void			setMethod(const std::string& method);

  // URI Part. Should be move ?
  const std::string&	getHost() const;
  void			setHost(const std::string& host);

  const int		getPort() const;
  void			setPort(const int port);

  const std::string&	getPath() const;
  void			setPath(const std::string& path);

private:
  std::string		_method;
  std::string		_host;
  int			_port;
  std::string		_path;
};

#endif // !__HTTP_REQUEST_H__
