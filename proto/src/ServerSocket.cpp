//
// ServerSocket.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 10:35:03 2008 morgan armand
// Last update Wed Jul 30 12:24:42 2008 morgan armand
//

#include <iostream>
#include "ServerSocket.h"

ServerSocket::ServerSocket()
  : _sck()
{
}

bool		ServerSocket::create(int port)
{
  if (!this->_sck.create())
    return (false);

  if (!this->_sck.bind(port))
    return (false);

  if (!this->_sck.listen(42))
    return (false);

  return (true);
}

Socket*		ServerSocket::accept()
{
  return (this->_sck.accept());
}

void		ServerSocket::close()
{
  this->_sck.close();
}
