//
// Client.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:39:53 2008 morgan armand
// Last update Wed Aug  6 13:52:27 2008 caner candan
//

#include "Client.h"

Client::Client(Socket* sck)
  : _sck(sck)
{
}

void	Client::run()
{
  //this->_request = new HttpRequest();
  this->_producer = new HttpProducer(this->_sck);
  this->_consumer = new HttpParser(this->_producer);

  Parser::Http::run(this->_consumer);

  delete this->_request;
  delete this->_producer;
  delete this->_consumer;
}
