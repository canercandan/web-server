#ifndef __FLUXCLIENT_H__
# define __FLUXCLIENT_H__

# include "IFlux.h"
# include "ISocket.h"

//! FluxClient
class FluxClient : IFlux
{
public:
  //! \param sck an ISocket pointer
  FluxClient(ISocket* sck);

  //! get the next string
  //! \return std::string
  std::string	nextString();
private:
  ISocket*	_sck;
};

#endif // !__FLUXCLIENT_H__
