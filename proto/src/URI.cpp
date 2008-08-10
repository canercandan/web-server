//
// URI.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:31:29 2008 morgan armand
// Last update Fri Aug  8 21:49:39 2008 morgan armand
//

#include "URI.h"

URI::URI()
  : _host(""), _port(80), _path("/")
{
}

void	URI::setHost(std::string& host)
{
  this->_host = host;
}

void	URI::setPort(int port)
{
  this->_port = port;
}

void	URI::setPath(std::string& path)
{
  this->_path = path;
}
