#ifndef __HEADER_H__
# define __HEADER_H__

#include <string>
#include "IConfig.h"
#include "IModule.h"

namespace	ziApi
{
  class Header : public IModule
  {
  public:
    Header(IConfig* conf);

    virtual State	affect(const Event& event, IRequest* request);
    virtual State	affect(const Event& event, IResponse* response);
  private:
    const double&	_version;
    const std::string&	_name;
    IConfig*		_conf;
  };
}

#endif // !__HEADER_H__
