#ifndef __REQUEST_H__
# define __REQUEST_H__

# include "IRequest.h"

namespace	ZapII
{
  //! Request
  class	Request : public IRequest
  {
  public:
    //! undef
    Request();

    //! undef
    virtual IModule::State	accept(const IModule::Event& event,
				       IModule* module);
  };
};

#endif // !__REQUEST_H__
