#ifndef __IREQUEST_H__
# define __IREQUEST_H__

# include "IRoot.h"
# include "IModule.h"

namespace	ZapII
{
  //! IRequest
  class	IRequest : public IRoot
  {
  public:
    virtual ~IRequest(){}

    //! undef
    virtual void	accept(IModule* module) = 0;
  };
};

#endif // !__IREQUEST_H__
