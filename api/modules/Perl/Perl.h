#ifndef __PERL_H__
# define __PERL_H__

#include <string>
#include "IModule.h"

namespace	ziApi
{
  class Perl : public IModule
  {
  public:
    Perl();

    virtual State	affect(const Event& event, IRequest* request);
    virtual State	affect(const Event& event, IResponse* response);
  private:
    const double&	_version;
    const std::string&	_name;
  };
}

#endif // !__PERL_H__
