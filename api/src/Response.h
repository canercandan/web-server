#ifndef __RESPONSE_H__
# define __RESPONSE_H__

# include "IResponse.h"
# include "IRequest.h"

namespace	ziApi
{
  //! Response
  class	Response : public IResponse
  {
  public:
    //! undef
    Response(IRequest* request);

    //! undef
    IModule::State	accept(const IModule::Event&,
			       IModule* module);

    //! undef
    IRequest*		getRequest() const;

    //! undef
    void		sendResponse(ISocket* sck);

  private:
    IRequest*	_request;
  };
};

#endif // !__RESPONSE_H__
