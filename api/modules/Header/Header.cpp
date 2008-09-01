#include "Header.h"
#include "IConfig.h"
#include "IRequest.h"
#include "IResponse.h"

using namespace ziApi;

Header::Header(IConfig* conf)
  : _version(0.1),
    _name("Header"),
    _conf(conf)
{}

Header::State	Header::affect(const Event&, IRequest*)
{
  return (CONTINUE);
}

Header::State	Header::affect(const Event&, IResponse* response)
{
  response->prependBuf("<h1>ad banner</h1>");
  return (CONTINUE);
}

extern	"C"
{
  EXPORT IModule*	call(IConfig* conf)
  {
    return (new Header(conf));
  }

  EXPORT void		kill(Header* module)
  {
    delete module;
  }
}
