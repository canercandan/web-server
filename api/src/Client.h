#ifndef __CLIENT_H__
# define __CLIENT_H__

# include "IRunnable.h"

//! Client class
class Client : public IRunnable
{
public:
  //! \param sck a ISocket pointer
  Client(ISocket* sck);
  //! run method
  void	run();
private:
  ISocket*	_sck;
};

#endif // !__CLIENT_H__
