//
// Client.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:39:53 2008 morgan armand
// Last update Wed Aug  6 14:44:39 2008 morgan armand
//

#include "Client.h"

Client::Client(Socket* sck)
  : _sck(sck)
{
}

void	Client::run()
{
  this->_producer = new HttpProducer(this->_sck);
  this->_consumer = new HttpParser(this->_producer);

  this->_consumer->run();

  delete this->_producer;
  delete this->_consumer;
}
