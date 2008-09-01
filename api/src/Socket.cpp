#include <iostream>
#include "Socket.h"

using namespace ziApi;

Socket::Socket()
  : _sck(INVALID_SOCKET), _sin()
{}

Socket::Socket(const SOCKET sck, const struct sockaddr_in& sin)
  : _sck(sck), _sin(sin)
{}

Socket::~Socket()
{
  this->close();
#ifdef WIN32
  WSACleanup();
#endif
}

bool	Socket::create()
{
#ifdef WIN32
  int		err;
  WSADATA	wsaData;

  if ((err = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
      std::cerr << "WSAStartup failed with error " << err << std::endl;
      return (false);
    }

  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
      std::cerr << "Could not find a useable version of winsock.dll" << std::endl;
      WSACleanup();
      return (false);
    }
#endif
  if ((this->_sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
      std::cerr << "socket() failed" << std::endl;
#ifdef WIN32
      WSACleanup();
#endif
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
#ifdef WIN32
      WSACleanup();
#endif
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
#ifdef WIN32
      WSACleanup();
#endif
      return (false);
    }
  return (true);
}

ISocket*	Socket::accept()
{
  int			opt;
  SOCKET		sck;
  struct sockaddr_in	sin;
  socklen_t		len;

  if (!this->isValid())
    return (false);

  opt = 1;
  len = sizeof(sin);

  if ((sck = ::accept(this->_sck, (struct sockaddr *)&sin, &len)) == INVALID_SOCKET)
    {
      std::cerr << "accept() failed" << std::endl;
      return (NULL);
    }

#ifndef WIN32
  if (::setsockopt(sck, SOL_SOCKET, SO_NOSIGPIPE, &opt, sizeof(opt)) == SOCKET_ERROR)
    {
      std::cerr << "accept() failed" << std::endl;
      this->close();
      return (NULL);
    }
#endif

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
    }
}

int	Socket::recv(char* buf, int len)
{
  return ::recv(this->_sck, buf, len, 0);
}

int	Socket::send(std::string& buf)
{
  int	ret;
  if ((ret = ::send(this->_sck, buf.c_str(), buf.length(), 0)) < 0)
    return (-1);
  if (ret < (signed int)buf.length())
    {
      buf = buf.substr(ret);
      return (Socket::send(buf));
    }
  return (ret);
}

bool	Socket::isValid()
{
  return (this->_sck != INVALID_SOCKET);
}
