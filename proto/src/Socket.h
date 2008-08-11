//
// Socket.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 11:39:49 2008 morgan armand
// Last update Mon Aug 11 21:29:18 2008 morgan armand
//

#ifndef __SOCKET_H__
#define __SOCKET_H__

#ifndef WIN32
typedef int	SOCKET;
#else
typedef int	socklen_t;
#endif

#ifndef WIN32
# define INVALID_SOCKET	-1
# define SOCKET_ERROR	-1
#endif

#ifdef WIN32
# include <winsock2.h>
#else
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
#endif

class	Socket
{
public:
  // Default ctor/dtor
  Socket();
  ~Socket();

  // Construct a Socket object from a existing SOCKET/sockaddr_in pair.
  Socket(const SOCKET sck, const struct sockaddr_in& sin);

  // Create a new TCP socket
  bool		create();

  // Bind the socket to the specified port
  bool		bind(const int port);

  // Listen with the specified backlog
  bool		listen(const int backlog);

  // Accept a new connection from the socket
  Socket*	accept();

  // Close the socket
  void		close();

  // Classic read / write operations
  int		recv(const char* buf, int len);
  int		send(const char* buf, int len);

  // Tell if the current socket is valid or not.
  bool		isValid();

private:
  SOCKET		_sck;
  struct sockaddr_in	_sin;
};

#endif // __SOCKET_H__
