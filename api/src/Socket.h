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
    virtual bool	create();
    //! undef
    bool		bind();
    //! undef
    bool		listen();
    //! undef
    virtual ISocket*	accept();
    //! undef
    virtual void	close();
    //! undef
    int			recv();
    //! undef
    int			send();
    //! undef
    bool		isValid();
  private:
    struct sockaddr_in	sin;
  };
};

#endif // !__SOCKET_H__
