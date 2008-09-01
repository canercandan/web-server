#include "Response.h"

using namespace ziApi;

Response::Response(IRequest* request)
  : _request(request)
{}

IModule::State	Response::accept(const IModule::Event& event,
				 IModule* module)
{
  return (module->affect(event, this));
}

IRequest*	Response::getRequest() const
{
  return (this->_request);
}

void	Response::buildResponse()
{}

void	Response::sendResponse(ISocket*)
{}

void	Response::appendBuf(const std::string& s)
{
  this->_buf.append(s);
}

void	Response::prependBuf(const std::string& s)
{
  this->_buf = s + this->_buf;
}
