#ifndef __SERVERSOCKET_H__
# define __SERVERSOCKET_H__

# include "ISocket.h"

namespace	ziApi
{
  //! ServerSocket
  class	ServerSocket : public ISocket
  {
  public:
    //! undef
    ServerSocket();

    //! undef
    bool	create(const int& port);
    //! undef
    virtual ISocket*	accept();
    //! undef
    virtual void	close();
  private:
    Socket	_sck;
  };
};

#endif // !__SERVERSOCKET_H__
