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
# include "ISocket.h"

namespace	ziApi
{
  //! Socket
  class Socket : public ISocket
  {
  public:
    //! undef
    Socket();
    Socket(const SOCKET sck, const struct sockaddr_in& sin);
    ~Socket();

    //! undef
    bool	create();
    //! undef
    bool	bind(const int port);
    //! undef
    bool	listen(const int backlog);
    //! undef
    Socket*	accept();
    //! undef
    void	close();
    //! undef
    int		recv(char* buf, int len);
    //! undef
    int		send(std::string& buf);
    //! undef
    bool	isValid();
  private:
    SOCKET		_sck;
    struct sockaddr_in	_sin;
  };
};

#endif // !__SOCKET_H__
