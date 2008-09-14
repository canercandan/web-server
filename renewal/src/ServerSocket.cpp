//
// ServerSocket.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 18:10:06 2008 caner candan
// Last update Sun Sep 14 14:28:02 2008 caner candan
//

#include <iostream>
#include "ServerSocket.h"
#include "Signal.h"

ServerSocket::ServerSocket()
{
  Signal*	signal = Signal::getInstance();

  signal->addCallback(Signal::INT, this,
		      static_cast<ISignalManager::callback>
		      (&ServerSocket::signal));
}

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

void	ServerSocket::signal()
{
  std::cout << "serversocket close()" << std::endl;
  this->close();
}
