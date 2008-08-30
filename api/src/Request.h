#ifndef __REQUEST_H__
# define __REQUEST_H__

# include "IRequest.h"

namespace	ziApi
{
  //! Request
  class	Request : public IRequest
  {
  public:
    //! undef
    Request();

    //! undef
    IModule::State	accept(const IModule::Event& event,
			       IModule* module);

  private:
    std::string		_method;
    std::string		_protocol;
    std::string		_port;
    std::string		_query;
    std::string		_version;
  };
};

#endif // !__REQUEST_H__
