#include "Response.h"

using namespace ziApi;

Response::Response()
{}

IModule::State	Response::accept(const IModule::Event& event,
				 IModule* module)
{
  return (module->affect(event, this));
}

void	Response::sendResponse(ISocket* sck)
{}
