#ifndef __SERVERSOCKET_H__
# define __SERVERSOCKET_H__

# include "Socket.h"

namespace	ziApi
{
  //! ServerSocket
  class	ServerSocket
  {
  public:
    //! undef
    ServerSocket();

    //! undef
    bool	create(const int& port);
    //! undef
    ISocket*	accept();
    //! undef
    void	close();
  private:
    Socket	_sck;
  };
};

#endif // !__SERVERSOCKET_H__
