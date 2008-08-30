#ifndef __FLUXCLIENT_H__
# define __FLUXCLIENT_H__

# include "IFlux.h"
# include "Socket.h"

namespace	ziApi
{
  //! FluxClient
  class	FluxClient : public IFlux
  {
  public:
    //! undef
    //! \param sck an ISocket pointer
    FluxClient(Socket* sck);
    ~FluxClient();

    //! get the next string
    //! \return std::string
    virtual std::string	nextString();
  private:
    Socket*	_sck;
  };
};

#endif // !__FLUXCLIENT_H__
