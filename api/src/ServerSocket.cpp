#include <iostream>
#include "ServerSocket.h"

using namespace ziApi;

ServerSocket::ServerSocket()
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

ISocket*	ServerSocket::accept()
{
  return (this->_sck.accept());
}

void		ServerSocket::close()
{
  this->_sck.close();
}
