//
// Client.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:39:53 2008 morgan armand
// Last update Fri Aug  8 11:00:54 2008 caner candan
//

#include "Client.h"

Client::Client(Socket* sck)
  : _sck(sck)
{}

void	Client::run()
{
  HttpProducer*	producer;
  HttpParser*	consumer;
  HttpRequest*	request;

  producer = new HttpProducer(this->_sck);
  request = new HttpRequest;
  consumer = new HttpParser(producer, request);
  consumer->run();
  delete producer;
  delete request;
  delete consumer;
}
