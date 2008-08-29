#include "Request.h"

using namespace ZapII;

Request::Request()
{}

IModule::State	Request::accept(const IModule::Event& event,
				IModule* module)
{
  return (module->affect(event, this));
}
