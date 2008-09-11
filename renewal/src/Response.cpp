//
// Response.cpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:44:00 2008 majdi toumi
// Last update Wed Sep 10 16:45:25 2008 majdi toumi
//

#include <sstream>
#include "Response.h"

using namespace	ZenZiAPI;

void		Response::setStatusCode(int code)
{
  std::stringstream	ss;


  ss << code;

  this->_code = ss.str();
}

const std::string&	Response::getStatusCode()
{
  return (this->_code);
}

void		Response::setStatusMessage(const std::string& message)
{
  this->_message = message;
}

const std::string&	Response::getStatusMessage()
{
  return (this->_message);
}

std::string	Response::buildResponse()
{
}

void		Response::resetHeaders()
{
}
