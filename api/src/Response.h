#ifndef __RESPONSE_H__
# define __RESPONSE_H__

# include "IResponse.h"
# include "IRequest.h"

namespace	ZapII
{
  //! Response
  class	Response : public IResponse
  {
  public:
    //! undef
    Response(IRequest* request);

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       IModule* module);
    //! undef
    virtual void	sendResponse(ISocket* sck);
  };
};

#endif // !__RESPONSE_H__
