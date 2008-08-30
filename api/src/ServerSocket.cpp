#include <iostream>
#include "ServerSocket.h"

ServerSocket::ServerSocket()
  : _sck()
{}

bool		ServerSocket::create(const int& port)
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
