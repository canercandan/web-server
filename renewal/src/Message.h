#ifndef _MESSAGE_H_
# define _MESSAGE_H_

# include "IMessage.hpp"

# include "Request.h"
# include "Response.h"

namespace	ZenZiAPI
{
  class		Message : public IMessage
  {
  public:
    IRequest&	request();
    IResponse&	response();

  private:
    Request	_request;
    Response	_response;
  };
}

#endif // _MESSAGE_H_
