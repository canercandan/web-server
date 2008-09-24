//
// Socket.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:22:33 2008 caner candan
// Last update Tue Sep 23 16:12:23 2008 majdi toumi
//

#include <iostream>
#include "Socket.h"
#include "Signal.h"

Socket::Socket()
  : _sck(INVALID_SOCKET), _sin()
{
  _setSignal();
}

Socket::Socket(const SOCKET sck,
	       const struct sockaddr_in& sin)
  : _sck(sck), _sin(sin)
{
  _setSignal();
}

Socket::~Socket()
{
  this->close();
}

void	Socket::_setSignal()
{
  Signal*	signal = Signal::getInstance();

  signal->addCallback(Signal::INT, this,
		      static_cast<ISignalManager::callback>
		      (&Socket::signal));
}

bool	Socket::create()
{
  if ((this->_sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
      std::cerr << "socket() failed" << std::endl;
      return (false);
    }
  return (true);
}

bool	Socket::bind(const int port)
{
  if (!this->isValid())
    return (false);

  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(port);
  this->_sin.sin_addr.s_addr = INADDR_ANY;

  if (::bind(this->_sck, (struct sockaddr *)&this->_sin, sizeof(this->_sin)) == SOCKET_ERROR)
    {
      std::cerr << "bind() failed" << std::endl;
      return (false);
    }
  return (true);
}

bool	Socket::listen(const int backlog)
{
  if (!this->isValid())
    return (false);

  if (::listen(this->_sck, backlog) == SOCKET_ERROR)
    {
      std::cerr << "listen() failed" << std::endl;
      return (false);
    }
  return (true);
}

Socket*		Socket::accept()
{
  int			optname;
  int			optval;
  SOCKET		sck;
  struct sockaddr_in	sin;
  struct linger linger;
  socklen_t		len;

  if (!this->isValid())
    return (false);

  optval = 1;
  len = sizeof(sin);

  if ((sck = ::accept(this->_sck, (struct sockaddr *)&sin, &len)) == INVALID_SOCKET)
    {
      std::cerr << "accept() failed" << std::endl;
      return (NULL);
    }

  optname = -1;
#ifndef WIN32
# if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
  optname = SO_NOSIGPIPE;
# else
  optname = MSG_NOSIGNAL;
# endif
  if (::setsockopt(sck, SOL_SOCKET, optname, &optval, sizeof(optval)) == SOCKET_ERROR)
    {
      std::cerr << "accept() failed" << std::endl;
      this->close();
      return (NULL);
    }
#endif
  linger.l_onoff = 1;
  linger.l_linger = 1;

  if (::setsockopt(sck, SOL_SOCKET, SO_LINGER, (char *)&linger, sizeof(linger)) == SOCKET_ERROR)
  {
	  std::cerr << "setsockopt() failed" << std::endl;
	  this->close();
	  return (NULL);
  }
  return (new Socket(sck, sin));
}

void	Socket::close()
{
  if (this->isValid())
    {
#ifdef WIN32
      ::closesocket(this->_sck);
#else
      ::close(this->_sck);
#endif
      this->_sck = INVALID_SOCKET;
    }
}

int	Socket::recv(char* buf, int len)
{
  return ::recv(this->_sck, buf, len, 0);
}

int	Socket::send(char* buf, int len)
{
  return ::send(this->_sck, buf, len, 0);
}

bool	Socket::isValid()
{
  return (this->_sck != INVALID_SOCKET);
}

SOCKET	Socket::getSocket()
{
  return (this->_sck);
}

void	Socket::signal()
{
  this->close();
}
