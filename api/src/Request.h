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

    //! undef
    const std::string&	getMethod() const;
    //! undef
    void		setMethod(const std::string& method);

    //! undef
    const std::string&	getProtocol() const;
    //! undef
    void		setProtocol(const std::string& protocol);

    //! undef
    const std::string&	getUrlHost() const;
    //! undef
    void		setUrlHost(const std::string& url);

    //! undef
    int			getUrlPort() const;
    //! undef
    void		setUrlPort(const std::string& port);

    //! undef
    const std::string&	getUrlPath() const;
    //! undef
    void		setUrlPath(const std::string& url);

    //! undef
    const std::string&	getUrlQuery() const;
    //! undef
    void		setUrlQuery(const std::string& query);

    //! undef
    const std::string&	getVersionProtocol() const;
    //! undef
    void		setVersionProtocol(const std::string& version);

  private:
    std::string		_method;
    std::string		_protocol;
    std::string		_port;
    std::string		_query;
    std::string		_version;
  };
};

#endif // !__REQUEST_H__
