#ifndef __SOCKET_H__
# define __SOCKET_H__

# include "ISocket.h"

//! Socket
class Socket : public ISocket
{
public:
  Socket();

  //! undef
  virtual bool		create();
  //! undef
  bool			bind();
  //! undef
  bool			listen();
  //! undef
  virtual ISocket*	accept();
  //! undef
  virtual void		close();
  //! undef
  int			recv();
  //! undef
  int			send();
  //! undef
  bool			isValid();
private:
  struct sockaddr_in	sin;
};

#endif // !__SOCKET_H__
