//
// HttpProducer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:13:12 2008 morgan armand
// Last update Wed Jul 30 17:37:59 2008 morgan armand
//

#include "HttpProducer.h"

HttpProducer::HttpProducer(Socket* sck)
  : _sck(sck)
{
}

std::string*	HttpProducer::nextString()
{
  char		buf[16];

  bzero(buf, 16);

  if (this->_sck->recv(buf, 15) == 0)
    return (NULL);

  return (new std::string(buf));
}
