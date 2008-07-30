//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:28:00 2008 morgan armand
// Last update Wed Jul 30 17:36:01 2008 morgan armand
//

#include <iostream>
#include "HttpParser.h"
#include "HttpRequest.h"

HttpParser::HttpParser(HttpProducer* prod)
  : _prod(prod), _buff("")
{
}

bool	HttpParser::readHttpRequest(/*HttpRequest& req*/)
{
  std::cout << "HttpParser->read: " << this->_prod->nextString()->c_str() << std::endl;
  return (true);
}
