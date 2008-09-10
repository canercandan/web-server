//
// ServerSocket.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 18:10:06 2008 caner candan
// Last update Wed Sep 10 18:10:06 2008 caner candan
//

#include <iostream>
#include "ServerSocket.h"

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
