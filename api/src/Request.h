#ifndef __REQUEST_H__
# define __REQUEST_H__

# include "IRequest.h"
# include "IModule.h"

namespace	ZapII
{
  //! Request
  class	Request : public IRequest
  {
  public:
    //! undef
    Request();

    //! undef
    virtual void	accept(IModule* module);
  };
};

#endif // !__REQUEST_H__
