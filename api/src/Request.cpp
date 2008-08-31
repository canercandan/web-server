#include "Request.h"

using namespace ziApi;

Request::Request()
{}

IModule::State		Request::accept(const IModule::Event& event,
					IModule* module)
{
  return (module->affect(event, this));
}

const std::string&	Request::getMethod() const
{
  return (this->_method);
}

void			Request::setMethod(const std::string& method)
{
  this->_method = method;
}

const std::string&	Request::getProtocol() const
{
  return (this->_protocol);
}

void			Request::setProtocol(const std::string& protocol)
{
  this->_protocol = protocol;
}

const std::string&	Request::getUrlHost() const
{
  return (this->_host);
}

void			Request::setUrlHost(const std::string& host)
{
  this->_host = host;
}

const std::string&	Request::getUrlPort() const
{
  return (this->_port);
}

void			Request::setUrlPort(const std::string& port)
{
  this->_port = port;
}

const std::string&	Request::getUrlPath() const
{
  return (this->_path);
}

void			Request::setUrlPath(const std::string& path)
{
  this->_path = path;
}

const std::string&	Request::getUrlQuery() const
{
  return (this->_query);
}

void			Request::setUrlQuery(const std::string& query)
{
  this->_query = query;
}


const std::string&	Request::getVersionProtocol() const
{
  return (this->_version);
}

void			Request::setVersionProtocol(const std::string& version)
{
  this->_version = version;
}
