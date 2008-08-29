#include "Request.h"

using namespace ziApi;

Request::Request()
{}

IModule::State	Request::accept(const IModule::Event& event,
				IModule* module)
{
  return (module->affect(event, this));
}
