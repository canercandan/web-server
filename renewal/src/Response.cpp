//
// Response.cpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:44:00 2008 majdi toumi
// Last update Sat Sep 13 15:02:07 2008 caner candan
//

#include <sstream>
#include <iostream>
#include "Response.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"

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
  std::cout << "URI: " << this->getUri() << std::endl;

  FluxString	flux(this->getUri());
  Consumer	consumer(flux);
  URIParser	uri(consumer);

  uri.run();
  std::cout << "URIPath: " << uri.getPath() << std::endl;
  return ("pouet.net");
}

void		Response::resetHeaders()
{
}
