#ifndef __AUTOINDEX_H__
# define __AUTOINDEX_H__

# include <string>
# include "IModule.h"

namespace	ziApi
{
  class	AutoIndex : public IModule
  {
  public:
    AutoIndex();

    virtual State	affect(const Event&,
			       const IRequest&);
    virtual State	affect(const Event&,
			       const IResponse&);
  private:
    const double&	_version;
    const std::string&	_name;
  };
};

#endif // !__AUTOINDEX_H__
