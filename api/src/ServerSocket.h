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
    bool		create();
    //! undef
    ISocket*	accept();
    //! undef
    void		close();
  private:
    ISocket*	_sck;
  };
};

#endif // !__SERVERSOCKET_H__
