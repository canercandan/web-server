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

    //! undef
    virtual const std::string&	getMethod() const = 0;
    //! undef
    virtual void		setMethod(const std::string& method) = 0;

    //! undef
    virtual const std::string&	getProtocol() const = 0;
    //! undef
    virtual void		setProtocol(const std::string& protocol) = 0;

    //! undef
    virtual const std::string&	getUrlHost() const = 0;
    //! undef
    virtual void		setUrlHost(const std::string& url) = 0;

    //! undef
    virtual int			getUrlPort() const = 0;
    //! undef
    virtual void		setUrlPort(const std::string& port) = 0;

    //! undef
    virtual const std::string&	getUrlPath() const = 0;
    //! undef
    virtual void		setUrlPath(const std::string& url) = 0;

    //! undef
    virtual const std::string&	getUrlQuery() const = 0;
    //! undef
    virtual void		setUrlQuery(const std::string& query) = 0;

    //! undef
    virtual const std::string&	getVersionProtocol() const = 0;
    //! undef
    virtual void		setVersionProtocol(const std::string& version) = 0;
  };
};

#endif // !__IREQUEST_H__
