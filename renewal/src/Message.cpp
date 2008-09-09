#include "Message.h"

Message::Message(IRequest& request, IResponse& response)
  : _request(request), _response(response)
{
}

IRequest&	Message::request()
{
  return (this->_request);
}

IResponse&	Message::response()
{
  return (this->_response);
}
