#ifndef __RESPONSE_H__
# define __RESPONSE_H__

# include <string>
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
    IRequest*	getRequest() const;
    //! undef
    void	buildResponse();
    //! undef
    void	sendResponse(ISocket* sck);
    //! undef
    void	appendBuf(const std::string&);
    //! undef
    void	prependBuf(const std::string&);
  private:
    IRequest*	_request;
    std::string	_buf;
  };
};

#endif // !__RESPONSE_H__
