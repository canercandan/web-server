#ifndef __IFLUX_H__
# define __IFLUX_H__

# include "IServer.h"

//! IFlux
class IFlux : public IServer
{
public:
  virtual ~IFlux(){}

  //! get next string
  //! \return std::string
  virtual std::string	nextString() = 0;
};

#endif // !__IFLUX_H__
