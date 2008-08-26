#ifndef __RESPONSE_H__
# define __RESPONSE_H__

# include "IResponse.h"
# include "IRequest.h"
# include "ISocket.h"

//! Response
class	Response : public IResponse
{
public:
  Response(IRequest* request);

  virtual void accept(IModule* module);
  virtual void sendResponse(ISocket* sck);
};

#endif // !__RESPONSE_H__
