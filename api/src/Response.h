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
    Response(const IRequest& request);

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       const IModule& module);
    //! undef
    virtual void	sendResponse(const ISocket& sck);

  private:
    const IRequest&	_request;
  };
};

#endif // !__RESPONSE_H__
