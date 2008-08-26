#ifndef __REQUEST_H__
# define __REQUEST_H__

# include "IRequest.h"
# include "IModule.h"

//! Request
class	Request : public IRequest
{
public:
  Request();

  virtual void	accept(IModule* module);
};

#endif // !__REQUEST_H__
