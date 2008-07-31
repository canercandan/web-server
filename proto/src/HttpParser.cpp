//
// HttpParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:28:00 2008 morgan armand
// Last update Wed Jul 30 19:56:58 2008 morgan armand
//

#include <iostream>
#include "HttpParser.h"
#include "HttpRequest.h"

HttpParser::HttpParser(HttpProducer& prod)
  : HttpConsumer(prod)
{
}

void	HttpParser::run()
{
  this->readHttpRequest();
}

bool	HttpParser::readHttpRequest(/*HttpRequest& req*/)
{
  return (true);
}
