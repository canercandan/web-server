#ifndef __IREQUEST_H__
# define __IREQUEST_H__

# include "IRoot.h"
# include "IModule.h"

namespace	ziApi
{
  class	IModule;

  //! IRequest
  class	IRequest : public IRoot
  {
  public:
    virtual ~IRequest(){}

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       IModule*) = 0;
  };
};

#endif // !__IREQUEST_H__
