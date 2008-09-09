#ifndef _MESSAGE_H_
# define _MESSAGE_H_

# include "IMessage.h"

namespace	ZenZiAPI
{
  class		Message : public IMessage
  {
  public:
    Message(IRequest& request, IResponse& response);

    IRequest&	request();
    IResponse&	response();

  private:
    IRequest&	_request;
    IResponse&	_response;
  };
}

#endif // _MESSAGE_H_
