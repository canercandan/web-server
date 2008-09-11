#include "Message.h"

using namespace ZenZiAPI;

IRequest&	Message::request()
{
  return (this->_request);
}

IResponse&	Message::response()
{
  return (this->_response);
}
