#ifndef __IFLUX_H__
# define __IFLUX_H__

# include <string>
# include "IRoot.h"

namespace	ziApi
{
  //! IFlux
  class	IFlux : public IRoot
  {
  public:
    virtual ~IFlux(){}

    //! get next string
    //! \return std::string
    virtual std::string	nextString() = 0;
  };
};

#endif // !__IFLUX_H__
