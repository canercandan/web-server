//
// URI.h for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:30:59 2008 morgan armand
// Last update Fri Aug  8 19:55:10 2008 morgan armand
//

#ifndef __URI_H__
#define __URI_H__

#include <string>

class	URI
{
public:
  URI();

  void	setHost(std::string& host);
  void	setPort(int port);

  void	setPath(std::string& path);

private:
  std::string	_host;
  int		_port;

  std::string	_path;
};

#endif // __URI_H__
