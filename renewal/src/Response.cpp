#include "Response.h"

void		Response::statusCode(int code)
{
  this->_code = code;
}

std::string&	Response::statusCode()
{
  std::sstream	ss;

  ss << this->_code;
  return (ss.str());
}

void		Response::statusMessage(const std::string& message)
{
  this->_status = message;
}

std::string	Response::statusMessage()
{
  return (this->_status);
}

std::string	Response::buildResponse()
{
}

void		Response::resetHeaders()
{
}
