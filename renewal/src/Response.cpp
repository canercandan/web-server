#include "Response.h"

void		Response::setStatusCode(int code)
{
  this->_code = code;
}

std::string&	Response::getStatusCode()
{
  std::sstream	ss;

  ss << this->_code;
  return (ss.str());
}

void		Response::setStatusMessage(const std::string& message)
{
  this->_status = message;
}

std::string	Response::getStatusMessage()
{
  return (this->_status);
}

std::string	Response::buildResponse()
{
}

void		Response::resetHeaders()
{
}
