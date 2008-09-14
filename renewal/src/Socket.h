//
// Socket.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:22:38 2008 caner candan
// Last update Sat Sep 13 22:22:38 2008 caner candan
//

#ifndef __SOCKET_H__
# define __SOCKET_H__

# ifdef WIN32
typedef int	socklen_t;
# endif

# ifndef WIN32
#  define INVALID_SOCKET	-1
#  define SOCKET_ERROR		-1
# endif

# ifndef WIN32
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
# endif

# include <string>
# include "defines.hpp"

class Socket
{
public:
  Socket();
  Socket(const SOCKET sck, const struct sockaddr_in& sin);
  ~Socket();

  bool		create();
  bool		bind(const int port);
  bool		listen(const int backlog);
  Socket*	accept();
  void		close();
  int		recv(char* buf, int len);
  int		send(std::string& buf);
  bool		isValid();
  SOCKET	getSocket();
private:
  SOCKET		_sck;
  struct sockaddr_in	_sin;
};

#endif // !__SOCKET_H__
