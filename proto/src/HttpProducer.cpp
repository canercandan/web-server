//
// HttpProducer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:13:12 2008 morgan armand
// Last update Sat Aug  2 19:28:25 2008 florent hochwelker
//

#include "HttpProducer.h"

HttpProducer::HttpProducer(Socket* sck)
  : _sck(sck)
{
}

HttpProducer::~HttpProducer()
{
  if (_sck)
    _sck->close();
}

std::string	HttpProducer::nextString(void)
{
  char		buf[128] = {0};
  int		cc;

  if (!(cc = this->_sck->recv(buf, sizeof(buf) - 1)))
    return (std::string(""));
  buf[cc] = 0; // useless
  return (std::string(buf));
}
