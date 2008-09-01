#ifndef __IRESPONSE_H__
# define __IRESPONSE_H__

# include "ITransition.h"
# include "ISocket.h"

namespace	ziApi
{
  class	IModule;

  //! IResponse
  class	IResponse : public ITransition
  {
  public:
    virtual ~IResponse(){}

    //! undef
    virtual IModule::State	accept(const IModule::Event&,
				       IModule* module) = 0;
    //! undef
    virtual IRequest*	getRequest() const = 0;
    //! undef
    virtual void	buildResponse() = 0;
    //! undef
    virtual void	sendResponse(ISocket* sck) = 0;
    //! undef
    virtual void	appendBuf(const std::string&) = 0;
    //! undef
    virtual void	prependBuf(const std::string&) = 0;
  };
};

#endif // !__IRESPONSE_H__
