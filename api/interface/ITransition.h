#ifndef __ITRANSITION_H__
# define __ITRANSITION_H__

# include "IRoot.h"
# include "IModule.h"

namespace	ziApi
{
  //! ITransition
  class	ITransition : public IRoot
  {
  public:
    virtual ~ITransition(){}

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       IModule*) = 0;
  };
};

#endif // !__ITRANSITION_H__
