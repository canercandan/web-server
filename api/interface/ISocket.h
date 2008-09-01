#ifndef __ISOCKET_H__
# define __ISOCKET_H__

# include "IRoot.h"

namespace	ziApi
{
  //! ISocket
  class	ISocket : public IRoot
  {
  public:
    virtual ~ISocket() {};

    //! undef
    virtual ISocket*	accept() = 0;
    //! undef
    virtual void	close() = 0;
  };
};

#endif // !__ISOCKET_H__
