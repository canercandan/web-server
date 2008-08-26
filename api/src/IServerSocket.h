#ifndef __SERVERSOCKET_H__
# define __SERVERSOCKET_H__

# include "ISocket.h"

//! ServerSocket
class	ServerSocket : public ISocket
{
public:
  ServerSocket();

  bool		create();
  ISocket*	accept();
  void		close();
private:
  ISocket*	_sck;
};

#endif // !__SERVERSOCKET_H__
