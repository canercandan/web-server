#ifndef __FOOTER_H__
# define __FOOTER_H__

#include <string>
#include "IConfig.h"
#include "IModule.h"

namespace	ziApi
{
  class Footer : public IModule
  {
  public:
    Footer(IConfig* conf);

    virtual State	affect(const Event& event, IRequest* request);
    virtual State	affect(const Event& event, IResponse* response);
  private:
    const double&	_version;
    const std::string&	_name;
    IConfig*		_conf;
  };
}

#endif // !__FOOTER_H__
