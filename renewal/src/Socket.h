#ifndef __SOCKET_H__
# define __SOCKET_H__

# ifndef WIN32
typedef int	SOCKET;
# else
typedef int	socklen_t;
# endif

# ifndef WIN32
#  define INVALID_SOCKET	-1
#  define SOCKET_ERROR		-1
# endif

# ifdef WIN32
#  include <winsock2.h>
# else
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
# endif

# include <string>

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
