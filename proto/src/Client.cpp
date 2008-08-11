//
// Client.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:39:53 2008 morgan armand
// Last update Mon Aug 11 12:34:11 2008 morgan armand
//

#include <iostream>
#include "Client.h"

Client::Client(Socket* sck)
  : _sck(sck)
{}

void	Client::run()
{
  HttpProducer*	producer;
  HttpParser*	parser;
  HttpRequest*	request;

  producer = new HttpProducer(this->_sck);
  request = new HttpRequest();
  parser = new HttpParser(producer, request);

  if (parser->readRequest())
    {
      std::cout << "Valid request" << std::endl;
      std::cout << "METHOD: " << request->getMethod() << std::endl;
      std::cout << "HOST: " << request->getHost() << std::endl;
      std::cout << "PORT: " << request->getPort() << std::endl;
      std::cout << "PATH: " << request->getPath() << std::endl;
    }
  else
    {
      std::cout << "Invalid request" << std::endl;
    }

  delete request;
  delete parser;
  delete producer;
}
