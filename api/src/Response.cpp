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

void		Response::sendResponse(ISocket*)
{
}
