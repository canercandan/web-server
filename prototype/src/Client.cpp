//
// Client.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:39:53 2008 morgan armand
// Last update Tue Aug 12 14:55:44 2008 majdi toumi
//

#include <iostream>
#include "Client.h"
#include "HttpParser.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpProducer.h"

Client::Client(Socket* sck, const ZiaConfiguration& conf)
  : _sck(sck), _conf(conf)
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
      HttpResponse response = HttpResponse(*request, this->_conf);
      response.sendResponse(this->_sck);
    }
  else
    {
      std::cout << "Invalid request" << std::endl;
    }

  delete request;
  delete parser;
  delete producer;
}
