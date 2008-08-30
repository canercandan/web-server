#include "Response.h"

using namespace ziApi;

IModule::Response(IRequest* request)
  : _request(request)
{}

IModule::State	Response::accept(const IModule::Event& event,
				 const IModule& module)
{
  return (module->affect(event, this));
}

void	Response::sendResponse(const ISocket& sck)
{}
