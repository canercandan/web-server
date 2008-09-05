#include "Footer.h"
#include "IConfig.h"
#include "IRequest.h"
#include "IResponse.h"

using namespace ziApi;

Footer::Footer(IConfig* conf)
  : _version(0.1),
    _name("Footer"),
    _conf(conf)
{}

Footer::State	Footer::affect(const Event&, IRequest*)
{
  return (CONTINUE);
}

Footer::State	Footer::affect(const Event& event, IResponse* response)
{
  if (event == POST)
    {
      response->appendBuf("\nFooter Module (c) All right reserved.");
    }
  return (CONTINUE);
}

extern	"C"
{
  EXPORT IModule*	call(IConfig* conf)
  {
    return (new Footer(conf));
  }

  EXPORT void		kill(Footer* module)
  {
    delete module;
  }
}
