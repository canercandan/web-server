#ifndef __IRESPONSE_H__
# define __IRESPONSE_H__

# include "IModule.h"
# include "ISocket.h"

//! IResponse
class IResponse
{
public:
  virtual ~IResponse(){}

  //! undef
  virtual void	accept(IModule* module) = 0;
  //! undef
  virtual void	sendResponse(ISocket* sck) = 0;
};

#endif // !__IRESPONSE_H__
