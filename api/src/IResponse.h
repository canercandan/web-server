#ifndef __IRESPONSE_H__
# define __IRESPONSE_H__

# include "IRoot.h"
# include "IModule.h"
# include "ISocket.h"

namespace	ziApi
{
  class	IModule;

  //! IResponse
  class	IResponse : public IRoot
  {
  public:
    virtual ~IResponse(){}

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       IModule* module) = 0;
    //! undef
    virtual void	sendResponse(ISocket* sck) = 0;
  };
};

#endif // !__IRESPONSE_H__
