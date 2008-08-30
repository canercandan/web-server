#include "AutoIndex.h"

using namespace ziApi;

AutoIndex::AutoIndex()
  : _version(0.1),
    _name("AutoIndex")
{}

AutoIndex::State	AutoIndex::affect(const Event&,
					  const IRequest&)
{
  return (CONTINUE);
}

AutoIndex::State	AutoIndex::affect(const Event& event,
					  const IResponse&)
{
  if (event != PRE)
    return (CONTINUE);
  // todo: listing directory
  return (BREAK);
}

extern "C"
{
  EXPORT IModule*	call()
  {
    return (new AutoIndex);
  }

  EXPORT void	kill(AutoIndex* module)
  {
    delete module;
  }
}
