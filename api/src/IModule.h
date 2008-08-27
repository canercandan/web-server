#ifndef __IMODULE_H__
# define __IMODULE_H__

# include "IRoot.h"
# include "IRequest.h"
# include "IResponse.h"

//! IModule
class	IModule : public IRoot
{
public:
  virtual ~IModule(){}

  //! undef
  virtual void	affect(IRequest* request) = 0;
  //! undef
  virtual void	affect(IResponse* response) = 0;
};

#endif // !__IMODULE_H__
